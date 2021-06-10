#include <iostream>
#include <vector>
#include "Personaje.h"
#include "Hechicera.h" 
#include "Vikingo.h"
#include "Arquero.h"
#include "Troll.h"
#include "Dragon.h"
#include <time.h>
using namespace std;


int getRand(int n) {
    return (rand() % n) + 1;
}

//Peleas
void isDragonHere(string mapa[][8],int Col, int Ren, Personaje* d, Personaje* player){
    if (mapa[1][5] == "o" && d->getHP()>0)  {
        cout << endl << "Cuidado! "<< endl;
        cout << "Te haz encontrado con el dragon "<< endl;
        int hits = 3;
        int golpe = 0;
        while (d->getHP()>0 && player->getHP()>0){
            //Curacion del fenix
            if (player->getMascota()==1){
                cout << "Cuentas con tu fenix que te ayudara a derrotar al dragon" << endl;
                player->setHP(player->getHP()+20);
                cout << player->getHP();
            } 
            //Golpe de Dragon
            golpe= getRand(40);
            player->setHP(player->getHP()-golpe);
            d->shoot(golpe);
            //Golpe jugador
            golpe=getRand(20);
            d->setHP(d->getHP()-golpe);
            player->shoot(golpe);
            //cout << player->getHP();
        }
        player->setProgreso(20);
        if (player->getHP()>0){
            cout << "Haz sobrevivido al ataque del dragon!"  << endl;
            cout << "Ahora tienes " << player->getHP() << " de vida" << endl;
        }
        
    } 
}

void isTrollHere(string mapa[][8],int Col, int Ren, Personaje* t, Personaje* player){
    if (mapa[5][5] == "o" && t->getHP()>0)  {
        cout << endl << "Cuidado! "<< endl;
        cout << "Te haz encontrado con un troll "<< endl;
        int hits = 3;
        int golpe = 0;
        while (t->getHP()>0 && player->getHP()>0){
            //Golpe de troll
            golpe= getRand(20);
            int vidaplayer= player->getHP();
            player->setHP(vidaplayer-golpe);
            t->shoot(golpe);
            //Golpe jugador
            golpe=getRand(30);
            int vidatroll= t->getHP();
            t->setHP(vidatroll-golpe);
            player->shoot(golpe);
            t->getHP();
            // cout << t->getHP() << endl;
            // cout << player->getHP() << endl;
        }
        player->setProgreso(20);
        //player->setHP(0);
        cout << "Haz sobrevivido al ataque del troll y quedaste con " << player->getHP() << " de vida! " << endl;
    }

    else if (mapa[5][5] == "o" && t->getHP()<=0){
        cout << endl << "Ya no hay nada aquí, has matado al troll" << endl;
    }
}


void isFenixHere(string mapa[][8],int Col, int Ren, Personaje* player){
    int resp;
    if (mapa[5][6] == "o" && player->getMascota()==0){
        cout << endl << "Te haz encontrado con un fenix"<< endl;
        cout << "Deseas agarrarlo?" << endl << "[1]Si [2]No "<< endl;
        cin >> resp;
        if (resp==1){
            player->setMascota(1);
            cout << "Haz agarrado un fenix" << endl;
        }
        else{
            cout << "Sigue tu camino" << endl;
        }
    }
        
    else if (mapa[5][6] == "o"){
        cout << "Ya agarraste lo que habia aqui" << endl;
    }
}

void isKeyHere(string mapa[][8],int Col, int Ren, Personaje* player, Items* llave){
    int respuesta;
    if (mapa[3][5] == "o" && llave->getDisponibilidad()==1){
        cout << "Haz encontrado una llave! Deseas agarrarla? [1]Si [2]No" << endl;
        cin >> respuesta;
        if (respuesta==1){
            player->AdicionaLlave(llave); 
            llave->setDisponibilidad(0);
        }
        else{
            cout << "Continua tu camino" << endl;
        }

            
    }
    else if (mapa[3][5]=="o"){
        cout << "Ya agarraste lo que habia aqui" << endl;
    }
    //player->showInventario();
}



void ganarCofre(string mapa[][8],int Col, int Ren, Personaje* player, Items* llave){
    if (mapa[0][7] == "o" && llave->getDisponibilidad()==0){
        cout << "¡Encontraste el tesoro y tienes la llave!" << endl;
        cout << "HAS GANADO" << endl;
        player->setProgreso(100);
    }
    else if (mapa[0][7]=="o"){
        cout << "No tienes la llave y no puedes abrir el cofre, sigue tu camino" << endl;
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
    cout << "  ------------------ " << endl;
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
    int opcion=1;
    int i=0;
    string nombre;
    srand(time(0));
    // MoverNorte(Mapa,Col,Ren);
    // MoverEste(Mapa,Col,Ren);
    // MoverOeste(Mapa,Col,Ren);
    // MoverSur(Mapa,Col,Ren);
    // imprimirMapa(mapa);
    string Mapa[8][8]={
        {"-","-","-","-","-","X","X","X"},
        {"-","-","-","X","X","X","-","-"},
        {"-","X","X","X","-","-","-","-"},
        {"-","X","-","-","-","X","X","X"},
        {"X","X","X","X","X","-","-","X"},
        {"-","-","X","X","X","X","X","X"},
        {"-","-","X","-","-","-","-","-"},
        {"X","o","X","-","-","-","-","-"},
    };
    int Ren=7, Col=1, posicion=0; 
    Personaje *t = new Troll();
    Personaje *a = new Arquero();
    Personaje *h = new Hechicera();
    Personaje *v = new Vikingo();
    Personaje *player;
    Personaje *d = new Dragon();

    cout << "Que personaje desea usar? [1]Arquero [2]Hechicero [3]Vikingo" << endl;
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
    /*cout << "Cómo quieres que se llame tu personaje?" << endl;
    cin >> nombre;
    player->setNombre(nombre);
    player->imprime();*/
    cout << player->getHP();
    Items *llaveRecolectada = new Key();   
    ganarCofre(Mapa, Col, Ren, player, llaveRecolectada);
    while (player->getProgreso()!=100 && player->getHP()>0){
        if (Mapa[2][3]=="o"){
            player->LeerCartel();
        }
        isFenixHere(Mapa,Col, Ren, player);
        isKeyHere(Mapa,Col, Ren, player, llaveRecolectada);

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
        isTrollHere(Mapa,Col, Ren, t, player);
        isDragonHere(Mapa,Col, Ren, d, player);
        if (player->getHP()>0){
            ganarCofre(Mapa, Col, Ren, player, llaveRecolectada);
            }
        else {
            cout << "Haz muerto, gracias por jugar" << endl;
        }
    }

    return 0;
}