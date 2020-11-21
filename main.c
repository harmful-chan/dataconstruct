#include "mag.h"
#include "alg.h"
#include <stdio.h>
#define ADD(a) 

int main(void)
{
    MaGraph mag;
    printf(" MAG --- \r\n");
    InitMaGraph(&mag);
    AddMaGraphVertexs(&mag, 'A', 'B', 'C', 'D', '\0');
    AddMaGraphEdge(&mag, MV('A'), MV('B'));
    AddMaGraphEdge(&mag, MV('B'), MV('C'));
    AddMaGraphEdge(&mag, MV('C'), MV('D'));
    AddMaGraphEdge(&mag, MV('D'), MV('A'));
    ShowMaGraph(&mag);
    printf(" (A, B) is adjacent [%2d]\r\n", IsMaGraphAdjacent(&mag, MV('A'), MV('B')));
    printf(" (A, C) is adjacent [%2d]\r\n", IsMaGraphAdjacent(&mag, MV('A'), MV('C')));
    MaVertex tmp[MAX_VERTEX_NUM] = {'\0'};
    GetMaGraphNeighbors(tmp, &mag, MV('A'));
    printf(" (A) neighbors has [%10s]\r\n", tmp);
    CleanMaGraph(&mag);


    AlGraph alg;
    printf(" ALG --- \r\n");
    InitAlGraph(&alg);
    AddAlGraphVertexs(&alg, 'A', 'B', 'C', 'D', '\0');
    AddAlGraphEdge(&alg, AV('A'), AV('B'));
    AddAlGraphEdge(&alg, AV('B'), AV('C'));
    AddAlGraphEdge(&alg, AV('C'), AV('D'));
    AddAlGraphEdge(&alg, AV('D'), AV('A'));
    ShowAlGraph(&alg);
    printf(" (A, B) is adjacent [%2d]\r\n", IsAlGraphAdjacent(&alg, AV('A'), AV('B')));
    printf(" (A, C) is adjacent [%2d]\r\n", IsAlGraphAdjacent(&alg, AV('A'), AV('C')));
    AlVertex tmp1[MAX_VERTEX_NUM] = {{'\0', NULL}};
    GetAlGraphNeighbors(tmp1, &alg, AV('A'));
    printf(" (A) neighbors has [");
    for(int i = 0; tmp1[i].data != '\0'; i++)
    {
        printf("%2c", tmp1[i].data);
    }
    printf("]\r\n");

    CleanAlGraph(&alg);
    return 0;
}