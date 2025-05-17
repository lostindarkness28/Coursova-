#pragma once
#include "Board.h"
#include "DominoSolver.h"
class Printer {
public:
    void printBoard( Board& board);//Початковий масив
    void printResult( Board& board, DominoSolver& solver);
};