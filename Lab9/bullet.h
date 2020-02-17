#ifndef bullet_h    
#define bullet_h
#include <iostream>

class Bullet{
private:
    double _caliber;
public:
    Bullet(double caliber);
    Bullet(){std::cout<<get_caliber()<<std::endl;}
    void click() { std::cout << "-click- "; }
    double get_caliber(){return _caliber;}

};

#endif