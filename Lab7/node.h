#ifndef node_h
#define node_h
#include "coin.h"


class Node{
private:
    static int n;
    Coin *object;
    Node *prev;
    Node();
public:
    friend class Stack;
    static int get_tot_nodes();
};

#endif