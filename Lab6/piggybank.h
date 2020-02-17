#ifndef piggybank_h
#define piggybank_h

#include "coin.h"

class Piggybank{
private:
    int size;
    Coin *tab;
    int suma;
    int index;


public:
   // friend class Coin;
    Piggybank(int rozm);
    void put_coin(const Coin &moneta);
    int get_tot_value();
    ~Piggybank();





};

#endif