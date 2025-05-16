#include <iostream>
#include <vector>
using namespace std;
const int ROWS1 = 7;
const int COLS1 = 8;
int array1[ROWS1][COLS1] = {
    {4,6,2,5,5,2,0,1},
    {0,4,4,0,0,1,6,3},
    {2,4,4,1,1,3,1,5},
    {2,5,0,2,2,2,0,0},
    {5,3,3,6,4,1,3,5},
    {1,4,1,4,5,6,6,5},
    {6,6,3,0,3,3,6,2}
};
void printStart1(){
    cout<<"     Початкове поле          "<< endl;
    cout << "+--------------------------------+" << endl;
    for (int i = 0; i < 7; i++) {
        cout<<endl;
        cout << "|"; 
        for (int j = 0; j < 8; j++) {
            cout << "  " << array1[i][j] << " ";
        }
        cout << "|" << endl; 
    }
    cout << "+--------------------------------+" << endl;
}
bool usedCell[ROWS1][COLS1] = {};
bool usedDomino1[7][7] = {};
int dominoId1 = 1;
int dominoMap1[ROWS1][COLS1] = {};
int isValid(int r, int c) {
    return r >= 0 && r < ROWS1 && c >= 0 && c < COLS1 && !usedCell[r][c];
}
bool Domino1(int r, int c) {
    if (r == ROWS1) {
        return true;
    }
    if (c == COLS1){ 
        return Domino1(r + 1, 0);
    }
    if (usedCell[r][c]){
        return Domino1(r, c + 1);
    }
    int a = array1[r][c];
    usedCell[r][c] = true;
    if (isValid(r, c + 1)) {
        int b = array1[r][c + 1];
        int x = min(a, b), y = max(a, b);
        if (!usedDomino1[x][y]) {
            usedDomino1[x][y] = true;
            usedCell[r][c + 1] = true;
            dominoMap1[r][c] = dominoId1;
            dominoMap1[r][c + 1] = dominoId1;
            dominoId1++;
            if (Domino1(r, c + 2)){
                return true;
            }
            dominoId1--;
            usedDomino1[x][y] = false;
            usedCell[r][c + 1] = false;
        }
    }
    if (isValid(r + 1, c)) {
        int b = array1[r + 1][c];
        int x = min(a, b), y = max(a, b);
        if (!usedDomino1[x][y]) {
            usedDomino1[x][y] = true;
            usedCell[r + 1][c] = true;
            dominoMap1[r][c] = dominoId1;
            dominoMap1[r + 1][c] = dominoId1;
            dominoId1++;
            if (Domino1(r, c + 1)){
                return true;
            }
            dominoId1--;
            usedDomino1[x][y] = false;
            usedCell[r + 1][c] = false;
        }
    }

    usedCell[r][c] = false;
    return false;
}
void printDomino1() {
    cout << "\nСписок доміно:\n\n";
    struct Domino {
        int a = -1;
        int b = -1;
    };
    vector<Domino> dominos(dominoId1); 
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            int id = dominoMap1[i][j];
            if (id > 0) {
                if (dominos[id].a == -1)
                    dominos[id].a = array1[i][j];
                else
                    dominos[id].b = array1[i][j];
            }
        }
    }
    int count = 0;  
    cout<<"---------  ---------  ---------  ---------  ---------  ---------  ---------"<<endl;
    for (int i = 1; i < dominoId1; i++) {
        cout << "| " << dominos[i].a << " | " << dominos[i].b << " |  ";
        count++;
        if (count % 7 == 0) cout<<endl<<"---------  ---------  ---------  ---------  ---------  ---------  ---------"<< endl;
    }
    cout << endl;
}
void printResult() {
    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            int id = dominoMap1[i][j];
            bool up = (i == 0 || dominoMap1[i - 1][j] != id);
            if (up) cout << "+---";
            else cout << "    ";
        }
        cout << "+\n";
        for (int j = 0; j < COLS1; ++j) {
            int id = dominoMap1[i][j];
            bool left = (j == 0 || dominoMap1[i][j - 1] != id);
            bool right = (j == COLS1 - 1 );
            if (left) {
                cout << "| ";
            } else {
                cout << "  ";
            }
            cout << array1[i][j];
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
void printStart(){
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
    cout << " 4     1     3      3     1     2"<<endl<<endl;
    cout << " 6     5     6      6     5     3"<<endl<<endl;
    cout << "                                4"<<endl<<endl;
}
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
            if (left) {
                cout << "|";
            } else {
                 cout << " ";
            }
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
    printStart1();
    Domino1(0,0);
     cout<<"     Розвязок завдання з доміно          "<< endl;
    printResult();
    printDomino1();
    printStart();
    specificValues();
    initializeStartArray();
    if (Domino(0, 0)) {
        printDomino();   
    } else {
        cout << "No solution\n";
    }
    return 0;
}
