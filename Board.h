#pragma once
const int ROWS = 7;
const int COLS = 8;
class Board {
public:
    int array[ROWS][COLS];
    bool usedCell[ROWS][COLS];
    Board();
    bool isValid(int r, int c);
};