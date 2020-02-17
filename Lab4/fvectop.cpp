#include "fvectop.h"
#include <math.h>

double ScalarProduct(FourVector v1, FourVector v2){
    double iloczyn = 0;
    iloczyn = (v1.czas_ * v2.czas_)-(v1.x_ * v2.x_) - (v1.y_ * v2.y_) - (v1.z_ * v2.z_);
    return iloczyn;
}

FourVector* AddFourVectors(FourVector v1, FourVector v2){
    FourVector *vector = new FourVector;
    vector->czas_ = v1.czas_ + v2.czas_;
    vector->x_ = v1.x_ + v2.x_;
    vector->y_ = v1.y_ + v2.y_;
    vector->z_ = v1.z_ + v2.z_;
    vector->M = sqrt(ScalarProduct(*vector, *vector));
    return vector;
}