#include "pasture.h"
#include <iostream>
#include <utility>

//operator << ktora pozwala wypisywac obiekty klasy
std::ostream &operator<<(std::ostream &o, const Pasture &K){
    o<<"area: "<<K._pole;
    o<<" sheeps:";
    for(int i=0; i<K.index; i++){
        o<<K.owieczka[i]<<" ";
    }
    return o;
 }
// Konstruktor domyślny, który zeruje pola
Pasture::Pasture(){
    _pole = 0;
    index = 0;
    owieczka = nullptr;
    //std::cout<<"Konstruktor"<<std::endl;
}



//Konstruktor z argumentami, tworzący pastwisko o zadanym boku i liczbie owiec;
Pasture::Pasture(double bok, int liczba){
    index = liczba;
    _pole = bok * bok;
    owieczka = new bool[liczba];
    for(int i=0; i<liczba; i++){
        owieczka[i]=rand()%2;
    }
   // std::cout<<index<<std::endl;
   // std::cout<<"Konstruktor"<<std::endl;
}

//Konstruktor kopiujący 
Pasture::Pasture(const Pasture &tmp){
    index = tmp.index;
    _pole = tmp._pole;
    owieczka = new bool[tmp.index];
    for(int i=0; i<index; i++){
        owieczka[i] = tmp.owieczka[i];
    }
   // std::cout<<"Konstruktor Kopiujacy"<<std::endl;
}

//Konstruktor przenoszacy
Pasture::Pasture(Pasture &&tmp){
    index = std::exchange(tmp.index, 0);
    _pole = std::exchange(tmp._pole, 0);
    owieczka = tmp.owieczka;
    tmp.owieczka = nullptr;
    //std::cout<<"Konstruktor przenoszacy"<<std::endl;

}

//Destruktor 
Pasture::~Pasture(){
    if(owieczka){
        delete [] owieczka;
    }
}

// operator dodawania
Pasture operator+(const Pasture &tmp1, const Pasture &tmp2){
    Pasture nowy;
    //int bufor = tmp1.index + tmp2.index;
    nowy.index = tmp1.index + tmp2.index;
    nowy._pole = tmp1._pole + tmp2._pole;
    nowy.owieczka = new bool[nowy.index];
    for(int i=0; i<tmp1.index; i++){
        nowy.owieczka[i] = tmp1.owieczka[i]; 
    }
    for(int i=tmp1.index; i<nowy.index; i++){
        nowy.owieczka[i] = tmp2.owieczka[i-tmp1.index]; 
    }
    //std::cout<<nowy.index<<std::endl;
    return nowy;
}

//operator *=
Pasture & Pasture::operator*=(double tmp){
    double a = _pole*tmp;
    _pole = a;
    return *this;
}

//operator *
Pasture operator*(double a, const Pasture &tmp){
    Pasture nowy(tmp);
    nowy*=a;
    return nowy;
}
//operator *
Pasture operator*(const Pasture &tmp, double a){
    Pasture nowy(tmp);
    nowy*=a;
    return nowy;
}
//operator =
Pasture & Pasture::operator=(const Pasture &tmp){
    if(this ==&tmp){
        return *this;
    }
    delete [] owieczka;
    index = tmp.index;
    _pole = tmp._pole;
    owieczka = new bool[index];
    for(int i=0; i<index; i++){
        owieczka[i] = tmp.owieczka[i];
    }
    return *this;
}

// operator () 
bool Pasture::operator() (const Pasture &tmp1, const Pasture &tmp2){
    return tmp1._pole > tmp2._pole;
}


Pasture & Pasture::operator=(Pasture &&tmp){
     index = std::exchange(tmp.index, 0);
    _pole = std::exchange(tmp._pole, 0);
    delete [] owieczka;
    owieczka = std::move(tmp.owieczka);
    tmp.owieczka=nullptr;
    return *this;
}

