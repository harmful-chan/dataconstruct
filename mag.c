#include "mag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapimg.h"
#include <stdarg.h>
#include "queue.h"

static int IndexOf(MaGraph *g, MaVertex v)
{
    for(int i = 0; i < MAX_VERTEX_NUM; i++ )
    {
        if(g->verx[i] == v) return i;
    }
    return -1;
}

static int SizeOf(MaGraph *g)
{
    for(int i = MAX_VERTEX_NUM; i > 0; i--)
    {
        if( g->verx[i-1] != '\0' ) 
            return i;
    }
    return 0;
}
void InitMaGraph(MaGraph *g)
{
    memset(g->verx, '\0', sizeof(MaVertex) * MAX_VERTEX_NUM);

    FOR(i, MAX_VERTEX_NUM) 
    FOR(j, MAX_VERTEX_NUM)
        g->edge[i][j] = 0;
}

void CleanMaGraph(MaGraph *g)
{
    memset(g->verx, '\0', sizeof(MaVertex) * MAX_VERTEX_NUM);
    memset(g->edge, '\0', sizeof(int) * MAX_VERTEX_NUM * MAX_VERTEX_NUM);
    
}

void AddMaGraphVertexs(MaGraph *g, ...)
{
    va_list p;
    va_start(p, g);

    for(MaVertex ver = (MaVertex)va_arg(p, int); ver != '\0'; 
        ver = (MaVertex)va_arg(p, int))
    {
        AddMaGraphVertex(g, ver);
    }
    va_end(p);

}
void AddMaGraphVertex(MaGraph *g, MaVertex v)
{
    int len = SizeOf(g);
    if(len < MAX_VERTEX_NUM)
        g->verx[len] = v;
}

void AddMaGraphEdge(MaGraph *g, MaVertex v1, MaVertex v2)
{
    int is = IndexOf(g, v1);
    int id = IndexOf(g, v2);
    g->edge[is][id] = 1;
    g->edge[id][is] = 1;

}
void ShowMaGraph(MaGraph *g)
{
    // ShowMaGraphImage(g);

    int len = SizeOf(g);
    printf(" (");
    FOR(i, len)
        printf("%2c, ", g->verx[i]);
    printf(")\r\n");

    printf("  ");    
    FOR(i, len)
        printf("%2c", g->verx[i]);
    printf("\r\n");    


    FOR(i, len)
    {
        printf("%2c", g->verx[i]);    

        FOR(j, len)
            printf("%2d", g->edge[i][j]);    
        printf("\r\n");
    }
}
int IsMaGraphAdjacent(MaGraph *g, MaVertex v1, MaVertex v2)
{
    int i1 = IndexOf(g, v1);
    int i2 = IndexOf(g, v2);
    return g->edge[i1][i2];
}
void GetMaGraphNeighbors(MaVertex *buf, MaGraph *g, MaVertex v)
{
    int i1 = IndexOf(g, v);
    int size = SizeOf(g);
    for(int i = 0 ; i < size; i++)
    {
        if(g->edge[i1][i]) 
            *buf++ = g->verx[i];
    }    
}

int GetMaGraphFirstNeighborIndex(MaGraph *g, int v)
{
    int len = SizeOf(g);
    for(int j = 0; j < len; j++)
    {
        if( g->edge[v][j] )
            return j;
    }
    return -1;
}
int GetMaGraphNextNeighborIndex(MaGraph *g, int v, int n)
{
    int len = SizeOf(g);    
    for(int j = n+1; j < len; j++)
    {
        if( g->edge[v][j] )
            return j;
    }
    return -1;
}

void GetMaGraphBFS(MaVertex *buf, MaGraph *g, int v)
{
    int len = SizeOf(g);
    int flag[MAX_VERTEX_NUM] = {0};
    int i = 0;
    Queue q;
    InitQueue(&q);
    Entry(&q, v);
    flag[v] = 1;
    
    while(!q.isEmpty)
    {
        int r = (int)Out(&q);
        //todo
        buf[i++] = g->verx[r];

        for(int n = GetMaGraphFirstNeighborIndex(g, r); 
            n >= 0; 
            n = GetMaGraphNextNeighborIndex(g, r, n))
        {
            if( flag[n] == 0)
            {
                Entry(&q, n);
                flag[n] = 1;
            }
        }
        // printf("r=%d  ", r);

        // for(int i = 0; i < 10; i++)
        //     printf("%d ", flag[i]);
        // printf("\r\n");
    }
}


