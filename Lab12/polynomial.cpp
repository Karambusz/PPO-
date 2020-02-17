#include <iostream>
#include "polynomial.h"
#include <math.h>
#include <utility>

std::ostream &operator<<(std::ostream &o, const Polynomial &K){
    o<<K.tab[0]<<" +";
    for(int i=1; i<K._size; i++)
    {
        if(K.tab[i]!=0){
            if(i!=K._size){
            o<<K.tab[i]<<"*x^"<<i;
            if(i!=K._size-1){
                o<<" +";
            }     
        }
        }

    }
    return o;
}
///////////////////////////////////////////
Polynomial::Polynomial(int n, double *array){
    _size = n+1;
    tab = new double[_size];
    for(int i=0; i<_size; i++){
        tab[i] = array[i];
    }
}
///////////////////////////////////////////
Polynomial::Polynomial(int n=0){
    _size = n+1;
    tab = new double[_size]{0};
}
///////////////////////////////////////////
Polynomial::Polynomial(const Polynomial &tmp){
    _size=tmp._size;
    tab = new double[_size];
    for(int i=0; i<_size; i++){
        tab[i]=tmp.tab[i];
    }
}
///////////////////////////////////////////
Polynomial::Polynomial(Polynomial &&tmp){
    _size=std::exchange(tmp._size, 0);
    tab = tmp.tab;
    tmp.tab=nullptr;
}
///////////////////////////////////////////
Polynomial &Polynomial::operator=(const Polynomial &tmp){
    if(this==&tmp){
        return *this;
    }
    delete [] tab;
    _size=tmp._size;
    tab = new double[_size];
    for(int i=0; i<_size; i++){
        tab[i] = tmp.tab[i];
    }
    return *this;
}
///////////////////////////////////////////
Polynomial & Polynomial::operator=(Polynomial &&tmp){
    _size = std::exchange(tmp._size, 0);
    delete [] tab;
    tab = std::move(tmp.tab);
    tmp.tab=nullptr;
    return *this;
}
/////////////////////////////////////////
Polynomial::~Polynomial(){
    if(tab){
        delete [] tab;
    }
}
/////////////////////////////////////////
double Polynomial::operator()(double a){
    double wynik = 0;
    double x = 1;
    wynik+=tab[0];
    for(int i=1; i<_size; i++){
        if(tab[i]!=0){
            x=pow(a,i);
            wynik+=tab[i]*x;
        }
    }
    return wynik;
}
///////////////////////////////////////////
Polynomial & Polynomial::operator+=(const Polynomial &tmp){
    double pomoc[_size];
    for(int i=0; i<_size; i++){
        pomoc[i] = tab[i];
    }
    delete [] tab;

    double a = 0;
    if(_size==tmp._size){
        a=_size;
        tab = new double[_size]{0};
        for(int i=0; i<_size; i++){
            tab[i]=pomoc[i]+tmp.tab[i];
        }
    }
    else if(_size>tmp._size){
        a=_size;
        tab = new double[_size]{0};
        for(int i=0; i<tmp._size; i++){
            tab[i]=pomoc[i]+tmp.tab[i];
        }
        for(int i=tmp._size; i<a; i++){
            tab[i]=pomoc[i];
        }
    }
     else{
         a=_size;
        _size = tmp._size;
        tab = new double[_size]{0};
        for(int i=0; i<a; i++){
            tab[i]=pomoc[i]+tmp.tab[i];  
        }
        for(int i=a; i<_size; i++){
            tab[i]=tmp.tab[i];
        }
    }
    return *this;
    
}
///////////////////////////////////////////
Polynomial operator+(const Polynomial &tmp1, const Polynomial &tmp2){
    Polynomial nowy(tmp1);
    nowy+=tmp2;
    return nowy;
}
///////////////////////////////////////////
Polynomial operator*(const Polynomial &tmp1, const double liczba){
    Polynomial nowy(tmp1);
    for(int i=0; i<nowy._size; i++){
        nowy.tab[i] *= liczba; 
    }
    return nowy;
}