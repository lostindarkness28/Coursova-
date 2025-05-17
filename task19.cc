#include "Board.h"
#include "DominoSolver.h"
#include "Printer.h"
#include "Board2.h"
#include "DominoSolver2.h"
#include "Printer2.h"


#include <iostream>
using namespace std;
int main() {
    Board board;
    DominoSolver solver(board);
    Printer printer; 
    printer.printBoard(board); 
    if (solver.solve()) {
        cout << "\nРозв'язок:\n";
        printer.printResult(board, solver);
    } else {
        cout << "Немає розв'язку." <<endl;
    }
    Board2 board2;              
    DominoSolver2 solver2(board2);     
    board2.initializeStartArray();        
    solver2.Domino(0,0);       
    Printer2 printer2;           
    printer2.printStart(board2);  
    printer2.printResult(board2, solver2); 
    return 0;
}