#ifndef _ALG_H_
#define _ALG_H_

#include "typedef.h"

#define AV(v) ((AlVertex){ v , NULL })

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
extern void AddAlGraphVertex(AlGraph *, AlVertex v);
extern void AddAlGraphVertexs(AlGraph *g, ...);
extern void DeleteAlGraphVertex(AlGraph *, AlVertex v);
extern void AddAlGraphEdge(AlGraph *, AlVertex v1, AlVertex v2);
extern void ShowAlGraph(AlGraph *);

extern int IsAlGraphAdjacent(AlGraph *g, AlVertex v1, AlVertex v2);
extern void GetAlGraphNeighbors(AlVertex *buf, AlGraph *g, AlVertex v);
extern AlVertex GetAlGraphFirstNeighbor(AlGraph *g, AlVertex v);

extern void GetAlGraphBFS(AlVertex *buf, AlGraph *g, int v);
extern int GetAlGraphFirstNeighborIndex(AlGraph *g, int v);
extern int GetAlGraphNextNeighborIndex(AlGraph *g, int v, int n);



#endif