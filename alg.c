#include "alg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapimg.h"
#include <stdarg.h>
#include "queue.h"

// common
static int IndexOf(AlGraph *g, AlVertex v)
{
    for(int i = 0; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ )
    {
        if( (*g)[i].data == v.data )
            return i;
    }
    return -1;
}
static int SizeOf(AlGraph *g)
{
    int i = MAX_VERTEX_NUM;
    for(; i > 0 && (*g)[i-1].data == '\0'; i-- );
    return i ;
}

void InitAlGraph(AlGraph *g)
{
    FOR(i, MAX_VERTEX_NUM)
    {
        (*g)[i].data = '\0';
        (*g)[i].edge = NULL;
    } 
}

// clean graph
static void ReleaseAlGraphEdge(AlEdge *edge)
{
    if(edge != NULL)
    {
        ReleaseAlGraphEdge(edge->next);
        free(edge);
    }
}
void CleanAlGraph(AlGraph *g)
{
    for(int i = 0; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ )
    {
        (*g)[i].data = '\0';
        ReleaseAlGraphEdge((*g)[i].edge);
        (*g)[i].edge = NULL;
    } 
}

// add vertex
void AddAlGraphVertexs(AlGraph *g, ...)
{
    va_list p;
    va_start(p, g);

    for(AlVertexElm ver = (AlVertexElm)va_arg(p, int); ver != '\0'; 
        ver = (AlVertexElm)va_arg(p, int))
    {
        AddAlGraphVertex(g, AV(ver));
    }
    va_end(p);

}
void AddAlGraphVertex(AlGraph *g, AlVertex v)
{
    int len = SizeOf(g);
    if(len >= 0)
    (*g)[len].data = v.data;
}

// add edge
static AlEdge *LastEdgeOf(AlEdge *v)
{
    if(v != NULL)
    {
        AlEdge *ret = LastEdgeOf(v->next);
        if(ret == NULL) return v;
        else return ret;
    }
    return NULL;
}
void AddAlGraphEdge(AlGraph *g, AlVertex v1, AlVertex v2)
{
    int is = IndexOf(g, v1);
    int id = IndexOf(g, v2);

    AlEdge *last = LastEdgeOf((*g)[is].edge);
    AlEdge *e = (AlEdge *)malloc(sizeof(AlEdge));
    e->index = id;
    e->next = NULL;

    if(last == NULL) (*g)[is].edge = e;
    else last->next = e;
}

// show
void ShowAlGraph(AlGraph *g)
{
    int len = SizeOf(g);
    for(int i = 0 ; i < len; i++)
    {
        printf(" [%c:%d]", (*g)[i].data, i);
        for(AlEdge *e = (*g)[i].edge; e != NULL; e = e->next)
        {
            printf(" -> {%c:%d}", (*g)[e->index].data, e->index);            
        }
        printf("\r\n");
    }

}

// Search
int IsAlGraphAdjacent(AlGraph *g, AlVertex v1, AlVertex v2)
{
    int i1 = IndexOf(g, v1);
    int i2 = IndexOf(g, v2);

    AlEdge *p = (*g)[i1].edge;
    for(; p!=NULL ; p=p->next)
    {
        if( p->index == i2 ) return 1;
    }

    return 0;
}
void GetAlGraphNeighbors(AlVertex *buf, AlGraph *g, AlVertex v)
{
    int i1 = IndexOf(g, v);

    AlEdge *p = (*g)[i1].edge;
    for(; p!=NULL ; p=p->next)
    {
        *buf++ = (*g)[p->index];
    }    
}
void GetAlGraphBFS(AlVertex *buf, AlGraph *g, int v)
{
    int flag[MAX_VERTEX_NUM] = {0};
    Queue q;
    int i = 0;
    InitQueue(&q);
    Entry(&q, v);
    flag[v]= 1;

    while(!q.isEmpty)
    {
        int r = (int)Out(&q);
        buf[i++] = (*g)[r];
        for(int n = GetAlGraphFirstNeighborIndex(g, r); n >= 0 ;
            n = GetAlGraphNextNeighborIndex(g, r, n))
        {
            if( flag[n] == 0 )
            {
                Entry(&q, n);
                flag[n] = 1;
            }
        }
        for(int j = 0; j < MAX_VERTEX_NUM; j++)
            printf("%d ", flag[j]);
        printf("\r\n");
    }
}
int GetAlGraphFirstNeighborIndex(AlGraph *g, int v)
{
    if( (*g)[v].edge != NULL )
        return (*g)[v].edge->index;
    else   
        return -1;
}
int GetAlGraphNextNeighborIndex(AlGraph *g, int v, int n)
{
    for(AlEdge *r = (*g)[v].edge; r != NULL ; r = r->next)
    {
        if( r->index == n )
        {
            return r->next ? r->next->index : -1;
        }
    }
    return -1;
}


