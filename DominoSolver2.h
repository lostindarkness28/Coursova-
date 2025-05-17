#pragma once
#include "board2.h"
class DominoSolver2 {
private:
     Board2* board;
     int dominoId;
     bool usedDomino[7][7];
public:
    DominoSolver2(Board2& b);
    bool domino(int r, int c);
};