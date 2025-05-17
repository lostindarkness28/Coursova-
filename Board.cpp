#include "Board.h"
Board::Board() {
    int temp[ROWS][COLS] = {
        {4,6,2,5,5,2,0,1},
        {0,4,4,0,0,1,6,3},
        {2,4,4,1,1,3,1,5},
        {2,5,0,2,2,2,0,0},
        {5,3,3,6,4,1,3,5},
        {1,4,1,4,5,6,6,5},
        {6,6,3,0,3,3,6,2}
    };
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = temp[i][j];
            usedCell[i][j] = false;
        }
}
bool Board::isValid(int r, int c)  {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS && !usedCell[r][c];
}