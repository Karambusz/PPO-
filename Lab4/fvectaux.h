#ifndef fvectaux_h
#define fvectaux_h
#include "fvector.h"

void RemoveAllFourVectors(FourVector **tab, int n){
    for(int i=0; i<n; i++){
        delete tab[i];
    }
    delete [] tab;
}


#endif
