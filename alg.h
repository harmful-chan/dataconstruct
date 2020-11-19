#ifndef _ALG_H_
#define _ALG_H_

#include "typedef.h"

typedef char AlVertexElm;

typedef struct al_edge_s 
{
    int index;
    struct al_edge_s *next;

}AlEdge;

typedef struct
{
    AlVertexElm data;
    struct al_edge_s *edge;
}AlVertex, AlGraph[MAX_VERTEX_NUM];



extern void InitAlGraph(AlGraph *);
extern void CleanAlGraph(AlGraph *);
extern void AddAlGraphVertex(AlGraph *, AlVertexElm);
extern void AddAlGraphVertexs(AlGraph *mag, ...);
extern void DeleteAlGraphVertex(AlGraph *, AlVertexElm);
extern void AddAlGraphEdge(AlGraph *, AlVertexElm, AlVertexElm);
extern void ShowAlGraph(AlGraph *);

#endif