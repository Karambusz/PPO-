#ifndef tank_h
#define tank_h
#include <iostream>



class Tank{
private:
    int _pojemnosc;
    double _paliwo;
public:
    friend class Car;
    Tank(int);
    double operator()();
    bool operator++();
    bool operator-=(double);




};


#endif