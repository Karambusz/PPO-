#ifndef stack_h
#define stack_h

#include "coin.h"
#include "node.h"


class Stack{
private:
    Node *stos;
public:
    Stack(Coin &coin);
    void push(Coin &coin);
    Coin *pop();
    ~Stack();

};

#endif