#ifndef _MAG_H_
#define _MAG_H_

#include "typedef.h"
typedef char MaVertex;

typedef struct mag_edge_s
{
    MaVertex src;
    MaVertex dst;
}MaEdge;

typedef struct mag_s
{
    MaVertex *verx;
    int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MaGraph;


extern void InitMaGraph(MaGraph *);
extern void CleanMaGraph(MaGraph *);
extern void AddMaGraphVertex(MaGraph *, MaVertex);
extern void AddMaGraphVertexs(MaGraph *mag, ...);
extern void DeleteMaGraphVertex(MaGraph *, MaVertex);
extern void AddMaGraphEdge(MaGraph *, MaEdge);
extern void ShowMaGraph(MaGraph *);

#endif