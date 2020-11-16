#ifndef _MAG_H_
#define _MAG_H_

#include "stddef.h"
#define FOR(i, n) for(int i = 0; i < n; i++)

#define MAX_VERTEX_NUM 10

typedef char VertexType;


typedef struct mag_edge_s
{
    VertexType src;
    VertexType dst;
}EdgeType;

typedef struct mag_s
{
    VertexType *verx;
    int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MaGraph;


extern void InitMaGraph(MaGraph *);
extern void CleanMaGraph(MaGraph *);
extern void AddMaGraphVertex(MaGraph *, VertexType);
extern void AddMaGraphVertexs(MaGraph *, int, VertexType[]);
extern void AddMaGraphEdge(MaGraph *, EdgeType);

extern void DeleteMaGraphVertex(MaGraph *, VertexType);

extern void ShowMaGraph(MaGraph *);

#endif