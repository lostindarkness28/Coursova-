#pragma once
#include "Board2.h"
#include "DominoSolver2.h"
class Printer2{
public:
    void printStart(const Board2& board);
    void printResult(const Board2& board, const DominoSolver2& solver);
};