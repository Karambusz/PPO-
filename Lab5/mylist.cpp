#include<iostream>

#include "particle.h"
#include "mylist.h"

/// funkcja tworzaca wezel listy, dodaje nazwe i mase a wskaznuk na nastepny element wskazuje na 
ListElem*  InitList(Particle* particle_pt){

    ListElem *list = new ListElem;
    list->particle_pt = particle_pt;
    list->next = NULL;
    return list;
}

/// funkcja ktora dodaje wezel na koniec listy
void AddToList(ListElem *prev_elem, Particle* particle_pt){    
    ListElem *next_elem = new ListElem;
    ListElem *elem = FindLastElem(prev_elem);
    elem->next=next_elem;
    next_elem->particle_pt = particle_pt;
    next_elem->next = NULL;

}

/// funkcja ktora szuka ostatni wezel listy
ListElem *FindLastElem(ListElem *init_elem){

/// szuka ostatni wezel przez przechodzenia po wszystkich wezlach 
///dopoki wskaznik na next nie rowna sie NULL
    while(init_elem->next!=NULL){
        init_elem=init_elem->next;
    }
    return init_elem;

}

/// Funkcja usuwa wezly z pamieci, poczawszy od wskazanego.
void RemoveList(ListElem *init_elem){
 
 /*
   if(init_elem->next == NULL)
   {
       delete init_elem;
   } else {
       RemoveList(init_elem->next);
        delete init_elem;
    }

*/    

    while(init_elem->next!=NULL){
        ListElem *wsk=init_elem;
        init_elem=init_elem->next;
        delete wsk;
    }
    delete init_elem;
    

}