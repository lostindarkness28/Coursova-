#include "DominoSolver.h"
#include <algorithm>// для min та max
using namespace std;
DominoSolver::DominoSolver(Board& b) {
    board = &b;// Зберігаємо адресу дошки
    dominoId = 1;//Початковий ID
    //Встановлюэмо для всіх доміно,що вони не використані
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 7; ++j)
            usedDomino[i][j] = false;
    }
    //ID кожного доміно 0
    for (int i = 0; i < ROWS1; ++i){
        for (int j = 0; j < COLS1; ++j)
            dominoMap[i][j] = 0;
    }
}
// Рекурсивний метод для розв’язання задачі розміщення доміно
bool DominoSolver::solve(int r, int c) {
    if (r == ROWS1){
        return true;
    }
    if (c == COLS1) {
        return solve(r + 1, 0);
    }
    if (board->usedCell[r][c]){
        return solve(r, c + 1);// Якщо клітинка вже використана,преходимо до наступної
    }
    int a = board->array[r][c]; // Значення у поточній клітинці
    board->usedCell[r][c] = true;// Позначаємо цю клітинку як використану
    // Перевіряємо можливість поставити доміно вправо
    if (board->isValid(r, c + 1)) {
        int b = board->array[r][c + 1]; // Значення сусідньої клітинки справа
        int x = min(a, b), y = max(a, b); // Визначаємо пару чисел доміно у впорядкованому вигляді
        // Якщо ця пара доміно ще не використана,то позначаємо як використану
        if (!usedDomino[x][y]) {
            usedDomino[x][y] = true;
            board->usedCell[r][c + 1] = true;//Сусідня комірка тепер використана
            dominoMap[r][c] = dominoId;//Присвоюємо ID обом коміркам
            dominoMap[r][c + 1] = dominoId;
            dominoId++;//Збільшую для наступної доміно
            if (solve(r, c + 2)){// Рекурсивно намагаюсь розтавити доміно з наступної комірки
                return true;
            }
            // Якщо розв’язок не знайдено, відкат змін 
            dominoId--;
            usedDomino[x][y] = false;
            board->usedCell[r][c + 1] = false;
        }
    }
      // Перевіряємо можливість поставити доміно вниз(аналогічно)
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
    board->usedCell[r][c] = false;// Якщо доміно не вдалося поставити ні вправо, ні вниз — звільняємо клітинку
    return false;// Повертаємо false — розв’язок не знайдено для цієї комірки
}
int DominoSolver::getMap(int r, int c) {
    return dominoMap[r][c];// Повертає ідентифікатор доміно, що займає клітинку (r, c)
}