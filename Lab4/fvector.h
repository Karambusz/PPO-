#ifndef fvector_h
#define fvector_h

struct FourVector
{
    double czas_;
    double x_;
    double y_;
    double z_;
    double M;

};

FourVector *CreateFourVector(double *tab);
void PrintFourVector(FourVector vector);
void PrintFourVector(FourVector *vector);
void DeleteFourVector(FourVector *vector);

#endif