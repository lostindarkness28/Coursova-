#pragma once
#include "Board.h"
class DominoSolver {
private:
    Board* board;
    int dominoId;
    int dominoMap[ROWS1][COLS1];
    bool usedDomino[7][7];

public:
    DominoSolver(Board& b);
    bool solve(int r = 0, int c = 0);
    int getDominoId() ;
    int getMap(int r, int c);
};