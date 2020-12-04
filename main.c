#include "mag.h"
#include "alg.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "ABCDEFGHIJKLMN";
    int len = strlen(src);
    len = len <= MAX_VERTEX_NUM ? len : MAX_VERTEX_NUM;

    MaGraph mag;
    printf(" [INFO] --- --- --- MAG --- --- --- \r\n");
    InitMaGraph(&mag);
    for(int i = 0; i < len ; i++)
    {
        AddMaGraphVertex(&mag, MV(src[i]));
    }
    for(int i = 1; i < len ; i++)
    {
        AddMaGraphEdge(&mag, MV(src[i]), MV(src[i-1]));
    }
    ShowMaGraph(&mag);
    printf(" [INFO] (A, B) is adjacent [%2d]\r\n", IsMaGraphAdjacent(&mag, MV('A'), MV('B')));
    printf(" [INFO] (A, C) is adjacent [%2d]\r\n", IsMaGraphAdjacent(&mag, MV('A'), MV('C')));
    MaVertex tmp[MAX_VERTEX_NUM] = {'\0'};
    GetMaGraphNeighbors(tmp, &mag, MV('A'));
    printf(" [INFO] (A) neighbors has [%5s]\r\n", tmp);
    GetMaGraphBFS(tmp, &mag, 3);
    printf(" [INFO] (D) BFS is [%10s]\r\n", tmp);
    CleanMaGraph(&mag);


    AlGraph alg;
    printf(" [INFO] --- --- --- ALG --- --- --- \r\n");
    InitAlGraph(&alg);
    for(int i = 0; i < len ; i++)
    {
        AddAlGraphVertex(&alg, AV(src[i]));
    }
    for(int i = 1; i < len ; i++)
    {
        AddAlGraphEdge(&alg, AV(src[i]), AV(src[i-1]));
        AddAlGraphEdge(&alg, AV(src[i-1]), AV(src[i]));

    }
    ShowAlGraph(&alg);
    printf(" [INFO] (A, B) is adjacent [%2d]\r\n", IsAlGraphAdjacent(&alg, AV('A'), AV('B')));
    printf(" [INFO] (A, C) is adjacent [%2d]\r\n", IsAlGraphAdjacent(&alg, AV('A'), AV('C')));
    AlVertex tmp1[MAX_VERTEX_NUM] = {{'\0', NULL}};
    GetAlGraphNeighbors(tmp1, &alg, AV('A'));
    printf(" [INFO] (A) neighbors has [");
    for(int i = 0; tmp1[i].data != '\0' && i < MAX_VERTEX_NUM ; i++)
    {
        printf("%2c", tmp1[i].data);
    }
    printf("]\r\n");
    GetAlGraphBFS(tmp1, &alg, 3);
    printf(" [INFO] (D) BFS is [");
    for(int i = 0; tmp1[i].data != '\0' && i < MAX_VERTEX_NUM ; i++)
    {
        printf("%2c", tmp1[i].data);
    }
    printf("]\r\n");
    CleanAlGraph(&alg);
    return 0;
}