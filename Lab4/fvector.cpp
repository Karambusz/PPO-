#include "fvector.h"
#include "fvectop.h"
#include <math.h>
#include "iostream"
using namespace std;

FourVector *CreateFourVector(double *tab){
    FourVector *vector = new FourVector;
    vector->czas_ = tab[0];
    vector->x_ = tab[1];
    vector->y_ = tab[2];
    vector->z_ = tab[3];
    double iloczyn = ScalarProduct(*vector, *vector);
    if(iloczyn < 0){
    vector->M = -sqrt(abs(iloczyn));
    }else
    {
        vector->M = sqrt(iloczyn);
    } 
    return vector;
}

void PrintFourVector(FourVector vector){
    cout<<"("<<vector.czas_<<","<<vector.x_<<","<<vector.y_<<","<<vector.z_<<")"<<endl;
}

void PrintFourVector(FourVector *vector){
    cout<<"("<<vector->czas_<<","<<vector->x_<<","<<vector->y_<<","<<vector->z_<<")"<<endl;
}

void DeleteFourVector(FourVector *vector){
    delete vector;
}