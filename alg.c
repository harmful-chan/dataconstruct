#include "alg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapimg.h"
#include <stdarg.h>

// common
static int IndexOf(AlGraph *g, AlVertex v)
{
    for(int i = 0; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ )
    {
        if((*g)[i].data == v.data) return i;
    }
    return -1;
}
static int SizeOf(AlGraph *g)
{
    int i = 0;
    for(; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ );
    return i < MAX_VERTEX_NUM ? i : -1;
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
        for(AlEdge *e = (*g)[i].edge; e != NULL; e = (*g)[i].edge->next)
        {
            printf(" -> {%c:%d}", (*g)[e->index].data, e->index);            
        }
        printf("\r\n");
    }

}


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
AlVertex GetAlGraphFirstNeighbor(AlGraph *g, AlVertex v)
{
    
}

