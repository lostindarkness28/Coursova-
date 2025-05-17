#include "DominoSolver.h"
#include <algorithm>//для мин макс
using namespace std;
DominoSolver::DominoSolver(Board& b) {
    board = &b;
    dominoId = 1;
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            usedDomino[i][j] = false;
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            dominoMap[i][j] = 0;
}
bool DominoSolver::solve(int r, int c) {
    if (r == ROWS){
        return true;
    }
    if (c == COLS) {
        return solve(r + 1, 0);
    }
    if (board->usedCell[r][c]){
        return solve(r, c + 1);
    }
    int a = board->array[r][c];
    board->usedCell[r][c] = true;
    if (board->isValid(r, c + 1)) {
        int b = board->array[r][c + 1];
        int x = min(a, b), y = max(a, b);
        if (!usedDomino[x][y]) {
            usedDomino[x][y] = true;
            board->usedCell[r][c + 1] = true;
            dominoMap[r][c] = dominoId;
            dominoMap[r][c + 1] = dominoId;
            dominoId++;
            if (solve(r, c + 2)){
                return true;
            }
            dominoId--;
            usedDomino[x][y] = false;
            board->usedCell[r][c + 1] = false;
        }
    }

    if (board->isValid(r + 1, c)) {
        int b = board->array[r + 1][c];
        int x = min(a, b), y = max(a, b);
        if (!usedDomino[x][y]) {
            usedDomino[x][y] = true;
            board->usedCell[r + 1][c] = true;
            dominoMap[r][c] = dominoId;
            dominoMap[r + 1][c] = dominoId;
            dominoId++;
            if (solve(r, c + 1)){
                return true;
            }
            dominoId--;
            usedDomino[x][y] = false;
            board->usedCell[r + 1][c] = false;
        }
    }
    board->usedCell[r][c] = false;
    return false;
}

int DominoSolver::getDominoId() {
    return dominoId;
}
int DominoSolver::getMap(int r, int c) {
    return dominoMap[r][c];
}