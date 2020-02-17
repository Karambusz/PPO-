#include <iostream>
#include <math.h>
#include <utility>
#include "legendre.h"


/*double * Legendre::licz(int n){
    double *tab = new double[n];
    for(int i=0; i<n; i++){
        tab[i] = 0;
    }
    int parzyste;
    if(n%2==0){
        parzyste = 0;
    }else
    {
        parzyste = 1;
    }
    int jedynka = 1;
    if(parzyste==0){
        for(int l=0; l<=n; l+=2){
            jedynka = pow(-1, (n-l)/2);
            long czyselnik1 = std::tgamma(l+n + 1);
            long znamennik1=std::tgamma((n-l)/2 + 1);
            long znamennik2=std::tgamma((n+l)/2 + 1);
            long znamennik3=std::tgamma(l+ 1);
            tab[l] = (jedynka*czyselnik1/pow(2,n))/(znamennik1*znamennik2*znamennik3);
        }
    }else
    {
        for(int l=1; l<=n; l+=2){
            jedynka = pow(-1, (n-l)/2);
            long czyselnik1 = std::tgamma(l+n + 1);
            long znamennik1=std::tgamma((n-l)/2 + 1);
            long znamennik2=std::tgamma((n+l)/2 + 1);
            long znamennik3=std::tgamma(l+ 1);
            tab[l] = (jedynka*czyselnik1/pow(2,n))/(znamennik1*znamennik2*znamennik3);
        }
    }
    
    return tab;

    return tab;
}
*/