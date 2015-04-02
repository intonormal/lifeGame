#include "userInterface.h"
#include "lifeGame.h"
#include <iostream>
#include <string>
#include <fstream>
#include "memory.h"


void lifeGameWithRandomInitData() {
    int row, col;
    std::cout<<"please input row(>0) and col(>0) of cellPic"<<std::endl;
    std::cin>>row>>col;

    LifeGame object(row, col);
    object.initByRandom();
    object.show();
}

//getRow()
//getCol()
//
//
//void lifeGameWithImportInitDataFromFile() {
//    int row, col;
//    std::cout<<"please input row(>0) and col(>0) of cellPic"<<std::endl;
//    std::cin>>row>>col;
//
//    LifeGame object(row, col);
//
//    std::string filePath= "E:\exercise\LifeGameForCertification\initalData.txt";
//    /*std::cout<<"please input file-path with init data"<<std::endl;
//    std::cin>>filePath;*/
//        
//    int** initalStatus = setArea(row, col);
//    for(int i=0; i<row; i++) {
//        for(int j=0; j<col; j++) {
//            initalStatus[i][j] = 0;
//        }
//    }
//
//    std::ifstream fin(filePath.c_str());
//    char c;
//    for(int i=0; i<row; i++) {
//        for(int j=0; j<col; j++) {
//            fin.get(c);
//            std::cout<<c<<std::endl;
//            fin>>initalStatus[i][j];
//        }
//    }
//    fin.close();
//    object.print();
//
//    object.initFormInput(initalStatus);
//    object.show();
//}