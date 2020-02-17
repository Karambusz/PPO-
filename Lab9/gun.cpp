#include <iostream>
#include "gun.h"


Gun::Gun(int size, double caliber){
    _size=size;
    _index=0;
    _caliber=caliber;
    magazyn = new Bullet *[_size];
    for(int i=0; i<_size; i++){
        magazyn[i]=new Bullet(_caliber);
        _index++;
    }
}

Gun::~Gun(){
    if(magazyn){
        for(int i=0; i<_index; i++){
            delete magazyn[i];
        }
        delete [] magazyn;
    }
    if(komora){
        delete komora;
    }
}

Gun::Gun(const Gun &tmp){
    _size=tmp._size;
    _index=tmp._index;
    _caliber=tmp._caliber;
    magazyn=new Bullet *[_size];
    for(int i=0; i<_index; i++){
        magazyn[i]= new Bullet(tmp._caliber); 
    }
    for(int i=_index; i<_size; i++){
        magazyn[i]=nullptr;
    }
    if(tmp.komora){
        komora = new Bullet();
    }else
    {
        komora=nullptr;
    }
    std::cout<<"Copy konstruktor!"<<std::endl;
    
}

Gun::Gun(Gun &&tmp){
    _size=tmp._size;
    _index=tmp._index;
    _caliber=tmp._caliber;
    magazyn=tmp.magazyn;
    komora=tmp.komora;
    tmp._size=0;
    tmp._index=0;
    tmp._caliber=0;
    tmp.magazyn=nullptr;
    tmp.komora=nullptr;
    std::cout<<"Move konstruktor!"<<std::endl;

}

void Gun::load(){
    if(_index>0){
    komora = new Bullet(_caliber);
    delete magazyn[_index-1];
    _index--;
    }else
    {
        mag_empty();
    }
    
}

void Gun::pull_trigger(){
    if(komora){
        bang();
        delete komora;
        komora=nullptr;
    }else
    {
        chamb_empty();
    }
    
}

void Gun::pull_trigger(int a){
    if(a<=_size){
        for(int i=0; i<a; i++){
            load();
            pull_trigger();
        }
    }
}


void Gun::new_magazine(){
    for(int i=0; i<_size; i++){
        magazyn[i]=new Bullet(_caliber);
        _index++;
    }
}