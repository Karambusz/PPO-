/// \file main.cpp
/// \mainpage
///
/// \n\n
///
//  ----------------------------------------------------------------------------------
/// Należy utworzyć brakujące pliki 
/// i utworzyć w nich odpowiedni kod, tak aby 
/// program się kompilowal BEZ OSTRZEŻEŃ i poprawnie wykonywał,
/// dając DOKŁADNIE wynik podany w pliku output.txt. 
/// (Należy użyć komendy diff -- patrz porady na końcu pliku).
///  \n\n
/// 
/// Ponadto:
/// a) Należy użyc ***  CMake *** do przygotowania programu
/// -- pliki źrodłowe muszą być w podkatalogu 'src'
/// -- pliki nagłówkowe muszą być w podkatalogu 'include' 
/// -- kod musi się kompilować w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' 
/// b) program musi się kompilować z flagami '-Wall -g', jako minimum.
/// c) Jako rozwiązanie, proszę przeslać spakowany katalog źrodlowy, 
///    WŁĄCZAJĄC plik main.cpp, ale BEZ katalogu 'build'. 
/// d) Nie wolno modyfikować pliku main.cpp.
/// e) Proszę nazwać program wykonywalny 'exec'.
//  --------------------------------------------------------------------------------- 
///
///    \n\n


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


// -------------------------------------------------------------------------------
//
/// *** Klasa Pasture ***
///
/// 1) Klasa implementuje 'pastwisko', które jest kwadratem o zadanym boku.
///    Na pastwisku pasie się zadana liczba owiec, białych lub czarnych.
///    Owieczka biała jest oznaczana liczbą 0, zaś czarna liczbą 1.
/// 
///    Klasa MUSI mieć przynajmniej następujące pola:
///	-- pole powierzchni pastwiska (typ double)
///	-- dynamiczna tablica owieczek (typ bool* )
//
///    Klasa musi mieć (jako minimum) następujące konstruktory:
///	-- konstruktor tworzący pastwisko o zadanym boku i liczbie owiec;
///	   Kolor owcy (czarny, biały) jest losowany fcją rand()
///	-- Konstruktor domyślny, który co najwyżej zeruje pola
///	-- Konstruktor kopiujący i przenoszący
///
///    Należy przeładować następujące operatory (szczegóły implementacji
///    trzeba odczytać z fcji main i wyjścia z pliku output.txt):
///	-- przypisania kopiującego i przenoszącego
///	-- operator + dla dodawania dwóch pastwisk
///	   Dodanie dwóch pastwisk dodaje ich powierzchnie i owce.
///        Zakładamy, że zachowujemy uporządkowanie owiec dodając pastwiska
///	   (patrz plik output.txt)
///	-- operator =* dla mnożenia pastwiska przez liczbę double x
///	   W wyniku powiększamy pole powierzchni x razy.
///	-- operator * dla mnożenia pastwiska przez double z lewej bądź prawej strony.
///	   Efekt taki sam jak dla =*.
///	-- Operator ()
///	   Należy utworzyć predykat, który porównuje powierzchnie dwóch pastwisk.
///	-- Operator << drukujący obiekt Pasture do std-out
///	   Format wydruku widoczny jest w pliku output.txt.
///        
#include "pasture.h"
// -----------------------------------------------------------------------------




// =======================================================================
int main() {

	srand(122332);// seed dla generatora liczb pseudolosowych
	std::cout << "\n";

	// Tworzymy 3 pastwiska o bokach danych jako pierwszy argument
	// i liczbie owiec danej drugim argumentem.
	
	  Pasture ps1(3.,5), ps2(4.,8), ps3 (1.,2);

	  cout << ps1 << "\n" << ps2 << "\n" << endl;



	cout << "\n-------------------------------------------------------------\n" << endl;

	// Testujmey operatory = , + , *= , *

	  Pasture sum1 = ps1+ps2, sum2 = Pasture(sqrt(2.),3)+Pasture(sqrt(5.),4);

	  cout << sum1 << "\n" << sum2 << endl;

	  cout << (sum1*=2.) << "\n" << 3.*sum2 << "\n" << sum2*3. << endl;



	cout << "\n-------------------------------------------------------------\n" << endl;

	// Tworzymy STL wektor pastwisk i sortujemy malejąco używając predykatu,
	// danego jako obiekt klasy Pasture.
	
  	  vector<Pasture> fields;
	  fields.push_back(ps1);
	  fields.push_back(ps2);
	  fields.push_back(ps3);
	  fields.push_back(sum1);
	  fields.push_back(sum2);

	  Pasture pred; 

	  sort(fields.begin(),fields.end(), pred );

	  vector<Pasture>::iterator it = fields.begin();
	  while (it!=fields.end()) { 
	  	cout << *it << endl;
		it++;
	  } 

	
	std::cout << "\n";

return 0;}
/// =======================================================================



///
///    *** Porady/Pomoc ***
///
///  -- Wszystkie krótkie fcje najlepiej zaimplementować w ciele klasy.
///     Poza klasą, implementujemy tylko fcje na wiele linijek.
///     Przyspieszy to pisanie programu.
///  -- poprawność wyjścia można sprawdzić komendą:
///     diff output.txt <( ./exec )
