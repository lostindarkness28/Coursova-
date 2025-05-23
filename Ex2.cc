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
bool rowDigits[ROWS][7] = {false}; 
bool colDigits[COLS][7] = {false};
bool specificRow[ROWS]={false};
bool specificCol[COLS]={false};
void specificValues() {
    specificRow[0]=true;
    rowDigits[0][2] = true;
    rowDigits[0][0] = true; 
    rowDigits[0][1] = true; 
    rowDigits[0][5] = true;
    specificRow[6]=true;
    rowDigits[6][1] = true; 
    rowDigits[6][3] = true; 
    rowDigits[6][4] = true;
    specificRow[9]=true;
    rowDigits[9][0] = true; 
    rowDigits[9][2] = true; 
    rowDigits[9][3] = true;
    specificCol[0]=true;
    colDigits[0][2] = true; 
    colDigits[0][4] = true; 
    colDigits[0][6] = true;
    specificCol[2]=true;
    colDigits[2][0] = true; 
    colDigits[2][1] = true; 
    colDigits[2][5] = true;
    specificCol[4]=true;
    colDigits[4][0] = true; 
    colDigits[4][3] = true; 
    colDigits[4][6] = true;
    specificCol[6]=true;
    colDigits[6][1] = true; 
    colDigits[6][3] = true; 
    colDigits[6][6] = true;
    specificCol[8]=true;
    colDigits[8][0] = true; 
    colDigits[8][1] = true; 
    colDigits[8][5] = true;
    specificCol[10]=true;
    colDigits[10][1] = true; 
    colDigits[10][2] = true; 
    colDigits[10][3] = true;
    colDigits[10][4] = true;
}
int array[ROWS][COLS];
int dominoId;
int dominoMap[ROWS][COLS];
bool usedDomino[7][7] = {};
void initializeStartArray() {
    dominoId=1;
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            if (avCells[r][c]) {
                array[r][c] = -1;
                dominoMap[r][c] = -1;
            } else {
                array[r][c] = -2;
                dominoMap[r][c] = 0;
            }
        }
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
    bool allCell=true;
    bool found[7]={false};
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
    bool allCell=true;
    bool found[7]={};
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
void nextCell(int r, int c, int &nr, int &nc) {
    nc = c + 1;
    nr = r;
    if (nc >= COLS) {
        nr = r + 1;
        nc = 0;
    }
}
bool Domino (int r, int c) {
    if (r >= ROWS) {
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
    int nr, nc;
    nextCell(r, c, nr, nc);
    if (!avCells[r][c] || array[r][c] != -1)
        return Domino(nr, nc);
    if (c + 1 < COLS && avCells[r][c+1] && array[r][c+1] == -1) {
        for (int a = 0; a < 7; a++){
            for (int b = a; b < 7; b++){
                if (usedDomino[a][b])
                    continue;
                array[r][c] = a;
                array[r][c+1] = b;
                dominoMap[r][c] = dominoMap[r][c+1] = dominoId++;
                usedDomino[a][b] = true;
                if (sameNumber(r, c) && sameNumber(r, c+1)&& checkRow(r) && checkCol(c) && checkCol(c+1)){
                    if (Domino(nr, nc))
                        return true;
                }
                usedDomino[a][b] = false; 
                dominoId--;
                array[r][c] = -1;
                array[r][c+1] = -1;
                dominoMap[r][c] = dominoMap[r][c+1] = -1;
                if (a != b) {
                    array[r][c] = b;
                    array[r][c+1] = a;
                    dominoMap[r][c] = dominoMap[r][c+1] = dominoId++;
                    usedDomino[a][b] = true;
                    
                    if (sameNumber(r, c) && sameNumber(r, c+1)
                        && checkRow(r) && checkCol(c) && checkCol(c+1))
                    {
                        if (Domino(nr, nc))
                            return true;
                    }
                    usedDomino[a][b] = false;
                    dominoId--;
                    array[r][c] = -1;
                    array[r][c+1] = -1;
                    dominoMap[r][c] = dominoMap[r][c+1] = -1;
                }
            }
        }
    }
    if (r + 1 < ROWS && avCells[r+1][c] && array[r+1][c] == -1) {
        for (int a = 0; a < 7; a++){
            for (int b = a; b < 7; b++){
                if (usedDomino[a][b])
                    continue;
                array[r][c] = a;
                array[r+1][c] = b;
                dominoMap[r][c] = dominoMap[r+1][c] = dominoId++;
                usedDomino[a][b] = true;
                
                if (sameNumber(r, c) && sameNumber(r+1, c)
                    && checkRow(r) && checkRow(r+1) && checkCol(c))
                {
                    if (Domino(nr, nc))
                        return true;
                }
                usedDomino[a][b] = false;
                dominoId--;
                array[r][c] = -1;
                array[r+1][c] = -1;
                dominoMap[r][c] = dominoMap[r+1][c] = -1;     
                if (a != b) {
                    array[r][c] = b;
                    array[r+1][c] = a;
                    dominoMap[r][c] =dominoMap[r+1][c] = dominoId++;
                    usedDomino[a][b] = true;
                    
                    if (sameNumber(r, c) && sameNumber(r+1, c)
                        && checkRow(r) && checkRow(r+1) && checkCol(c))
                    {
                        if (Domino(nr, nc))
                            return true;
                    }
                    usedDomino[a][b] = false;
                    dominoId--;
                    array[r][c] = -1;
                    array[r+1][c] = -1;
                    dominoMap[r][c] = dominoMap[r+1][c] = -1;
                }
            }
        }
    }
    return false;
}   
void printDomino() {
    cout << "Рішення:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (!avCells[i][j]) {
                cout << "    ";
                continue;
            }
            int id = dominoMap[i][j];
            bool up = (i == 0 || !avCells[i - 1][j] || dominoMap[i - 1][j] != id);
            if (up) cout << "+---";
            else cout << "    ";
        }
        cout << "\n";
        for (int j = 0; j < COLS; ++j) {
            if (!avCells[i][j]) {
                cout << "    ";
                continue;
            }
            int id = dominoMap[i][j];
            bool left = (j == 0 || !avCells[i][j - 1] || dominoMap[i][j - 1] != id);
            cout << (left ? "|" : " ");

            if (array[i][j] == -2) {
                cout << "   ";
            } else {
                cout << " " << array[i][j] << " ";
            }
        }
        int last = -1;
        for (int j = COLS - 1; j >= 0; --j) {
            if (avCells[i][j]) {
                last = j;
                break;
            }
        }
        if (last != -1 && last == COLS - 1 ) {
            cout << "|";
        }

        cout << "\n";
    }
    for (int j = 0; j < COLS; ++j) {
        if (!avCells[ROWS - 1][j]) {
            cout << "    ";
            continue;
        }
        bool down = (ROWS - 1 == ROWS - 1 || !avCells[ROWS - 1 + 1][j] || dominoMap[ROWS - 1][j] != dominoMap[ROWS - 1][j]);
        if (down) cout << "+---";
        else cout << "    ";
    }
    for (int j = COLS - 1; j >= 0; --j) {
        if (avCells[ROWS - 1][j]) {
            cout << "+\n";
            break;
        }
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
    specificValues();
    initializeStartArray();
    if (Domino(0, 0)) {
        printDomino();   
    } else {
        cout << "No solution\n";
    }
    return 0;
}
