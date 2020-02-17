#ifndef car_h
#define car_h
#include "tank.h"
#include "odometer.h"

class Car{
private:
    Tank *wsk_tank;
    Odometer *wsk_odometer;
    double zuz_paliwa;
    int _size;
public:
    Car(double, int);
    Car(const Car &);
    Car(Car &&);
    ~Car();
    void dashboard();
    void refuel();
    void drive(int);



};

#endif