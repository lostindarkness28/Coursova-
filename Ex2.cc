#include <iostream>
using namespace std;
const int ROWS = 11;
const int COLS = 11;
bool avCells[ROWS][COLS] = {
    { true,  true,  true,  false, false, false, false, true,  true,  true,  false },
    { true,  false, true,  true,  false, false, true,  true,  false, true,  true },
    { true,  false, false, true,  false, false, true,  false, false, false, true },
    { true,  false, false, true,  false, false, true,  false, false, false, false },
    { true,  true,  true,  true,  false, false, true,  false, false, false, false },
    { true,  false, false, true,  true,  false, true,  false, false, false, false },
    { true,  false, false, false, true,  false, true,  false, false, false, false },
    { true,  false, false, false, true,  false, true,  false, true,  true,  true },
    { true,  false, false, false, true,  false, true,  false, false, false, true },
    { true,  false, false, false, true,  false, true,  true,  false, false, true },
    { true,  true,  true,  true,  true,  false, false, true,  true,  true,  true }
};
bool rowDigits[ROWS][7] = {}; 
bool colDigits[COLS][7] = {};
void RowTrue() {
    rowDigits[0][2] = true; rowDigits[0][0] = true; rowDigits[0][1] = true; rowDigits[0][5] = true;
    rowDigits[6][1] = true; rowDigits[6][3] = true; rowDigits[6][4] = true;
    rowDigits[9][0] = true; rowDigits[9][2] = true; rowDigits[9][3] = true;
}
void ColTrue() {
    colDigits[0][2] = true; colDigits[0][4] = true; colDigits[0][6] = true;
    colDigits[2][0] = true; colDigits[2][1] = true; colDigits[2][5] = true;
    colDigits[4][0] = true; colDigits[4][3] = true; colDigits[4][6] = true;
    colDigits[6][1] = true; colDigits[6][3] = true; colDigits[6][6] = true;
    colDigits[8][0] = true; colDigits[8][1] = true; colDigits[8][5] = true;
    colDigits[10][1] = true; colDigits[10][2] = true; colDigits[10][3] = true; colDigits[10][4] = true;
}
int dominoId = 1;
int dominoMap[ROWS][COLS] = {};
int main(){
    cout<<"     Початкове поле          "<< endl;
    cout << "+--------+            +--------+" << endl;
    cout << "|  |  |  |            |  |  |  |   ⮜  2  0  1  5"   << endl;
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
    cout << "+--+        +--+   +--+--+     +--+"<< endl;
    cout << "|  |        |  |   |  |  |     |  |⮜  0  2  3" << endl;
    cout << "+--+--+--+--+--+   +--+--+--+--+--+"<< endl;
    cout << "|  |  |  |  |  |      |  |  |  |  |" << endl;
    cout << "+--+--+--+--+--+      +--+--+--+--+" << endl;
    cout << " ⮝     ⮝     ⮝      ⮝     ⮝     ⮝"<<endl;
    cout << " 2     0     0      1     0     1"<<endl<<endl;
    return 0;
}
