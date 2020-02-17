#ifndef coin_h
#define coin_h

enum strona {
    heads =0, tails=1
};

enum wartosc {
    one=1, two=2, five=5
};



class Coin {
private:
    wartosc value;
    strona side;
public:
    Coin();
    Coin(wartosc a);
    strona get_side_up();
    int get_coin_value();
    void print_side_up();
    void toss();
};



#endif