
#ifndef Personaje_h
#define Personaje_h
using namespace std;

class Personaje{
    public:
        Personaje();
        Personaje(string, int);
        string getNombre();
        int getNivel();
        void setNivel(int);
        void setNombre(string);
        void correr();
        void saltar();
        void imprime();
        virtual void use();
        
    protected:
        string Nombre;
        int Nivel;
    
};

Personaje::Personaje(){
    Nombre= "-";
    Nivel = 0;
}

Personaje::Personaje(string name, int lvl){
    Nombre= name;
    Nivel= lvl;
}

//Getters
string Personaje::getNombre(){
    return Nombre;
}

int Personaje::getNivel(){
    return Nivel;
}

//Setters
void Personaje::setNombre(string name){
    Nombre= name;
}

void Personaje::setNivel(int lvl){
    Nivel= lvl;
}

void Personaje::saltar(){
    cout << "Saltar" << endl;
}

void Personaje::correr(){
    cout << "Correr" << endl;
}

//Funcion imprimir
void Personaje::imprime(){
    cout << "Personaje" << endl << "Nombre: " << Nombre << endl;
    cout << "Nivel: " << Nivel << endl;
}
#endif /* Personaje_h */
