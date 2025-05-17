#include "Board.h"
#include "DominoSolver.h"
#include "Printer.h"
#include <iostream>
using namespace std;
int main() {
    Board board;
    DominoSolver solver(board);
    Printer printer; // <- создаем объект

    printer.printBoard(board); // <- вызываем через объект

    if (solver.solve()) {
        cout << "\nРозв'язок:\n";
        printer.printResult(board, solver);
    } else {
        cout << "Немає розв'язку." <<endl;
    }

    return 0;
}