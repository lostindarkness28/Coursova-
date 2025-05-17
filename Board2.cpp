#include "Board2.h"
bool Board2::avCells[ROWS][COLS] = {
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
bool Board2::rowDigits[ROWS][7] = {false};
bool Board2::colDigits[COLS][7] = {false};
bool Board2::specificRow[ROWS] = {false};
bool Board2::specificCol[COLS] = {false};
Board2::Board2() {
    dominoId = 1;
    for (int i = 0; i < ROWS; ++i){
        for (int j = 0; j < COLS; ++j) {
            if (avCells[i][j]) {
                array[i][j] = -1;
                dominoMap[i][j] = -1;
            } else {
                array[i][j] = -2;
                dominoMap[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            usedDomino[i][j] = false;
    
    specificValues();
}
void Board2::specificValues() {
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
void Board2::initializeStartArray() {
    dominoId = 1;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
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
bool Board2::sameNumber(int r, int c) {
    int d = array[r][c];
    if (r > 0 && avCells[r-1][c] && dominoMap[r-1][c] != -1 && dominoMap[r-1][c] != dominoMap[r][c]){
         if (array[r-1][c] != d){ 
            return false;
        }
    }
    if (r < ROWS-1 && avCells[r+1][c] && dominoMap[r+1][c] != -1 && dominoMap[r+1][c] != dominoMap[r][c]){
         if (array[r+1][c] != d){
            return false;
        }
    }
    if (c > 0 && avCells[r][c-1] && dominoMap[r][c-1] != -1 && dominoMap[r][c-1] != dominoMap[r][c]){
         if (array[r][c-1] != d){ 
            return false;
        }
    }
    if (c < COLS-1 && avCells[r][c+1] && dominoMap[r][c+1] != -1 && dominoMap[r][c+1] != dominoMap[r][c]){
         if (array[r][c+1] != d){
            return false;
        }
    }
    return true;
}
bool Board2::checkRow(int r){
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
        return true;
    }
    for(int d=0;d<7;d++){
        if(rowDigits[r][d]&&!found[d]){
            return false;
        }
    }
    return true;
}
bool Board2::checkCol(int c){
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
void Board2::nextCell(int r, int c, int &nr, int &nc) {
    nc = c + 1;
    nr = r;
    if (nc >= COLS) {
        nr = r + 1;
        nc = 0;
    }
}
