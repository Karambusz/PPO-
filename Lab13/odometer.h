#ifndef odometer_h
#define odometer_h

class Odometer{
private:
    int _km;
public:
    friend class Car;
    Odometer();
    int operator()();
    Odometer &operator++();
};

#endif