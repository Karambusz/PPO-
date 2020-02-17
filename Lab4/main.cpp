/// \file main.cpp
/// \mainpage
///
/// Program implemetuje wektory w czterowymiarowej czasoprzestrzeni (czterowektory),
/// i dwie operacje na nich: iloczyn skalarny i dodawanie. \n\n
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
/// c) W plikach naglowkowych musza znajdowac sie TYLKO deklaracje funkcji.
///    Definicje prosze umiescic w plikach *.cpp.
/// d) Jako rozwiazanie, prosze przeslac spakowane wszystkie pliki zrodlowe
///    (czyli bez plikow wykonywalnych i bibliotek) \n\n
/// 
/// Sugestie:
/// -- W miare mozliwosci (lub gdy konieczne)  prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///    Typ *wsk = new Typ[N]; delete [] wsk; (dla tablic o rozmiarze N)
/// -- Prosze pamietac o dokumentacji.
///
///    \n\n


#include<iostream>

/// Naglowek deklrujacy czterowektor oraz funkcje: tworzaca, usuwajaca, drukujaca
#include "fvector.h"

/// Naglowek deklarujacy operacje na czterowektorach
/// (niezmienniczy iloczyn skalarny oraz sume)
#include "fvectop.h"

/// Deklaruje funkcje pomocnicza RemoveAllFourVectors
#include "fvectaux.h"

/// Funkcja zwraca liczbe pseudolosowa z przedzialu (0,100)
double gen_rand_coord() {
	const int MaxRange = 100;
	return rand()%MaxRange;
}


int main() {
	
	std::cout << "\n";
	/// Czterowektor to wektor o 4 wspolrzednych: (t,x,y,z),
	/// gdzie t jest czasem, x,y,z -- sa wspolrzednymi przestrzennymi.
	///
	/// Tworzymy czterowektory, zainicjalizowane pewnymi wartosciami wspolrzednych:
	/// 1) czterowektor nr 1
	
	double coord1[] = {4.08,0.,0.,4.08}; 
	FourVector *proton1 = CreateFourVector(coord1);
	
	/// 2) czterowektor nr 2

	double coord2[] = {4.08,0.,0.,-4.08}; 
	FourVector *proton2 = CreateFourVector(coord2);

	/// Drukujemy czterowektory, i ich mase niezmiennicza.
	/// Masa niezmiennicza: \f$ M = \sqrt(v.v) \f$,
	/// gdzie \f$ v1.v2 \f$ jest niezmienniczym iloczynem skalarnym
	/// \f$ v1.v2 = t1*t2-x1*x2-y1*y2-z1*z2 \f$ (uwaga na znaki minus),
	/// zas wspolrzedne wektora to
	/// \f$ v1=(t1,x1,y1,z1) \f$ etc.
	/// UWAGA: jesli \f$ v.v<0 \f$ to umawiamy sie, ze \f$ M = -\sqrt(|v.v|) \f$
	/// Tip: funkcja sqrt znajduje sie w bibliotece <cmath>
	
	std::cout << "four-vector of proton1: " << std::endl;
	PrintFourVector(*proton1);
	std::cout << "invariant mass: " << proton1->M << std::endl;
	std::cout << "four-vector of proton2: " << std::endl;
	PrintFourVector(proton2);
	std::cout << "invariant mass: " << proton2->M << std::endl;

	std::cout << "\n";

	/// Tworzymy czterowektor, bedacy suma czterowektorow proton1 i proton2.
	/// (czterowektory dodaje sie tak samo jak zwykle wektory)
	
	FourVector *totvec = AddFourVectors(*proton1,*proton2);

	std::cout << "four-vector of proton1+proton2: " << std::endl;
	PrintFourVector(*totvec);
	std::cout << "invariant mass: " << (*totvec).M << std::endl;

	std::cout << "\n";

	/// Obliczamy niezmienniczy iloczyn skalarny czterowektorow
	
	double p1p2 = ScalarProduct(*proton1,*proton2);
	std::cout << "Scalar product of proton1.proton2 = " << p1p2 << std::endl;

	/// Usuwamy czterowektory z pamieci
	DeleteFourVector(proton1);
	DeleteFourVector(proton2);
	DeleteFourVector(totvec);

	std::cout << "\n";

	/// Losujemy tablice czterowektorow
	
	srand (44332211); // seed generatora liczb pseudolosowych	
	int NVec = 5;  // rozmiar tablicy

	FourVector **fvectors = new FourVector*[NVec]; // tablica wskaznikow

	std::cout << "Random four-vectors:" << std::endl;
	for (int k=0;k<NVec;++k) {
		// tworzymy tablice losowych liczb calkowitych (0,100)
		double tmpvec[] = {gen_rand_coord(),gen_rand_coord(),gen_rand_coord(),gen_rand_coord()};
		// tworzymy czterowektor
		fvectors[k] = CreateFourVector(tmpvec);
		PrintFourVector(*fvectors[k]);	
		std::cout << fvectors[k]->M << std:: endl;
	}

	/// czyscimy zaalokowana pamiec
	RemoveAllFourVectors(fvectors,NVec);
	
	std::cout << "\n";

return 0;}

