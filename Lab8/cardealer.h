#ifndef cardealer_H
#define cardealer_h
#include "car.h"

class SubaruDealer{
private:
    SubaruCar *salon;
    int _size;
    int _index;
    int _suma;
    static int n;
public:
    SubaruDealer(int size);
    ~SubaruDealer(){ delete [] salon;}
    void new_inventory(SubaruCar car, int numer, int cena);
    SubaruCar *show(int numer);
    void sell(int numer);
    int get_income();
    static int get_all_dealers_income();



};


#endif