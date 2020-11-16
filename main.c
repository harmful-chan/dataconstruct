#include "mag.h"

#define ADD(a) 

int main(void)
{
    MaGraph mag;
    VertexType tmp[] = {'A', 'B', 'C', 'D'};
    InitMaGraph(&mag);
    AddMaGraphVertexs(&mag, 4, tmp);

    AddMaGraphEdge(&mag, (EdgeType){'A', 'B'});
    AddMaGraphEdge(&mag, (EdgeType){'B', 'A'});


    ShowMaGraph(&mag);
    CleanMaGraph(&mag);
    return 0;
}