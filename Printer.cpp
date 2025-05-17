#include "Printer.h"
#include <iostream>
using namespace std;
//Виводить границю для ігрового поля
void Printer::printBoard(Board& board) {
    cout<<"     Початкове поле          "<< endl;
    cout << "+--------------------------------+" << endl;//
    for (int i = 0; i < 7; i++) {
        cout<<endl;
        cout << "|"; 
        for (int j = 0; j < 8; j++) {
            cout << "  " << board.array[i][j] << " ";
        }
        cout << "|" << endl; 
    }
    cout << "+--------------------------------+" << endl;
}
//Вивід готового поля з обведенеми комірками
void Printer::printResult(Board& board, DominoSolver& solver) {
    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            int id = solver.getMap(i,j);
            bool up = (i == 0 ||  solver.getMap(i - 1,j) != id);
            if (up) {
                cout << "+---";
            }else{
                cout << "    ";
            }
        }
        cout << "+\n";
        for (int j = 0; j < COLS1; ++j) {
            int id = solver.getMap(i,j);
            bool left = (j == 0 || solver.getMap(i,j-1) != id);
            bool right = (j == COLS1 - 1 );
            if (left) {
                cout << "| ";
            } else {
                cout << "  ";
            }
            cout << board.array[i][j];
            if (right) {
                cout << " ";
            } else {
                cout << " ";
            }
        }
        cout << "|\n";
    }
    for (int j = 0; j < COLS1; ++j){
        cout << "+---";
    }
    cout << "+\n";
}
