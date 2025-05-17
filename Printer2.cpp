#include "Printer2.h"
#include <iostream>
using namespace std;
void Printer2::printStart(const Board2& board) {
    cout << "     Початкове поле          " << endl;
    cout << "+--------+            +--------+" << endl;
    cout << "|  |  |  |            |  |  |  |   ⮜  2  0  1  5" << endl;
    cout << "+-----------+      +--------------+" << endl;
    cout << "|  |  |  |  |      |  |  |  |  |  |" << endl;
    cout << "+--+  +-----+      +-----+  +-----+" << endl;
    cout << "|  |     |  |      |  |        |  |" << endl;
    cout << "+--+     +--+      +--+        +--+" << endl;
    cout << "|  |     |  |      |  |" << endl;
    cout << "+--+--+--+--+      +--+" << endl;
    cout << "|  |  |  |  |      |  |" << endl;
    cout << "+--+--+--+--+--+   +--+" << endl;
    cout << "|  |     |  |  |   |  |" << endl;
    cout << "+--+     +--+--+   +--+" << endl;
    cout << "|  |        |  |   |  |            ⮜  1  3  4" << endl;
    cout << "+--+        +--+   +--+  +--+--+--+" << endl;
    cout << "|  |        |  |   |  |  |  |  |  |" << endl;
    cout << "+--+        +--+   +--+  +--+--+--+" << endl;
    cout << "|  |        |  |   |  |        |  |" << endl;
    cout << "+--+        +--+   +--+--+     +--+" << endl;
    cout << "|  |        |  |   |  |  |     |  |⮜  0  2  3" << endl;
    cout << "+--+--+--+--+--+   +--+--+--+--+--+" << endl;
    cout << "|  |  |  |  |  |      |  |  |  |  |" << endl;
    cout << "+--+--+--+--+--+      +--+--+--+--+" << endl;
    cout << " ⮝     ⮝     ⮝      ⮝     ⮝     ⮝" << endl;
    cout << " 2     0     0      1     0     1" << endl << endl;
    cout << " 4     1     3      3     1     2" << endl << endl;
    cout << " 6     5     6      6     5     3" << endl << endl;
    cout << "                                4" << endl << endl;
}
void Printer2::printResult(const Board2& board, const DominoSolver2& solver) {
    cout << "Рішення:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!board.avCells[i][j]) {
                cout << "    ";//Пропуски в місцях де немає комірки
                continue;
            }
            int id = board.dominoMap[i][j];
            bool up = (i == 0 || !board.avCells[i - 1][j] || board.dominoMap[i - 1][j] != id);
            // Якщо верхній сусід не є частиною того ж доміно — малюємо верхню межу
            if (up){
                cout << "+---";
            }
            else{
                cout << "    ";
            }
        }
        cout << "\n";
        for (int j = 0; j < COLS; ++j) {
            if (!board.avCells[i][j]) {
                cout << "    ";//Якщо комірка недоступна то вона пропускається і навколо неї не буде обведено
                continue;
            }
            int id = board.dominoMap[i][j];
            bool left = (j == 0 || !board.avCells[i][j - 1] || board.dominoMap[i][j - 1] != id);//Перервірка лівого сусіда
            if (left) {
                cout << "|";//Вивід у разі його 
            }
            else {
                cout << " ";
            }
            //Якщо порожня клітинка
            if (board.array[i][j] == -2) {
                cout << "   ";
            } else {
                cout << " " << board.array[i][j] << " ";
            }
        }
        //Закриваємо межу остіньої клітинки якщо потрібно
        int last = -1;
        for (int j = COLS - 1; j >= 0; --j) {
            if (board.avCells[i][j]) {
                last = j;
                break;
            }
        }
        if (last != -1 && last == COLS - 1) {
            cout << "|";
        }
        cout << "\n";
    }
    //Нижні межі останього рядка
    for (int j = 0; j < COLS; ++j) {
        if (!board.avCells[ROWS - 1][j]) {
            cout << "    ";
            continue;
        }
        cout << "+---";
    }
    cout << "+" << endl;
}
