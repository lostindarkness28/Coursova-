#pragma once
const int ROWS = 11;
const int COLS = 11;
class Board2 {
public:
    int array[ROWS][COLS];
    int dominoId;
    int dominoMap[ROWS][COLS];
    bool usedDomino[7][7];
    static bool avCells[ROWS][COLS];
    static bool rowDigits[ROWS][7];
    static bool colDigits[COLS][7];
    static bool specificRow[ROWS];
    static bool specificCol[COLS];
    Board2();
    void initializeStartArray();
    void specificValues();
    bool sameNumber(int r, int c);
    bool checkRow(int r);
    bool checkCol(int c);
    void nextCell(int r, int c, int &nr, int &nc);
};