#ifndef gun_h
#define gun_h
#include "bullet.h"

class Gun{
private:
    Bullet **magazyn;
    int _size;
    int _index;
    double _caliber;
    Bullet *komora;
public:
    Gun(int size, double caliber);
    ~Gun();
    void load();
    void bang() { std::cout << "\nBang!" << std::endl;}
    void mag_empty() { std::cout << "Gun: Magazine empty." << std::endl; }
    void chamb_empty() { std::cout << "Gun: Chamber is empty. Reload." << std::endl; }
    void pull_trigger();
    void pull_trigger(int a);
    void new_magazine();
    Gun(const Gun &tmp);
    Gun(Gun &&tmp);
};

#endif