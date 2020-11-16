#include "mag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexof(VertexType *p, VertexType data)
{
    for(int i = 0; i < MAX_VERTEX_NUM; i++ )
    {
        if(p[i] == data) return i;
    }
    return -1;
}

void InitMaGraph(MaGraph *mag)
{
    mag->verx= (VertexType *)malloc(sizeof(VertexType) * MAX_VERTEX_NUM);
    memset(mag->verx, '\0', sizeof(VertexType) * MAX_VERTEX_NUM);

    FOR(i, MAX_VERTEX_NUM) 
    FOR(j, MAX_VERTEX_NUM)
        mag->edge[i][j] = 0;
}

void CleanMaGraph(MaGraph *mag)
{
    free(mag->verx);
}

void AddMaGraphVertexs(MaGraph *mag, int len, VertexType datas[])
{
    for(int i = 0 ; i < len; i++)
    {
        AddMaGraphVertex(mag, datas[i]);
    }
}


void AddMaGraphVertex(MaGraph *mag, VertexType data)
{
    int len = strlen(mag->verx);
    mag->verx[len] = data;
}
void AddMaGraphEdge(MaGraph *mag, EdgeType edge)
{
    int is = indexof(mag->verx, edge.src);
    int id = indexof(mag->verx, edge.dst);
    mag->edge[is][id] = 1;

}


typedef unsigned short int DSType;
static DSType picture[30][30] = {{0x00}}; 
inline static void Set(int x, int y, const char *s)
{
    // 20 5F 2F 5C
    // ' ' '_' '/' '\'
    picture[y][x] = s[0] << 8 | s[1];
}

inline static DSType Get(int x, int y)
{
    return picture[y][x];
}

static void DrawDown(int sx, int sy, int ex, int ey)
{
    ey = ey - sy;
    for(int i = 0, j = sx ; j <= ex; j++)
    {
        i = (j * -ey)/ex;
        if( (char)Get(j-1, sy + (-i)) == '_')
            Set(j, sy + (-i), "__");
        else Set(j, sy + (-i), "\\_");
    }
}

static void DrawUp(int sx, int sy, int ex, int ey)
{
    ey = sy - ey;
    for(int i = ey, j = ex ; j >= 0; j--)
    {
        i = (j * ey) / ex;
        char prio = (char)(Get(j+1, sy-i) >> 8);
        if( prio == '_' )
            Set(j, sy-i, "__");
        else Set(j, sy-i, "_/");
    }
}

static void DrawLine( int sx, int sy, int ex, int ey)
{
    if(sy <= ey )
        DrawDown(sx, sy,ex,ey);
    else
        DrawUp(sx, sy, ex, ey);    
}

static void CleanMaGraphDS(int x, int y)
{
    FOR(i, x)
    FOR(j, y)
    Set(i, j, "  "); 
}

static void ShowMaGraphDS(int x, int y)
{
    printf("  ");
    FOR(i, x)
    printf("%2d", i);
    printf("\r\n");

    FOR(i, y){
        printf("%2d", i);
        FOR(j, x){
            printf("%c%c", picture[i][j] >> 8, picture[i][j]);
        }
        printf("\r\n");
    }


}

static void ShowMaGraphVertex(MaGraph *mag, VertexType ver)
{
    int len = strlen(mag->verx);
    for(int i = 0 ; i < len; i++)
    {
        
    }
}

void ShowMaGraph(MaGraph *mag)
{
    CleanMaGraphDS(30, 30);
    DrawLine(0,29, 29, 0);
    DrawLine(0,6, 29, 6);
    DrawLine(0,12, 29, 12);
    DrawLine(0, 0, 29, 29);
    ShowMaGraphDS(30, 15);

    FOR(i, MAX_VERTEX_NUM)
    {
        FOR(j, MAX_VERTEX_NUM)
            printf("%2d", mag->edge[i][j]);    
        printf("\r\n");
    }
}
