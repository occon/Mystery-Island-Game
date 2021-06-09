#ifndef Arquero_h
#define Arquero_h
#include "Personaje.h"

class Arquero: public Personaje{
    public:
        Arquero();
        Arquero(int, int, string, int);
        int getArma();
        void setArma(int);
        void shoot();
    private:
        int arma;
};

//Getters

Arquero::Arquero(): Personaje(){
    arma= 0;
    mascota = 0;
    Nombre= "";
    HP= 0;
}

Arquero::Arquero(int weapon, int pet, string n, int healthp): Personaje(n, healthp,pet){
    arma = weapon;
    mascota = pet;
    Nombre= n;
    HP = healthp;
}
//Getters
int Arquero::getArma(){
    return arma; 
}


//Setters
void Arquero::setArma(int weapon){
    arma = weapon;
} 


//Funciones

void Arquero::shoot(){ 
    cout << "Tirar flechas" << endl;
}

#endif /* Arquero_h */
