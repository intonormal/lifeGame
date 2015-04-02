#include "lifeGame.h"
#include "macro.h"
#include "memory.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define STARTLOOP(f, fb, fe, s, sb, se)\
for(f = fb; f<=fe; f++) {              \
    for(s = sb; s<= se; s++) {

#define ENDLOOP \
    }           \
}

#define ENDLOOPWITHDIV \
    }                       \
    std::cout<<std::endl;   \
}

LifeGame::LifeGame(int row, int col) : row_(row + 2), col_(col + 2) {
    firArea_ = setArea(row_, col_);
    secArea_ = setArea(row_, col_);
}

void LifeGame::initFormInput(int** source) {
    initEdge();
    initCoreFormInput(source);
    backup();
}

void LifeGame::initByRandom() {
    initEdge();
    initCoreByRandom();
    backup();
}

void LifeGame::initEdge() {
    for(int c = 0; c <= col_ - 1; c++) {
        firArea_[0][c] = 0;            
        firArea_[row_ - 1][c] = 0;            
    }

    for(int r = 0; r <= row_ - 1; r++) {
        firArea_[r][0] = 0;            
        firArea_[r][col_ - 1] = 0;            
    }
}

void LifeGame::initCoreFormInput(int** source) {
    int r, c;
    STARTLOOP(r, 1, row_ - 2, c, 1, col_ - 2)
            firArea_[r][c] = source[r - 1][c - 1];
            secArea_[r][c] = 0;
    ENDLOOP
}

void LifeGame::initCoreByRandom() {
    srand((unsigned)time(NULL));
    int r, c;
    STARTLOOP(r, 1, row_ - 2, c, 1, col_ - 2)
        firArea_[r][c] = rand()%2;
        secArea_[r][c] = 0;    
    ENDLOOP
}

void LifeGame::backup() {
    int r, c;
    STARTLOOP(r, 0, row_ - 1, c, 10, col_ - 1)
        secArea_[r][c] = firArea_[r][c];
    ENDLOOP
}

LifeGame::~LifeGame() {
    clearArea(firArea_, row_); 
    clearArea(secArea_, row_); 
}
//////////////////////////////////////////////////////////////////////////
int LifeGame::neighbour(int row, int col) {
    int r, c, result = 0;
    STARTLOOP(r, row - 1, row + 1, c, col - 1, col + 1)
        result += firArea_[r][c];
    ENDLOOP

    return result - firArea_[row][col];
}

int LifeGame::status(int row, int col) {
    return (neighbour(row + 1, col + 1) == 3) 
            || ((neighbour(row + 1, col + 1) == 2 && firArea_[row + 1][col + 1] == 1));
}

void LifeGame::show() {
    do {
        showSignal();
        remaind();
        swap();
        system("cls");
    }while (1);
}

void LifeGame::showSignal() {
    int r, c;
    STARTLOOP(r, 1, row_ - 2, c, 1, col_ - 2)
        std::cout<<(firArea_[r][c] == 1 ? "$" : " ");
    ENDLOOPWITHDIV
}

void LifeGame::remaind() {
    int r, c;
    STARTLOOP(r, 1, row_ - 2, c, 1, col_ - 2)
        secArea_[r][c] = status(r-1, c-1);
    ENDLOOP
}

void LifeGame::swap() {
    int r, c;
    STARTLOOP(r, 1, row_ - 2, c, 1, col_ - 2)
        firArea_[r][c] = secArea_[r][c];
    ENDLOOP
}

void LifeGame::print() {
    int r, c;
    STARTLOOP(r, 0, row_ - 1, c, 0, col_ - 1)
        std::cout<<firArea_[r][c];
    ENDLOOPWITHDIV
}
