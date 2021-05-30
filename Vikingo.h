#ifndef Vikingo_h
#define Vikingo_h
#include "Personaje.h"

class Vikingo: public Personaje{
    public:
        Vikingo();
        Vikingo(int, int, string, int);
        int getArma();
        int getMascota();
        void setArma(int);
        void setMascota(int);
        void shoot();
    private:
        int arma;
        int mascota;
};

//Getters

Vikingo::Vikingo(): Personaje(){
    arma= 0;
}

Vikingo::Vikingo(int weapon, int pet, string n, int healthp): Personaje(n, healthp){
    arma = weapon;
    mascota = pet;
    Nombre= n;
    HP = healthp;
}
//Getters
int Vikingo::getArma(){
    return arma; 
}

int Vikingo::getMascota(){ 
    return mascota; 
}

//Setters
void Vikingo::setArma(int weapon){
    arma = weapon;
} 

void Vikingo::setMascota(int pet){
    mascota = pet;
}


void Vikingo::shoot(){ 
    cout << "Atacar con hacha" << endl;
}

#endif /* Vikingo_h */
