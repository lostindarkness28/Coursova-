#include <iostream>
using namespace std;
const int ROWS = 7;
const int COLS = 8;
int array[ROWS][COLS] = {
        {4,6,2,5,5,2,0,1},
        {0,4,4,0,0,1,6,3},
        {2,4,4,1,1,3,1,5},
        {2,5,0,2,2,2,0,0},
        {5,3,3,6,4,1,3,5},
        {1,4,1,4,5,6,6,5},
        {6,6,3,0,3,3,6,2}
};
bool usedDomino[ROWS][COLS] = {};
int dominoId = 1;
int dominoMap[ROWS][COLS] = {};
int isValid(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS && !usedDomino[r][c];
}
int Domino(int r,int c){
    if(r==ROWS){
        return 1;
    }
    if (c==COLS){
        return Domino(r + 1, 0);
    }
    if (usedDomino[r][c]) return Domino(r, c + 1);
    int a = array[r][c];
    usedDomino[r][c] = true;
    cout<<"Комірка ["<<r<<"]["<<c<<"]="<<a<<endl;
    return Domino(r, c + 1);
}
int main(){
    
    cout<<"     Початкове поле          "<< endl;
    cout << "+------------------------+" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "|"; 
        for (int j = 0; j < 8; j++) {
            cout << " " << array[i][j] << " ";
        }
        cout << "|" << endl; 
    }
    cout << "+------------------------+" << endl;
    Domino(0,0);
    return 0;
}