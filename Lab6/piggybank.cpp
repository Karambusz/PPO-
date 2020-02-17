#include<iostream>

#include "coin.h"
#include "piggybank.h"

///////////////////////////////
Piggybank::Piggybank(int rozm){
    size = rozm;
    tab = new Coin[size];
    suma = 0;
    index = 0;

}
/////////////////////////////////////
void Piggybank::put_coin(const Coin &moneta){
    if(index>=size){
        std::cout<<"Piggybank is full..."<<std::endl;
        return;
}
else{
    tab[index]=moneta;
    index++;
}
}
/////////////////////////////////////
int Piggybank::get_tot_value(){
for(int i=0; i<index; i++){
    suma=suma+tab[i].get_coin_value();
}

return suma;
}

Piggybank::~Piggybank(){

    delete [] tab;
    
}