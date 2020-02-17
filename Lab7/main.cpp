/// \file main.cpp
/// \mainpage
///
/// \n\n
///
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
///
/// Dodatkowe zastrzezenia:
/// a) Nie wolno uzywac struktur (nalezy uzyc klas).
/// b) Nalezy dolaczyc Makefile aby calosc programu kompilowala
///    sie poleceniem make. 
///    -- MUSI istniec rowniez cel clean, aby polecenie 
///      'make clean' usuwało skompilowane biblioteki i plik wykonywalny.
///    -- musi istniec cel valgrind, ktory uruchamia polecenie 'valgrind --tool=memcheck'
///       na programie wykonywalnym 
///    -- Program musi sie re-kompilowac poleceniem make po modyfikacji plikow naglowkowych.
///    -- Plik wykonywalny musi sie nazywac 'exec'
/// c) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe i naglowkowe, 
///     wlaczajac main.cpp (nie wysylamy skompilowanych bibliotek ani pliku wykonywalnego)
/// d) Nie wolno modyfikowac pliku main.cpp.
/// 
///
///    \n\n


#include<iostream>

/// Wlaczamy klase Coin z poprzednich zajec.
#include "coin.h"

/// Plik naglowkowy deklarujacy klase Node, 
/// reprezentujaca wezel w liscie jednokierunkowej
/// przechowujacej obiekty typu Coin.
/// UWAGA: 
///       -- klasa moze miec tylko jedna publiczna metode
///          Node::get_tot_nodes()
///       -- klasa nie moze miec zadnych innych publicznych metod
///          ani skladnikow (dotyczy rowniez konstruktorow)
#include "node.h"

/// Plik naglowkowy deklarujacy klase Stack, ktora
/// implementuje kontener typu stos. Jest to kontener 
/// typu LIFO (last in, first out), czyli aby dostac sie
/// do elementow wlozonych wczeniej, nalezy 'zdjac' ostatnie 
/// elementy. 
/// Stos nalezy zaimplementowac lista jednokierunkowa, uzywajac
/// klasy Node jako wezlow. 
/// UWAGA:
///      -- nie mozna uzywac kontenerow STL
///      -- stos musi przechowywac kopie wlozonych do niego obiektow
#include "stack.h"


int main() {
	
	std::cout << "\n";

	srand (232113443); // Seed dla generator licz pseudo losowych.


	// Tworzymy stos nr 1, w ktorym przechowamy 
	// Stos jest inicjalizowany pierwszym elementem.
	Coin coin1;
	Stack stack1(coin1);
	
	// Wypelniamy stos pewna liczba monet
	unsigned Ncoin1 = 9;
	for (unsigned i=0;i<Ncoin1;++i) {
		Coin coin_tmp;
		stack1.push(coin_tmp);
	}

	// Wyswietlamy liczbe uzytych wezlow
	std::cout << "Nuber of created nodes: " << Node::get_tot_nodes() << std::endl;

	std::cout << "\n++++++++++++++++++++\n";

	// Zdejmujemy monety ze stosu (zdjete monety sa pokazywane wskaznikiem)
	// i wyswietlamy ich wartosc i strone (po czym usuwamy monete).
	Coin* coin_ptr = nullptr;
	while ( (coin_ptr = stack1.pop()) ) { 
		std::cout << "Coin value: " << coin_ptr->get_coin_value() << "PLN, ";
		coin_ptr->print_side_up();
		delete coin_ptr;
	} // Stos jest teraz pusty.
	

	// Tworzymy drugi stos
	Stack stack2(coin1);
	for (unsigned i=0;i<Ncoin1;++i) {
		Coin coin_tmp;
		stack2.push(coin_tmp);
	} // Destruktor stosu powinien zwolnic pamiec gdy stos 
	  // zostanie zlikwidowany przy zakonczeniu fcji main.



	std::cout << "\n";
	

return 0;}

