/// \file main.cpp
/// \mainpage
///
/// \n\n
///
//  ----------------------------------------------------------------------------------
/// Nalezy utworzyc brakujace pliki 
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany w pliku output.txt. \n\n
/// 
///
/// Dodatkowe zastrzezenia:
/// a) Nalezy uzyc ***  CMake *** do przygotowania programu
/// -- pliki zrodlowe musza byc w podkatalogu 'src'
/// -- pliki naglowkowe musza byc w podkatalogu 'include' 
/// -- kod musi sie kompilowac w nowym podkatalogu (np. 'build')
///    poleceniem 'cmake .. && make' 
/// b) program musi się kompilować z flagami '-Wall -g' jako minimum
/// c) Jako rozwiazanie, prosze przeslac spakowany katalog zrodlowy, 
///    WLACZAJAC plik main.cpp, BEZ katalogu 'build'. 
/// d) Nie wolno modyfikowac pliku main.cpp.
//  --------------------------------------------------------------------------------- 
///
///    \n\n


// -----------------------------------------------------------
//
/// *** Klasa SubaruCar ***
///
/// Klasa ta powinna implementowac nastepujace informacje 
/// na temat samochodow marki Subaru:
/// -- nazwa modelu
/// -- rok produkcji
/// -- przebieg
/// -- numer inwentaryzacyjny
/// -- cena
///
/// Jeden z konstruktorow musi okreslac (kolejno):
///   -- nazwe modelu
///   -- rok produkcji
///   -- przebieg
//
#include "car.h"
// ----------------------------------------------------------


// -----------------------------------------------------------
//
/// *** Klasa SubaruDealer ***
///
/// Klasa ta powinna implementować salon sprzedajacy samochody
/// marki Subaru.
/// -- konstruktor musi okreslac 'rozmiar salonu', tj. ile 
///    maksymalnie samochodow moze salon posiadac
/// -- samochody musza sie znajdowac fizycznie w salonie 
///    (tj. obiekt klasy SubaruDealer musi przechowywać obiekty SubaruCar),
///    sposob ich przechowania jest dowolny o ile jest sensowny
/// -- musi istniec metoda wprowadzajaca nowy inwentarz do salonu
///    o nazwie 'new_inventory' i pobierajaca, kolejno:
///     -- obiekt SubaruCar
///     -- nr inwentaryzacyjny nadawany samochodowi
///     -- cene samochodu 
/// -- musi istniec metoda 'show', pobierajaca nr inventaryzacyjny
///    samochodu jako argment, zwracajaca wskaznik do przechowywanego
///    obiektu SubaruCar 
/// -- musi istniec metoda 'sell', pobierajaca nr inwentaryzacyjny
///    jako argument
///    ktora usuwa sprzedany samochod (czyli obiekt SubaruCar) 
///    z inwentarza (kontenera);
///    cena sprzedanego samochodu musi powiekszac zarobek salonu
/// -- musi istniec metoda 'get_income' zwracajaca zarobek salonu
/// -- musi istniec metoda 'get_all_dealers_income' zwracajaca
///    zarobek wszystkich salonow
//
#include "cardealer.h"
// --------------------------------------------------------------------     


#include<iostream>


int main() {
	
	std::cout << "\n";

	// Tworzymy dwa salony samochodowe:
	SubaruDealer AutoLarusso(10), // salon miesci 10 pojazdow
		     JapanMotors(3);  // maly salon na 3 pojazdy

		// zaopatrujemy salon w samochody   (model,r.prod, przebieg)  nr invent., cena
	AutoLarusso.new_inventory(  SubaruCar("Forester",2017,3132)   ,1001,18000);
	AutoLarusso.new_inventory(  SubaruCar("Forester",2019,3)     ,1002,28000);
	AutoLarusso.new_inventory(  SubaruCar("Outback",2014,14134)  ,1005,12000);
	AutoLarusso.new_inventory(  SubaruCar("Impreza",2019,5)      ,1006,27000);

	
// zaopatrujemy salon w samochody
	JapanMotors.new_inventory(  SubaruCar("Outback",2018,12012)  ,2003,24000);
	JapanMotors.new_inventory(  SubaruCar("Legacy",2017,5112)    ,2004,30100);
	JapanMotors.new_inventory(  SubaruCar("Forester",2019,6)     ,2005,28400);
	JapanMotors.new_inventory(  SubaruCar("Outback",2012,45666)  ,2008,10000);


	std::cout << "\n";

	// 'Ogladamy' samochod o nr inwentaryzacyjnym 1002
	SubaruCar* car = AutoLarusso.show(1002);
	std::cout << "model: " << car->get_model() << ", " 
		  << "year: " << car->get_year()  << ", " 
		  << "mileage: " << car->get_mileage() << std::endl;

	
	std::cout << "\n";


	// sprzedajemy samochody
	AutoLarusso.sell(1002);
	AutoLarusso.sell(1001);

	JapanMotors.sell(2005);
	JapanMotors.sell(2005);
	JapanMotors.sell(2003);


	// posumowanie sprzedazy
	std::cout << "AutoLarusso income: " << AutoLarusso.get_income() << std::endl;
	std::cout << "JapanMotors income: " << JapanMotors.get_income() << std::endl;
	std::cout << "All dealers total income: " << SubaruDealer::get_all_dealers_income() << std::endl;


	std::cout << "\n";

return 0;}

