#include "car.h"
#include <iostream>
#include "tank.h"
#include "odometer.h"


Car::Car(double paliwo, int size){
    _size = size;
    zuz_paliwa=paliwo;
    wsk_tank = new Tank(size);
    wsk_odometer = new Odometer();
}

void Car::dashboard(){
    std::cout<<">>> Km: "<<wsk_odometer->operator()()<<"    Fuel(L): "<<wsk_tank->operator()()<<" <<<"<<std::endl;
}

void Car::refuel(){
    while (! ++(*wsk_tank));
}

void Car::drive(int distance){
   while(distance>0){
       if(!((*wsk_tank)-=zuz_paliwa/100)) return;
       ++(*wsk_odometer);
       distance--;
   }
        
}

Car::Car(const Car &tmp){
    _size = tmp._size;
    zuz_paliwa = tmp.zuz_paliwa;
    if(tmp.wsk_tank)
    wsk_tank = new Tank(_size);
    wsk_tank->_paliwo = tmp.wsk_tank->_paliwo;
    if(tmp.wsk_odometer)
    wsk_odometer = new Odometer();
    wsk_odometer->_km = tmp.wsk_odometer->_km;
}

Car::Car( Car &&tmp){
    _size = tmp._size;
    zuz_paliwa = tmp.zuz_paliwa;
    wsk_tank = tmp.wsk_tank;
    wsk_odometer = tmp.wsk_odometer;
    tmp.wsk_odometer=nullptr;
    tmp.wsk_tank=nullptr;
    tmp.zuz_paliwa=0;
    tmp._size=0;

}

Car::~Car(){
    if(wsk_tank)
        delete wsk_tank;
    if(wsk_odometer)
        delete wsk_odometer;
}