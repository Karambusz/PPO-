#ifndef polynomial_h
#define polynomial_h
#include <iostream>

class Polynomial{
protected:
    int _size;
    double *tab;
public:
    friend std::ostream &operator<<(std::ostream &o, const Polynomial &K);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const double); 
    Polynomial(int, double *);
    Polynomial(int);
    Polynomial(const Polynomial &);
    Polynomial(Polynomial &&);
    Polynomial &operator=(const Polynomial &);
    Polynomial &operator=(Polynomial &&);
     ~Polynomial();
    double operator()(double);
    Polynomial &operator+=(const Polynomial &);
};


#endif