/// \file main.cpp
/// \mainpage
///
/// Program implementujacy prosty 'pojemnik' typu lista
/// jednokrotnie laczona.
///  \n\n
///
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
///
/// Dodatkowe zastrzezenia (UWAGA: brak spelnienia ktoregokolwiek = 0 pkt):
/// a) Prosze NIE UZYWAC klas (mozna uzywac struktur, ale tylko jako 
///    POD -- plain-old-data). 
/// b) Nalezy napisac Makefile aby calosc programu kompilowala
///    sie poleceniem make. 
///    -- MUSI istniec rowniez cel clean, aby polecenie 
///      'make clean' usuwało skompilowane biblioteki i plik wykonywalny.
///    -- musi istniec cel valgrind, ktory uruchamia polecenie 'valgrind --tool=memcheck'
///       na programie wykonywalnym 
///    -- Program musi sie re-kompilowac poleceniem make po modyfikacji plikow naglowkowych.
///    -- Plik wykonywalny musi sie nazywac 'exec'
/// c) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe
///    (czyli bez plikow wykonywalnych i bibliotek)
/// d) Nie wolno modyfikowac pliku main.cpp ani innych plikow w ktorych jest to zastrzezone. \n\n
/// 
/// Sugestie:
/// -- Prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///    Typ *wsk = new Typ[N]; delete [] wsk; (dla tablic o rozmiarze N)
/// -- Prosze pamietac o dokumentacji.
///
///    \n\n

#include<iostream>

/// Plik naglowkowy dla implementacji typu Particle i kilku funkcji
#include "particle.h"

/// Plik naglowkowy dla implementacji listy
#include "mylist.h"



int main() {
	
	std::cout << "\n";

	/// Lista bedzie sluzyc do przechowywania obiektow naszego wlasnego typu.
	///
	/// Dla prostoty, niech bedzie to typ Particle, ktory implemetuje dwie podstawowe informacje
	/// na temat czastek: nazwa czastki oraz masa.
	/// Przyklady ponizej:
	Particle electron;
	double const me = 0.5; // electron mass
	SetParticle(electron, "electron",me);
	///
	Particle gluon;
	SetParticle(gluon,"gluon",0);
	///
	Particle higgs;
	SetParticle(higgs,"higgs",125000.);


	/// Inicjalizacja listy pierwszym elementem.
	ListElem* init_elem_l1 = InitList(&electron);


	/// Tak chcemy dodawac czastki do listy.
	/// Lista jest wskazana dowolnym istniejacym wezlem.
	AddToList(init_elem_l1,&gluon);
	AddToList(init_elem_l1,&higgs);

	/// Drukujemy liste poczawszy od wskazanego elementu.
	std::cout << "++++ First list ++++" << std::endl;
	PrintList(init_elem_l1);
	std::cout << "+++++++  end  ++++++\n" << std::endl;

	/// Funkcja FindLastElem zwraca ostatni element listy
	std::cout << "Last element:" << std::endl;
	PrintParticle(*(FindLastElem(init_elem_l1)->particle_pt));



	std::cout << "\n";

	
	/// Tworzymy nowa liste;
	
	const int N = 15;
	Particle barion1;
	const double mp = 1000.;
	SetParticle(barion1,"proton",mp);

	ListElem *init_elem_l2 = InitList(&barion1);

	Particle* resonance_pt[N-1]; // tablica zapamietjaca wsk do obiektow dynamicznych

	for (int i=2;i<=N;++i) {
		
		Particle *resonance = new Particle;
		SetParticle(*resonance,"res",i*mp);

		AddToList(init_elem_l2,resonance);

		resonance_pt[i-2] = resonance;

	}

	std::cout << "++++ Second list ++++" << std::endl;
	PrintList(init_elem_l2);
	std::cout << "+++++++  end  +++++++\n" << std::endl;

	/// Usuwamy listy (czyscimy pamiec)
	RemoveList(init_elem_l1);
        RemoveList(init_elem_l2);

	/// Usuwamy pamiec po obiektach pokazywanych przez druga liste
	for (int k=0;k<N-1;++k)
		delete resonance_pt[k];


	std::cout << "\n";

return 0;}

