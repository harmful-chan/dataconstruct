#include "mag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapimg.h"
#include <stdarg.h>

int indexof(MaVertex *p, MaVertex data)
{
    for(int i = 0; i < MAX_VERTEX_NUM; i++ )
    {
        if(p[i] == data) return i;
    }
    return -1;
}

void InitMaGraph(MaGraph *mag)
{
    mag->verx= (MaVertex *)malloc(sizeof(MaVertex) * MAX_VERTEX_NUM);
    memset(mag->verx, '\0', sizeof(MaVertex) * MAX_VERTEX_NUM);

    FOR(i, MAX_VERTEX_NUM) 
    FOR(j, MAX_VERTEX_NUM)
        mag->edge[i][j] = 0;
}

void CleanMaGraph(MaGraph *mag)
{
    free(mag->verx);
}

void AddMaGraphVertexs(MaGraph *mag, ...)
{
    va_list p;
    va_start(p, mag);

    for(MaVertex ver = (MaVertex)va_arg(p, int); ver != '\0'; 
        ver = (MaVertex)va_arg(p, int))
    {
        AddMaGraphVertex(mag, ver);
    }
    va_end(p);

}
void AddMaGraphVertex(MaGraph *mag, MaVertex data)
{
    int len = strlen(mag->verx);
    mag->verx[len] = data;
}

void AddMaGraphEdge(MaGraph *mag, MaEdge edge)
{
    int is = indexof(mag->verx, edge.src);
    int id = indexof(mag->verx, edge.dst);
    mag->edge[is][id] = 1;
    mag->edge[id][is] = 1;

}
void ShowMaGraph(MaGraph *mag)
{
    ShowMaGraphImage(mag);

    int len = strlen(mag->verx);
    FOR(i, len)
        printf("%c ", mag->verx[i]);

    printf("\r\n");

    FOR(i, MAX_VERTEX_NUM)
    {
        FOR(j, MAX_VERTEX_NUM)
            printf("%2d", mag->edge[i][j]);    
        printf("\r\n");
    }
}
