//
//  ItemKey.h
//  Tarea 04 
//  
//  Created by Lydia Delgado uriarte & Hugo Edgar Palomares Estrella on 01/06/21.
//

#include "Items.h"


class Key:public Items{
    public:
        Key();
        Key(int,int, string, string, int);
        void use();
    private:
        int KeyType; // {Health, Energy, Wisdom, Death}
};

Key::Key() : Items(){
    KeyType = 0;
};
Key::Key(int p, int lvl, string n, string descr, int healthp):Items(lvl,n,descr,healthp){ 
    KeyType= p;
    
}
void Key::use(){
    cout << "Acabas de agarrar una LLAVE, usala para abrir el tesoro" << endl;
}