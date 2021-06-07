#include <iostream>
#include "Personaje.h"
#include "Hechicera.h" 
#include "Vikingo.h"
#include "Arquero.h"
#include "Mapa.h"
#include <vector>
using namespace std;


void isTrollHere(string mapa[][8],int Col, int Ren, Personaje Troll){

    if (mapa[5][5] == "o" && Troll.getHP()>0)  {
        cout << endl << "Cuidado! "<< endl;
        cout << "Te haz encontrado con un troll "<< endl;
    }
}


void imprimirMapa(string Mapa[][8]){
    cout << endl << "Mapa"<< endl;
    cout << "  ------------------" << endl;
    for (int ren = 0; ren < 8; ren++) {
        cout << " | " ;
        for (int col = 0; col < 8; col++) {
            cout << Mapa[ren][col] << " ";
        }
        cout << " | " ;
        cout << endl;
    }
    cout << "  ------------------" << endl;
}

int MoverNorte(string mapa[][8], int Col, int Ren){
    if (mapa[Ren-1][Col]=="-"){
        cout << "Esta parte del mapa no es accesible" << endl;
    }
    else if(mapa[Ren-1][Col]=="X"){
        cout << "Es parte del mapa" << endl;
        mapa[Ren-1][Col]="o";
        mapa[Ren][Col]="X";
        Ren--;
    }
    else{
        cout << "No es parte del mapa" << endl;
    }
    // imprimirMapa(mapa);
    return Ren;
}

int MoverOeste(string mapa[][8], int Col, int Ren){
    if (mapa[Ren][Col-1]=="-"){
        cout << "No es parte del mapa" << endl;
    }
    else if(mapa[Ren][Col-1]=="X"){
        cout << "Es parte del mapa" << endl;
        mapa[Ren][Col-1]="o";
        mapa[Ren][Col]="X";
        Col--;
    }
    else{
        cout << "No es parte del mapa" << endl;
    }
    // imprimirMapa(mapa);
    return Col;
}

int MoverEste(string mapa[][8], int Col, int Ren){
    if (mapa[Ren][Col+1]=="-"){
        cout << "No es parte del mapa" << endl;
    }
    else if(mapa[Ren][Col+1]=="X"){
        cout << "Es parte del mapa" << endl;
        mapa[Ren][Col+1]="o";
        mapa[Ren][Col]="X";
        Col++;
    }
    else{
        cout << "No es parte del mapa" << endl;
    }
    // imprimirMapa(mapa);
    return Col;
}

// int MoverSur(string mapa[][8], int Col, int Ren){
//     if (mapa[Ren+1][Col]=="-"){
//         cout << "Esta parte del mapa no es accesible" << endl;
//     }
//     else if(mapa[Ren+1][Col]=="X"){
//         cout << "Es parte del mapa" << endl;
//         mapa[Ren+1][Col]="o";
//         mapa[Ren][Col]="X";
//         Ren++;
//     }
//     else{
//         cout << "No es parte del mapa" << endl;
//     }
//     imprimirMapa(mapa);
//     return Ren;
// }


int MoverSur(string mapa[][8], int Col, int Ren){
    if (mapa[Ren+1][Col]=="-"){
        cout << "Esta parte del mapa no es accesible" << endl;
    }
    else if(mapa[Ren+1][Col]=="X"){
        cout << "Es parte del mapa" << endl;
        mapa[Ren+1][Col]="o";
        mapa[Ren][Col]="X";
        Ren++;
    }
    else{
        cout << "No es parte del mapa" << endl;
    }
    // imprimirMapa(mapa);
    return Ren;
}

int main(){
    
    // MoverNorte(Mapa,Col,Ren);
    // MoverEste(Mapa,Col,Ren);
    // MoverOeste(Mapa,Col,Ren);
    // MoverSur(Mapa,Col,Ren);
    // imprimirMapa(mapa);
    string Mapa[8][8]={
        {"-","-","-","-","-","X","X","X"},
        {"-","-","-","X","X","X","-","-"},
        {"-","X","X","X","-","-","-","-"},
        {"-","X","-","-","-","X","X","-"},
        {"X","X","X","X","X","-","-","X"},
        {"-","-","X","X","X","X","X","X"},
        {"-","-","X","-","-","-","-","-"},
        {"X","o","X","-","-","-","-","-"},
    };
    int Ren=7, Col=1, posicion=0;

    Personaje Troll("Troll", 100);
    
    while (Mapa[0][7]!="o"){
        isTrollHere(Mapa,Col, Ren, Troll); 
        imprimirMapa(Mapa);
        cout << "A que posicion quieres moverte? [1] ^ [2] v [3] < [4] >" << endl;

        cin >> posicion;
        if (posicion==1){
            Ren = MoverNorte(Mapa,Col,Ren);
            cout << Col << " " << Ren << endl;
        }
        else if (posicion==2){
            Ren = MoverSur(Mapa,Col,Ren);
            cout << Col << " " << Ren << endl;
        }
        else if (posicion==3){
            Col = MoverOeste(Mapa,Col,Ren);
            cout << Col << " " << Ren << endl;
        }
        else if (posicion==4){
            Col = MoverEste(Mapa,Col,Ren);
            cout << Col << " " << Ren << endl;
        }
    }
    cout << "Haz ganado!" << endl;


    return 0;
}