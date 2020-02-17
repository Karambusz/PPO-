/// \file main.cpp
/// \mainpage
///
/// \n\n
///
///
/// Należy utworzyć brakujące pliki i napisać odpowiednie klasy, opisane niżej.
/// Program musi się kompilować bez ostrzeżeń i poprawnie wykonywać,
/// dając wynik podany w pliku output.txt. 
/// Najlepiej użyć komendy 'diff <( ./exec ) output.txt )'
/// 
/// Dodatkowe zastrzeżenia:\n
/// a) Należy użyc CMake do przygotowania programu:\n
///  -- pliki źrodłowe muszą być w podkatalogu 'src'\n
///  -- pliki nagłówkowe muszą być w podkatalogu 'include'\n 
///  -- kod musi się kompilować w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' \n
/// b) program musi się kompilować z flagami '-Wall -g', jako minimum.\n
/// c) Jako rozwiązanie, proszę przeslać spakowany katalog źrodlowy,
///    WŁĄCZAJĄC plik main.cpp, ale BEZ katalogu 'build'. \n
/// d) Nie wolno modyfikować pliku main.cpp.\n
/// e) Proszę nazwać program wykonywalny 'exec'.\n
///
///   
///
/// -------------------------------------------------------------------------------
///  
/// *** Klasa Tank ***
/// 
/// Klasa implementuje zbiornik paliwa o zadanej pojemności.
/// Minimalne składniki klasy to:\n
/// 1) pojemność zbiornika
/// 2) ilość paliwa w litrach (double)
/// 3) Konstruktor tworzący zbiornik o zadanej pojemności.
/// 4) Operator() zwracający ilość paliwa w zbiorniku
/// 5) Operator ++ (preinkrementacji) zwiekszający ilość paliwa o 1 litr, służacy do tankowania. 
///	Operator musi zwracać true jeśli zbiornik jest pełny oraz false jeśli nie jest.
///     Przy próbie dolania do pełnego zbiornika powinien wyświetlać się napis:
///     ## Tank full. 
/// 6) Operator -= zmniejszający ilośc paliwa w zbiorniku o zadaną ilość X. Operator musi 
///    zwracać true jeśli w zbiorniku jest paliwo aby zużyć X paliwa, zaś false jeśli jest  
///    niewystarczająca ilość paliwa aby odjąć X paliwa. 
///    Przy próbie zużycia zbyt dużej ilości paliwa w stosunku do ilości w zbiorniku,
///    powinien wyświetlać się komunikat: ## Tank empty.  
///    
/// -------------------------------------------------------------------------------
///  
/// *** Klasa Odometer ***
/// 
/// Klasa implementuje licznik kilometrów.
/// Minimalne składniki klasy to:
/// 1) ilość przejechanych kilometrów 
/// 2) Konstruktor domyślny tworzący licznik ze wskaaniem 0
/// 3) Operator() zwracający ilość przejechanych kilometrów
/// 4) Operator ++ zwiększający przejechane kilometry o 1
///  
/// -------------------------------------------------------------------------------
/// 
/// *** Klasa Car ***
/// 
/// Klasa implementuje samochód posiadający zbiornik paliwa oraz licznik kilometrów.
/// Klasa powinna przechowywać:\n
/// 1) dynamiczny obiekt klasy Tank (pokazywany wskaźnikiem)
/// 2) dynamiczny obiekt klasy Odometer (pokazywany wskaźnikiem)
/// 3) zużycie paliwa
/// 4) Konstruktor tworzący samochód o podanym zużyciu paliwa i pojemności baku
/// 5) metodę refuel() która tankuje zbiornik paliwa samochodu do pełna
/// 6) metodę drive(int distance) 
///    Funkcja ta zawiera pętle, która dla każdego przejechanego kilometra
///    zmniejsza ilość paliwa w baku zgodnie ze zużyciem paliwa samochodu,
///    oraz zwiększa wskazania licznika kilometrów.
/// 7) metodę dashboard() wyświetlającą ilość przejechanych km oraz ilość paliwa
///    (format jest widoczny w pliku output.txt)
/// 8) Konstruktory: przenoszący i kopiujący\n


#include <iostream>

using namespace std;

#include "tank.h"
#include "odometer.h"
#include "car.h"

//  -------------------------------------------------
/// Szablon funkcji testującej konstruktory cp/mv
template <class Type> Type  mkcopy(Type obj) {
	return obj; }
//  -------------------------------------------------


// =======================================================================
int main() {

	std::cout << "\n";
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	// Testujemy klasę zbiornika paliwa
	//
	Tank tank1(40);
	cout << "Liters: " << tank1() << endl;
	while (! ++tank1); // tankowanie 
	cout << "Liters: " << tank1() << endl;
	while (tank1 -= 0.66); // zużywanie paliwa
	cout << "Liters: " << tank1() << endl;

	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	// Testujemy klasę licznika kilometrów
	//
	Odometer odo1;
	cout << "Km: " << odo1() << endl;
	for (int l=0; l<150; ++l) 
		++odo1;
	cout << "Km: " << odo1() << endl;

	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	// Testujemy klasę samochodu
	//
	Car car1(6.0,50); // samochód o zużyciu 6 L/100km i poj. baku 50 L
	car1.dashboard(); // wyświetlamy licznik kilometrów i paliwa
	car1.refuel(); // tankujemy
	car1.dashboard();
	car1.drive(100); // jedziemy 100 km
	car1.dashboard();
	car1.drive(1000); // jedziemy dopóki mamy paliwo
	car1.dashboard();
	
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	// Testujemy konstruktor kopiujący/przenoszący klasy Car

	Car car2(mkcopy(Car(7.0,60)));
	car2.dashboard();
	car2.refuel();
	car2.drive(150);
	car2.dashboard();
	Car car3(car2);
	car3.dashboard();


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
