#ifndef __certification_lifeGame_H__
#define __certification_lifeGame_H__

struct LifeGame {
    LifeGame(int row, int col);
    void initByRandom(); 
    void show();
    void initFormInput(int** source);//for test
    int status(int row, int col);//for test
    void print();//for debug
    ~LifeGame();

private:
    int neighbour(int row, int col);
    void showSignal();
    void remaind();
    void swap();
    void initEdge();
    void initCoreFormInput(int** source);//for test
    void initCoreByRandom();
    void backup();

private:
    int row_;
    int col_;
    int** firArea_;
    int** secArea_;
};
#endif