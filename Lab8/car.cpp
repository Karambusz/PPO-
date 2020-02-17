#include <string>
#include <iostream>
#include "car.h"


SubaruCar::SubaruCar(std::string nazwa, int rok, int przebieg):
_nazwa(nazwa), _rok(rok), _przebieg(przebieg){}

SubaruCar::SubaruCar(){
    _nazwa="no-name";
    _rok=0;
    _przebieg=0;
    _numer=0;
    _cena=0;
}