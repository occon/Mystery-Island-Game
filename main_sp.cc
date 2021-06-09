#include <iostream>
#include <vector>
#include "Personaje.h"
#include "Hechicera.h" 
#include "Vikingo.h"
#include "Arquero.h"
#include "Troll.h"

using namespace std;

void mostrarmapa(int tamRen, int tamCol, string mapa[tamRen][tamCol]){
    
    // cout << "Cantidad de renglones ";
    // cin >> tamRen;
    // cout << "Cantidad de columnas ";
    // cin >> tamCol;
    
    for (int ren = 0; ren < tamRen; ren++) {
        for (int col = 0; col < tamCol; col++) {
            // cout << "Elemento [" << ren << "][" << col << "] = ";
            // cin >> mapa[ren][col];
            mapa[ren][col] = "-";
        }
    }

    mapa[7][0] = "x";mapa[7][1] = "x";mapa[7][2] = "x";mapa[6][2] = "x";mapa[5][2] = "x";mapa[5][3] = "x";mapa[5][4] = "x";mapa[5][5] = "x";
    mapa[5][6] = "x";mapa[5][7] = "x";mapa[4][4] = "x";mapa[4][3] = "x";mapa[4][2] = "x";mapa[4][1] = "x";mapa[4][0] = "x";mapa[4][7] = "x";
    mapa[3][7] = "x";mapa[3][6] = "x";mapa[3][1] = "x";mapa[2][1] = "x";mapa[2][2] = "x";mapa[2][3] = "x";mapa[1][3] = "x";mapa[1][4] = "x";
    mapa[1][5] = "x";mapa[0][5] = "x";mapa[0][6] = "x";

    for (int ren = 0; ren < tamRen; ren++) {
        for (int col = 0; col < tamCol; col++) {
            cout << mapa[ren][col] << "  ";
        }
        cout << endl ;
    }
    // return mapa[tamRen][tamCol];
}

// void norte(){
//     // mapa();

//      for (int ren = 0; ren < tamRen; ren++) {
//         for (int col = 0; col < tamCol; col++) {
//             cout << mapa[ren][col].mapa() << "  ";
//         }
//     } 
// }

int main(){
    int opcion;
    string nombre;
    vector <Personaje*> vecPersonajes;
    Personaje *clasesPersonajes;
    int tamRen = 8, tamCol = 8;
    string Matrizmapa[tamRen][tamCol];
    //mostrarmapa(Matrizmapa, tamRen, tamCol);
    //Troll  
    Personaje *t = new Troll();
    Personaje *a = new Arquero();
    Personaje *h = new Hechicera();
    Personaje *v = new Vikingo();
    Personaje *player;
    cout << "Que personaje desea usar? [1]Arquero [2]Hechicero [3]Vikingo" << endl;
    cin >> opcion;
    if (opcion==1){
        player = a;
    }
    else if (opcion==2){
        player = h;
    }
    else if (opcion==3){
         player = v;
    }
    cout << "Como quieres que se llame tu personaje?" << endl;
    cin >> nombre;
    player->setNombre(nombre);
    player->imprime();



    // mapa();
    // Mapa::Mapa();
    
    return 0;
}