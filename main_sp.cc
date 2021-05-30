

#include <iostream>
#include "Personaje.h"
#include "Hechicera.h" 
#include "Vikingo.h"
#include "Arquero.h"
using namespace std;
#include <vector>

int main(){
    vector <Personaje*> vecPersonajes;
    Personaje *clasesPersonajes;

    clasesPersonajes = new Hechicera(0,0,"",100);
    vecPersonajes.push_back(clasesPersonajes);
    clasesPersonajes = new Arquero(0,0,"",100);
    vecPersonajes.push_back(clasesPersonajes);
    clasesPersonajes = new Vikingo(0,0,"",100);
    vecPersonajes.push_back(clasesPersonajes);

    for (int i=0; i<vecPersonajes.size();i++){
        vecPersonajes[i]->shoot();
    }

    return 0;
}