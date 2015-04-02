#include "memory.h"

int** setArea(int row, int col) {
    int** p = new int*[row];
    for(int i = 0; i < row; i++)
        p[i] = new int[col];
    return p;        
}

void clearArea(int** area, int row) {
    for(int i = 0; i < row; i++)
        delete [] area[i];
    delete [] area;
}
