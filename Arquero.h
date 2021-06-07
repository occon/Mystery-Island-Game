#ifndef Arquero_h
#define Arquero_h
#include "Personaje.h"

class Arquero: public Personaje{
    public:
        Arquero();
        Arquero(int, int, string, int);
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

Arquero::Arquero(): Personaje(){
    arma= 0;
}

Arquero::Arquero(int weapon, int pet, string n, int healthp): Personaje(n, healthp){
    arma = weapon;
    mascota = pet;
    Nombre= n;
    HP = healthp;
}
//Getters
int Arquero::getArma(){
    return arma; 
}

int Arquero::getMascota(){ 
    return mascota; 
}

//Setters
void Arquero::setArma(int weapon){
    arma = weapon;
} 

void Arquero::setMascota(int pet){
    mascota = pet;
}

//Funciones

void Arquero::shoot(){ 
    cout << "Tirar flechas" << endl;
}

#endif /* Arquero_h */
