#include "polynomial.h"
#include <iostream>
#include <math.h>
#include <utility>


class Legendre : public Polynomial{
public:
//double * licz(int);
Legendre(int n):Polynomial(n){
    for(int i = n%2; i<=n; i+=2){
      tab[i] = (double)pow(-1, (n-i)/2) / (double)pow(2,n);
      tab[i] *= (double) std::tgamma(n+i+1);
      tab[i] /= (double) std::tgamma((n-i)/2 + 1);
      tab[i] /= (double) std::tgamma((n+i)/2 + 1);
      tab[i] /= (double) std::tgamma(i + 1);
    }
}

Legendre(const Legendre &tmp):Polynomial(tmp){}

Legendre(Legendre &&tmp):Polynomial(std::move(tmp)) {}

Legendre &operator=(const Legendre &tmp){
    (*this).Polynomial::operator=(tmp);
    return *this;
}

Legendre operator=(Legendre &&tmp){
    (*this).Polynomial::operator=(std::move(tmp));
    return *this;
}








};