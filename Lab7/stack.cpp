#include "stack.h"

Stack::Stack(Coin &coin){
    stos = new Node;
    stos->object=new Coin(coin);
    stos->prev=nullptr;
}

void Stack::push(Coin &coin){
    Node *wezel = new Node;
    wezel->object= new Coin(coin);
    wezel->prev=stos;
    stos=wezel;
     
}

Coin * Stack::pop(){
    if(!stos)
    return nullptr;
    Coin *wsk = stos->object;
    Node *tmp=stos;
    stos=stos->prev;
    delete tmp;
    return wsk;
}


Stack::~Stack(){
    if(stos){
        while(stos->prev!=nullptr){
            Node *tmp = stos;
            stos=stos->prev;
            delete tmp->object;
            delete tmp;
        }
        delete stos->object;
        delete stos;
    }
}