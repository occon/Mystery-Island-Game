#include <iostream>
using namespace std;

class Mapa{
    Mapa();
};

Mapa::Mapa(){
    string matriz[10][10];
    int tamRen = 8, tamCol = 8;
    
    // cout << "Cantidad de renglones ";
    // cin >> tamRen;
    // cout << "Cantidad de columnas ";
    // cin >> tamCol;
    
    for (int ren = 0; ren < tamRen; ren++) {
        for (int col = 0; col < tamCol; col++) {
            // cout << "Elemento [" << ren << "][" << col << "] = ";
            // cin >> matriz[ren][col];
            matriz[ren][col] = "-";
        }
    }

    matriz[7][0] = "x";
    matriz[7][1] = "x";
    matriz[7][2] = "x";
    matriz[6][2] = "x";
    matriz[5][2] = "x";
    matriz[5][3] = "x";
    matriz[5][4] = "x";
    matriz[5][5] = "x";
    matriz[5][6] = "x";
    matriz[5][7] = "x";
    matriz[4][4] = "x";
    matriz[4][3] = "x";
    matriz[4][2] = "x";
    matriz[4][1] = "x";
    matriz[4][0] = "x";
    matriz[4][7] = "x";
    matriz[3][7] = "x";
    matriz[3][6] = "x";
    matriz[3][1] = "x";
    matriz[2][1] = "x";
    matriz[2][2] = "x";
    matriz[2][3] = "x";
    matriz[1][3] = "x";
    matriz[1][4] = "x";
    matriz[1][5] = "x";
    matriz[0][5] = "x";
    matriz[0][6] = "x";

    for (int ren = 0; ren < tamRen; ren++) {
        for (int col = 0; col < tamCol; col++) {
            cout << matriz[ren][col] << "  ";
        }
        cout << endl ;
    }
}