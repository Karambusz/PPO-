#include "node.h"

int Node::n;

Node::Node(){
    n++;
}

int Node::get_tot_nodes(){
    return n;
}

