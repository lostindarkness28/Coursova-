#pragma once
const int ROWS1 = 7;
const int COLS1 = 8;
class Board {
public:
    int array[ROWS1][COLS1];
    bool usedCell[ROWS1][COLS1];
    Board();
    bool isValid(int r, int c);
};