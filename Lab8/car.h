#ifndef car_h
#define car_h
#include <string>


class SubaruCar{
private:
    std::string _nazwa;
    int _rok;
    int _przebieg;
    int _numer;
    int _cena;
public:
    friend class SubaruDealer;
    SubaruCar(std::string nazwa, int rok, int przebieg);
    SubaruCar();
    std::string get_model(){return _nazwa;}
    int get_year(){return _rok;}
    int get_mileage(){return _przebieg;}
};

#endif