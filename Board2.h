#pragma once
const int ROWS = 11;
const int COLS = 11;
class Board2 {
public:
    int array[ROWS][COLS];
    int dominoMap[ROWS][COLS];
    static bool avCells[ROWS][COLS];// Статичний масив доступних клітинок (чи можна їх використовувати)
    static bool rowDigits[ROWS][7];
    static bool colDigits[COLS][7];
    static bool specificRow[ROWS];
    static bool specificCol[COLS];
    Board2();
    void initializeStartArray();// Метод для початкового заповнення масиву значеннями,щоб було видно доступні і не доступні комірки
    void specificValues();//встановлює набори цифри які повинні бути використані в певному рядку чи стовпці
    bool sameNumber(int r, int c);//перевірка чи однакові значення на сусідніх комірках різних доміно
    bool checkRow(int r);
    bool checkCol(int c);
    void nextCell(int r, int c, int &nr, int &nc);//перехід до наступної комірки
};