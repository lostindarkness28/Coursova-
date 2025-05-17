#pragma once
#include "Board.h"
class DominoSolver {
private:
    Board* board;// Вказівник на дошку для роботи з нею
    int dominoId;
    int dominoMap[ROWS1][COLS1];//Масив для збереження ідентифікаторів доміно на дошці
    bool usedDomino[7][7];
public:
    DominoSolver(Board& b);
    bool solve(int r = 0, int c = 0);
    int getMap(int r, int c);
};