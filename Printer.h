#pragma once
#include "Board.h"
#include "DominoSolver.h"

class Printer {
public:
    void printBoard( Board& board);
    void printResult( Board& board, DominoSolver& solver);
    void printDominos( Board& board, DominoSolver& solver);
};