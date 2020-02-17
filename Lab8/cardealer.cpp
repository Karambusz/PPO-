#include "cardealer.h"
#include<iostream>
int SubaruDealer::n;

SubaruDealer::SubaruDealer(int size){
    _size=size;
    _index=0;
    _suma=0;
    n=0;
    salon = new SubaruCar[_size];
}


void SubaruDealer::new_inventory(SubaruCar car, int numer, int cena){
    if(_index<_size){
    salon[_index]=car;
    salon[_index]._numer=numer;
    salon[_index]._cena=cena;
    _index++;
    }else
    {
        std::cout<<"SubaruDealer: No place for more cars."<<std::endl;
    }
    
}

SubaruCar * SubaruDealer::show(int numer){
    for(int i=0; i<_index; i++){
        if(salon[i]._numer==numer){
            return &salon[i];
        }
    }
    return nullptr;
}


void SubaruDealer::sell(int numer){
    SubaruCar *car = show(numer);
    if(car){
        car->_numer=0;
        _suma=_suma+car->_cena;
        n=n+car->_cena;
    }else
    {
        std::cout<<"SubaruDealer: no such car."<<std::endl;
        return;
    }
    
}

int SubaruDealer::get_income(){
    return _suma;
}

int SubaruDealer::get_all_dealers_income(){
    return n;
}