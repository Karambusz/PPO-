#ifndef pasture_h
#define pasture_h
#include <iostream>

class Pasture{
private:
    double _pole;
    bool *owieczka;
    int index;
public:
    friend std::ostream &operator<<(std::ostream &o, const Pasture &K);
    friend Pasture operator+(const Pasture &tmp1, const Pasture &tmp2);
    friend Pasture operator*(double a, const Pasture &tmp);
    friend Pasture operator*(const Pasture &tmp, double a);
    Pasture &operator=(const Pasture &tmp);
    Pasture(double bok, int liczba);
    Pasture();
    Pasture(const Pasture &tmp);
    Pasture(Pasture &&tmp);
    ~Pasture();
    Pasture &operator*=(double tmp);
    Pasture &operator=(Pasture &&tmp);
    bool operator() (const Pasture &tmp1, const Pasture &tmp2);
    



};



#endif