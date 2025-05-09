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
bool specificRow[ROWS]={};
bool specificCol[COLS]={};
void specificValues() {
    specificRow[0]=true;
    rowDigits[0][2] = true; rowDigits[0][0] = true; rowDigits[0][1] = true; rowDigits[0][5] = true;
    specificRow[6]=true;
    rowDigits[6][1] = true; rowDigits[6][3] = true; rowDigits[6][4] = true;
    specificRow[9]=true;
    rowDigits[9][0] = true; rowDigits[9][2] = true; rowDigits[9][3] = true;
    specificCol[0]=true;
    colDigits[0][2] = true; colDigits[0][4] = true; colDigits[0][6] = true;
    specificCol[2]=true;
    colDigits[2][0] = true; colDigits[2][1] = true; colDigits[2][5] = true;
    specificCol[4]=true;
    colDigits[4][0] = true; colDigits[4][3] = true; colDigits[4][6] = true;
    specificCol[6]=true;
    colDigits[6][1] = true; colDigits[6][3] = true; colDigits[6][6] = true;
    specificCol[8]=true;
    colDigits[8][0] = true; colDigits[8][1] = true; colDigits[8][5] = true;
    specificCol[10]=true;
    colDigits[10][1] = true; colDigits[10][2] = true; colDigits[10][3] = true; colDigits[10][4] = true;
}
int array[ROWS][COLS];
int dominoId = 1;
int dominoMap[ROWS][COLS];
bool usedDomino[7][7] = {false};
void initializeStartArray() {
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            if (avCells[r][c]) {
                array[r][c] = -1;
                dominoMap[r][c] = -1;
            } else {
                array[r][c] = 0;
                dominoMap[r][c] = 0;
            }
        }
    }
}
void printStartArray() {
     for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (array[r][c] == 0)
                cout << "   "; 
            else
                cout << array[r][c] << " "; 
        }
        cout << endl;
    }
}
bool sameNumber(int r, int c) {
    int d = array[r][c];
    if (r > 0 && avCells[r-1][c] && dominoMap[r-1][c] != -1 && dominoMap[r-1][c] != dominoMap[r][c]){
         if (array[r-1][c] != d){ 
            return false;
        }
    }
    if (r < ROWS-1 && avCells[r+1][c] && dominoMap[r+1][c] != -1 &&dominoMap[r+1][c] != dominoMap[r][c]){
         if (array[r+1][c] != d){
            return false;
        }
    }
    if (c > 0 && avCells[r][c-1] && dominoMap[r][c-1] != -1 && dominoMap[r][c-1] != dominoMap[r][c]){
         if (array[r][c-1] != d){ 
            return false;
        }
    }
    if (c < COLS-1 && avCells[r][c+1] && dominoMap[r][c+1] != -1 &&dominoMap[r][c+1] != dominoMap[r][c]){
         if (array[r][c+1] != d){
            return false;
        }
    }
    return true;
}
bool checkRow(int r){
    if(!specificRow[r]){
        return true;
    }
    bool allCell;
    bool found[7];
    for(int c=0;c<COLS;c++){
        if(avCells[r][c]){
            if(array[r][c]==-1){
                allCell=false;
                break;
            }
            int d=array[r][c];
            if(!rowDigits[r][d]){
                return false;
            }
            found[d]=true;
        }
    }
    if(!allCell){
        return true;//повертаємо тру тому що,оскількі  ще якась комірка просто не заповнена,але і переходити до подальшої перевірки коректності ми не можемо
    }
    for(int d=0;d<7;d++){
        if(rowDigits[r][d]&&!found[d]){
            return false;
        }
    }
    return true;
}
bool checkCol(int c){
    if(!specificCol[c]){
        return true;
    }
    bool allCell;
    bool found[7];
    for(int r=0;r<ROWS;r++){
        if(avCells[r][c]){
            if(array[r][c]==-1){
                allCell=false;
                break;
            }
            int d=array[r][c];
            if(!colDigits[c][d]){
                return false;
            }
            found[d]=true;
        }
    }
    if(!allCell){
        return true;
    }
    for(int d=0;d<7;d++){
        if(colDigits[c][d]&&!found[d]){
            return false;
        }
    }
    return true;
}
void nextCell(int r, int c, int &nextR, int &nextC) {
    nextC = c + 1;
    nextR = r;
    if (nextC >= COLS) {
        nextR = r + 1;
        nextC = 0;
    }
}
bool Domino(int r, int c) {
    if (r == ROWS) {
        for (int i = 0; i < ROWS; i++){
            if (!checkRow(i))
                return false;
        }
        for (int j = 0; j < COLS; j++){
            if (!checkCol(j))
                return false;
        }
        return true;
    }
}
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
    initializeStartArray();
    cout << "Початковий массив доступних і не доступних комірок:" << endl;
    printStartArray();
    return 0;
}
