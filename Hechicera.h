#ifndef Hechicera_h
#define Hechicera_h
#include "Personaje.h"

class Hechicera: public Personaje{
    public:
        Hechicera();
        Hechicera(int, int, string, int);
        int getArma();
        void setArma(int);
        void shoot();
    private:
        int arma;
        int mascota;
};

//Getters

Hechicera::Hechicera(): Personaje(){
    arma= 0;
}

Hechicera::Hechicera(int weapon, int pet, string n, int healthp): Personaje(n, healthp, pet){
    arma = weapon;
    mascota = pet;
    Nombre= n;
    HP = healthp;
}
//Getters
int Hechicera::getArma(){
    return arma; 
}


//Setters
void Hechicera::setArma(int weapon){
    arma = weapon;
} 


void Hechicera::shoot(){ 
    cout << "Disparar hechizos" << endl;
}

#endif /* Hechicera_h */
