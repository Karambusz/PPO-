#include<iostream>

#include "coin.h"


///////////////////////////
Coin::Coin(wartosc a){
    value = a;
    toss();
    side = get_side_up();
}
//////////////////////////////////////
strona Coin::get_side_up(){
    return side;
}
///////////////////////////////////
Coin::Coin(){
    value = one;
    toss();
    side = get_side_up();
    
}
///////////////////////////////////////
int Coin::get_coin_value(){
    return value;
}
///////////////////////////////
void Coin::print_side_up(){
    if(side == heads)
        std::cout<<"heads"<<std::endl;
    else
        std::cout<<"tails"<<std::endl;
}
//////////////////////////////////////////
void Coin::toss(){
   side = strona(rand()%2);
}
