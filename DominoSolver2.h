#pragma once
#include "board2.h"
class DominoSolver2 {
private:
     Board2* board;
public:
    DominoSolver2(Board2& b);
    bool Domino(int r, int c);
};