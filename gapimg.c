#include "gapimg.h"
#include <stdio.h>
inline static void Set(GraphImage *p, int x, int y, const char *s)
{
    // 20 5F 2F 5C
    // ' ' '_' '/' '\'
    (*p)[y][x] = s[0] << 8 | s[1];
}

static void DrawDown(GraphImage *p, int sx, int sy, int ex, int ey)
{
    ey = ey - sy;
    for(int i = 0, j = sx ; j <= ex; j++)
    {
        i = (j * -ey)/ex;
        // if( (char)Get(j-1, sy + (-i)) == '_')
        //     Set(j, sy + (-i), "__");
        // else Set(j, sy + (-i), "\\_");
        if( (*p)[j-1][sy-i] == '_')
            Set(p, j, sy-i, "__");
        else 
            Set(p, j, sy-i, "\\_");

    }
}

static void DrawUp(GraphImage *p, int sx, int sy, int ex, int ey)
{
    ey = sy - ey;
    for(int i = ey, j = ex ; j >= 0; j--)
    {
        i = (j * ey) / ex;
        // char prio = (char)(Get(j+1, sy-i) >> 8);
        // if( prio == '_' )
        //     Set(j, sy-i, "__");
        // else Set(j, sy-i, "_/");
        char prio = (*p)[j+1][sy-i] >> 8;
        if( prio == '_' )
            Set(p, j, sy-i, "__");
        else 
            Set(p, j, sy-i, "_/");
    }
}

static void DrawLine(GraphImage *p,  int sx, int sy, int ex, int ey)
{
    if( (sx <= ex && sy <= ey) || (ex <= sx && ey <= sy) )
    {
        DrawDown(p, sx, sy,ex,ey);
    }
    else
    {
        DrawUp(p, sx, sy, ex, ey);    
    }
}

static void CleanMaGraphImage(GraphImage *p)
{
    for(int i = 0; i < IMG_SIZE; i++)
        for(int j = 0; j < IMG_SIZE; j++)
            Set(p, i, j, "  "); 
}

static void DepictMaGraphImage(MaGraph *mag, GraphImage *p)
{
    DrawLine(p, 0, 0, 20, 20);
    DrawLine(p, 0, 6, 20, 14);
    DrawLine(p, 0, 14, 20, 6);
    DrawLine(p, 0, 20, 20, 0);

}

void ShowMaGraphImage(MaGraph *mag)
{
    GraphImage pic;
    CleanMaGraphImage(&pic);
    DepictMaGraphImage(mag, &pic);

    // table head.
    printf("  ");
    for(int i = 0; i < IMG_SIZE; i++)
        printf("%2d", i);
    printf("\r\n");

    // body
    for(int i = 0; i < IMG_SIZE; i++)
    {
        printf("%2d", i);
        for(int j = 0; j < IMG_SIZE; j++)
        {
            printf("%c%c", pic[i][j] >> 8, pic[i][j]);
        }
        printf("\r\n");
    }
}
