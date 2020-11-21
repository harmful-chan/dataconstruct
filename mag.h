#ifndef _MAG_H_
#define _MAG_H_

#include "typedef.h"


#define MV(v) ((MaVertex)v)

typedef char MaVertex;

typedef struct mag_edge_s
{
    MaVertex src;
    MaVertex dst;
}MaEdge;

typedef struct mag_s
{
    MaVertex verx[MAX_VERTEX_NUM];
    int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MaGraph;

extern void InitMaGraph(MaGraph *g);
extern void CleanMaGraph(MaGraph *g);
extern void AddMaGraphVertex(MaGraph *g, MaVertex v);
//extern void DeleteMaGraphVertex(MaGraph *g, MaVertex v);
extern void AddMaGraphEdge(MaGraph *g, MaVertex v1, MaVertex v2);
//extern void DeleteMaGraphEdge(MaGraph *g, MaVertex v1, MaVertex v2);
extern void AddMaGraphVertexs(MaGraph *g, ...);
extern void ShowMaGraph(MaGraph *g);

extern int IsMaGraphAdjacent(MaGraph *g, MaVertex v1, MaVertex v2);
extern void GetMaGraphNeighbors(MaVertex *buf, MaGraph *g, MaVertex v);
extern MaVertex GetMaGraphFirstNeighbor(MaGraph *g, MaVertex v);
// extern void GetMaGraphxtNeighbor(MaVertex *, MaVertex v1, MaVertex v2);


#endif