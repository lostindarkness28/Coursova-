#include "Board.h"
#include "DominoSolver.h"
#include "Printer.h"
#include "Board2.h"
#include "DominoSolver2.h"
#include "Printer2.h"
#include <iostream>
using namespace std;
int main() {
    while (true) {
        cout << "\nМеню \n";
        cout << "1 - Обрати першу програму (Доміно на прямокутнії дошці)\n";
        cout << "2 - Обрати другу програму (Доміно на розширеній дошці)\n";
        cout << "3 - Вихід\n";
        cout << "\n";
        int choice;
        cout << "Ваш вибір: ";
        while (!(cin >> choice)) {  
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Некоректний вибір. Введіть число від 1 до 3.\n";
            cout << "Ваш вибір: ";
        }
        cin.ignore(100, '\n');  
        if (choice == 1) {
            Board board;
            DominoSolver solver(board);
            Printer printer;
            
            cout << "\nВи обрали **Доміно на прямокутній дошці**.\n";
            cout << "На ігровому полі заданонабір доміно, ĸожне доміно зустрічається рівно один раз.\n";
            cout<<"Намалюйте лінії, щоб відзначити становище ĸожного доміно:\n\n";
            printer.printBoard(board);
            while (true) {
                cout << "\nОберіть дію:\n";
                cout << "1 - Подивитись рішення\n";
                cout << "2 - Повернутися до меню\n";
                cout << "Ваш вибір: ";
                while (!(cin >> choice)) { 
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << " Некоректний вибір. Введіть 1 або 2.\n";
                    cout << "Ваш вибір: ";
                }

                cin.ignore(100, '\n');  
                if (choice == 1) {
                    if (solver.solve()) {
                        cout << "\nРозв'язок знайдено!\n";
                        printer.printResult(board, solver);
                    } else {
                        cout << "Немає розв'язку для цієї конфігурації.\n";
                    }
                    break;
                } else if (choice == 2) {
                    break;
                } else {
                    cout << "Некоректний вибір. Спробуйте ще раз.\n";
                }
            }
        } else if (choice == 2) {
            Board2 board2;
            DominoSolver2 solver2(board2);
            Printer2 printer2;
            cout << "\nВи обрали **Доміно на розширеній дошці**.\n";
            cout << "Ця програма працює з більш складним полем для доміно.Кожну ĸістячĸу доміно можна виĸористовувати лише один раз.\n";
            cout<<"Дотичні половинĸи двох доміно повинні містити однаĸові цифри.Цифри за межами ігрового поля позначають усі цифри,\n";
            cout<<"що виĸористовуються у відповідному напрямĸу, у будь-яĸому порядĸу:\n\n";
            board2.initializeStartArray();
            printer2.printStart(board2);
            while (true) {
                cout << "\nОберіть дію:\n";
                cout << "1 - Подивитись рішення\n";
                cout << "2 - Повернутися до меню\n";
                cout << "Ваш вибір: ";
                while (!(cin >> choice)) {  
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Некоректний вибір. Введіть 1 або 2.\n";
                    cout << "Ваш вибір:";
                }
                cin.ignore(100, '\n');  
                if (choice == 1) {
                    cout<<"\n";
                    solver2.domino(0, 0);
                    printer2.printResult(board2, solver2);
                    break;
                } else if (choice == 2) {
                    break;
                } else {
                    cout << "Некоректний вибір. Спробуйте ще раз.\n";
                }
            }
        } else if (choice == 3) {
            cout << "\nВихід з програми!\n";
            break;
        } else {
            cout << "Некоректний вибір. Введіть число від 1 до 3.\n";
        }
    }
    return 0;
}