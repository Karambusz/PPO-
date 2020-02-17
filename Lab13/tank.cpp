#include "tank.h"
#include <iostream>

Tank::Tank(int n){
    _pojemnosc = n;
    _paliwo=0;
}


double Tank::operator()(){
    return _paliwo;
}


bool Tank::operator++(){
    _paliwo++;
    if(_paliwo == _pojemnosc){
        std::cout<<"## Tank full."<<std::endl;
        return true;
    }
    return false;
}

bool Tank::operator-=(double n){
        if(_paliwo-n < 0){
            std::cout<<"## Tank empty."<<std::endl;
            return false;
        }
        _paliwo-=n;
        return true;
}


