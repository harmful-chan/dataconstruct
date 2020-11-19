#include "alg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapimg.h"
#include <stdarg.h>

// common
static int IndexOf(AlGraph *g, AlVertexElm e)
{
    for(int i = 0; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ )
    {
        if((*g)[i].data == e) return i;
    }
    return -1;
}
static int SizeOf(AlGraph *g)
{
    int i = 0;
    for(; i < MAX_VERTEX_NUM && (*g)[i].data != '\0'; i++ );
    return i < MAX_VERTEX_NUM ? i : -1;
}

// init graph
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
        AddAlGraphVertex(g, ver);
    }
    va_end(p);

}
void AddAlGraphVertex(AlGraph *g, AlVertexElm data)
{
    int len = SizeOf(g);
    if(len >= 0)
    (*g)[len].data = data;
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
void AddAlGraphEdge(AlGraph *g, AlVertexElm s, AlVertexElm d)
{
    int is = IndexOf(g, s);
    int id = IndexOf(g, d);

    AlEdge *dstEdge = LastEdgeOf((*g)[is].edge);
    AlEdge *e = (AlEdge *)malloc(sizeof(AlEdge));
    e->index = id;
    e->next = NULL;
    if(dstEdge == NULL) (*g)[is].edge = e;
    else dstEdge->next = e;
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
