#include "odometer.h"
#include <iostream>

Odometer::Odometer(){
    _km=0;
}


int Odometer::operator()(){
    return _km;
}

Odometer & Odometer::operator++(){
    _km++;
    return *this;
}