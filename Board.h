#pragma once
const int ROWS1 = 7;// Кількість рядків у дошці
const int COLS1 = 8; // Кількість стовпців у дошці
class Board {
public:
    int array[ROWS1][COLS1];// Основний масив для зберігання цифр у дошці
    bool usedCell[ROWS1][COLS1]; // Масив, що позначає, чи використана клітинка (true - використана)
    Board();
    bool isValid(int r, int c);//перевіряє чи можна використовувати конкретну комірку
};