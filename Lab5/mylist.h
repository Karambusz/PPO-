#ifndef mylist_h
#define mylist_h

// ** UWAGA ** NIE MODYFIKOWAC

#include "particle.h"

/// Struktura zapamietujaca wskaznik do obiektu znajdujacego sie
/// na danym miejscu listy (particle_pt) 
/// oraz zapamietujaca wskaznik do nastepnego elementu listy (next). 
/// Jesli next = nullptr jest to ostatni element listy.
/// Obiekty niniejszego typu nawywaja sie wezlami listy.
struct ListElem {
	Particle *particle_pt;
	ListElem *next;
};


/// Inicjalizacja listy.
/// Funkcja tworzy pierwszy wezel listy i zwraca wskaznik
/// do tego wezla.
/// UWAGA: lista tylko zapamietuje wskazniki do istniejacych
/// obiektow! Nie robi kopii obiektow.
ListElem*  InitList(Particle* particle_pt);


/// Funkcja dodajaca element do listy. Lista jest wskazana
/// poprzez podanie dowolnego poprzedniego wezla listy.
void AddToList(ListElem *prev_elem, Particle* particle_pt);


/// Funkcja znajduje ostatni element listy (wezel) i zwraca
/// do niego wskaznik.
/// Fcja powinna byc uzyta w AddToList.
ListElem *FindLastElem(ListElem *init_elem);


/// Funkcja drukujaca zawartosc listy, poczawszy
/// od wskazanego elementu (wezla).
inline void PrintList(ListElem *init_elem) {
	ListElem* elem = init_elem;
	do {
		PrintParticle(*(elem->particle_pt));
		elem = elem->next; 
	}
	while (elem!=nullptr);
}


/// Funkcja usuwa wezly z pamieci, poczawszy od wskazanego.
/// Wskazanie pierwszego wezla usuwa liste.
void RemoveList(ListElem *init_elem);

#endif
