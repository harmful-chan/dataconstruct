#include "mag.h"
#include "alg.h"
#define ADD(a) 

int main(void)
{
    // MaGraph mag;
    // InitMaGraph(&mag);
    // AddMaGraphVertexs(&mag, 'A', 'B', 'C', 'D', '\0');
    // AddMaGraphEdge(&mag, (MaEdge){'A', 'B'});
    // AddMaGraphEdge(&mag, (MaEdge){'B', 'C'});
    // AddMaGraphEdge(&mag, (MaEdge){'C', 'D'});
    // AddMaGraphEdge(&mag, (MaEdge){'D', 'A'});
    // ShowMaGraph(&mag);
    // CleanMaGraph(&mag);
    AlGraph alg;
    InitAlGraph(&alg);
    AddAlGraphVertexs(&alg, 'A', 'B', 'C', 'D', '\0');
    AddAlGraphEdge(&alg, 'A', 'B');
    AddAlGraphEdge(&alg, 'B', 'C');
    AddAlGraphEdge(&alg, 'C', 'D');
    AddAlGraphEdge(&alg, 'D', 'A');
    ShowAlGraph(&alg);
    CleanAlGraph(&alg);
    return 0;
}