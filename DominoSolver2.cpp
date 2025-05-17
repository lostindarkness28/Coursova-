#include "DominoSolver2.h"
DominoSolver2::DominoSolver2(Board2& b) {
    board = &b;// Зберігаємо адресу поля
    dominoId = 1;
    //Доміно спочатку невикористані
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 7; ++j){
            usedDomino[i][j] = false;
        }
    }
    for (int i = 0; i < ROWS; ++i){
        for (int j = 0; j < COLS; ++j){
            board->dominoMap[i][j] = 0;
        }
    }
}
bool DominoSolver2::domino(int r, int c) {
    if (r >= ROWS) {
        for (int i = 0; i < ROWS; i++) {
            if (!board->checkRow(i)){//Перевіряєм рядки на коректність
                return false;
            }
        }
        for (int j = 0; j < COLS; j++) {
            if (!board->checkCol(j)){//Аналогічно стовпці
                return false;
            }
        }
        return true;
    }
    int nr, nc;
    board->nextCell(r, c, nr, nc);//Отримую координати наступної комірки
    if (!board->avCells[r][c] || board->array[r][c] != -1){
        return domino(nr, nc);//Переходшу на наступну комірку якщо дана недоступна,або зайнята
    }
    //Спроба горизотального ромзміщення
    if (c + 1 < COLS && board->avCells[r][c+1] && board->array[r][c+1] == -1) {
        for (int a = 0; a < 7; a++) {
            for (int b = a; b < 7; b++) {
                if (usedDomino[a][b]){
                    continue;//Пропускаємо якщо доміношка з таким значенням вже зайнята
                }
                board->array[r][c] = a;
                board->array[r][c+1] = b;
                board->dominoMap[r][c] = board->dominoMap[r][c+1] = dominoId++;
                usedDomino[a][b] = true;
                //Перевіряємо сусідні комірки,і умови по рядкам і стовпцям
                if (board->sameNumber(r, c) && board->sameNumber(r, c+1) && board->checkRow(r) && board->checkCol(c) && board->checkCol(c+1)) {
                    if (domino(nr, nc)){
                        return true;//рекурсія
                    }
                }
                //Відкат в разі невдачі
                usedDomino[a][b] = false;
                dominoId--;
                board->array[r][c] = -1;
                board->array[r][c+1] = -1;
                board->dominoMap[r][c] = board->dominoMap[r][c+1] = -1;
                //Спроба перевернути доміношку
                if (a != b) {
                    board->array[r][c] = b;
                    board->array[r][c+1] = a;
                    board->dominoMap[r][c] = board->dominoMap[r][c+1] = dominoId++;
                    usedDomino[a][b] = true;
                    if (board->sameNumber(r, c) && board->sameNumber(r, c+1) && board->checkRow(r) && board->checkCol(c) && board->checkCol(c+1)) {
                        if (domino(nr, nc)){
                            return true;//Повторна рекурсія
                        }
                    }
                    //Відкат
                    usedDomino[a][b] = false;
                    dominoId--;
                    board->array[r][c] = -1;
                    board->array[r][c+1] = -1;
                    board->dominoMap[r][c] = board->dominoMap[r][c+1] = -1;
                }
            }
        }
    }
    //Аналогічно тільки вертикальне розміщення
    if (r + 1 < ROWS && board->avCells[r+1][c] && board->array[r+1][c] == -1) {
        for (int a = 0; a < 7; a++) {
            for (int b = a; b < 7; b++) {
                if (usedDomino[a][b]){
                    continue;
                }
                board->array[r][c] = a;
                board->array[r+1][c] = b;
                board->dominoMap[r][c] = board->dominoMap[r+1][c] = dominoId++;
                usedDomino[a][b] = true;
                if (board->sameNumber(r, c) && board->sameNumber(r+1, c) && board->checkRow(r) && board->checkRow(r+1) && board->checkCol(c)) {
                    if (domino(nr, nc)){
                        return true;
                    }
                }
                usedDomino[a][b] = false;
                dominoId--;
                board->array[r][c] = -1;
                board->array[r+1][c] = -1;
                board->dominoMap[r][c] = board->dominoMap[r+1][c] = -1;
                if (a != b) {
                    board->array[r][c] = b;
                    board->array[r+1][c] = a;
                    board->dominoMap[r][c] = board->dominoMap[r+1][c] = dominoId++;
                    usedDomino[a][b] = true;
                    if (board->sameNumber(r, c) && board->sameNumber(r+1, c) && board->checkRow(r) && board->checkRow(r+1) && board->checkCol(c)) {
                        if (domino(nr, nc)){
                            return true;
                        }
                    }
                    usedDomino[a][b] = false;
                    dominoId--;
                    board->array[r][c] = -1;
                    board->array[r+1][c] = -1;
                    board->dominoMap[r][c] = board->dominoMap[r+1][c] = -1;
                }
            }
        }
    }
    return false;
}
