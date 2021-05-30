#ifndef Troll_h
#define Troll_h
#include "Troll.h"

class Troll: public Personaje{
    public:
        Troll();
        Troll(int, string, int);
        int getArma();
        void setArma(int);
        void setMascota(int);
        void shoot();
    private:
        int arma;
};

//Getters

Troll::Troll(): Personaje(){
    arma= 0;
}

Troll::Troll(int weapon, string n, int healthp): Personaje(n, healthp){
    arma = weapon;
    Nombre= n;
    HP = healthp;
}
//Getters
int Troll::getArma(){
    return arma; 
}



//Setters
void Troll::setArma(int weapon){
    arma = weapon;
} 


void Troll::shoot(){ 
    cout << "Tirar golpe" << endl;
}

#endif /* Troll_h */
