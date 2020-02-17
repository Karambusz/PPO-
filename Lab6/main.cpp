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
/// Dodatkowe zastrzezenia (UWAGA: brak spelnienia ktoregokolwiek = 0 pkt):
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
///     wlaczajac main (nie wysylamy skompilowanych bibliotek ani pliku wykonywalnego)
/// d) Nie wolno modyfikowac pliku main.cpp.
/// 
///
///    \n\n


#include<iostream>

/// Plik naglowkowy deklarujacy klase Coin, ktora implementuje
/// monete PLN lezaca na stole. Moneta taka lezy losowo 'orlem' (ang. heads) 
/// lub 'reszka' (ang. tails) do gory i posiada wartosc.
/// Zarowno mozliwe wartosci monety (1PLN, 2PLN, 5PLN), jak i
/// widoczna strona monety (heads,tails) powinny byc zdefiniowane 
/// jako nowe typy enum.
/// UWAGA: przynajmniej jedna metoda klasy musi zostac zdefiniowana w pliku
///        zrodlowym coin.cpp
//
#include "coin.h"

/// Plik naglowkowy deklarujacy klase Piggybank. Jest to skarbonka
/// o rozmiarze (maksymalnej liczbie monet) definiowanym podczas 
/// tworzenia instancji klasy.
/// UWAGA 1: nie wolno uzywac kontenerow.
/// UWAGA 2: przynajmniej jedna metoda klasy musi zostac zdefiniowana w pliku
///          zrodlowym piggybank.cpp
//
#include "piggybank.h"


int main() {
	
	std::cout << "\n";

	srand (232113443); // seed dla generator licz pseudo losowych


	unsigned pigsize = 12; // rozmiar skarbonki
	Piggybank pig1(pigsize); // tworzymy skarbonke

	Coin onePLN; // tworzymy monete na stole (losowo jest 'orzel' lub 'reszka')
	std::cout << "I tossed " << onePLN.get_coin_value() << " PLN and got:" << std::endl;
	onePLN.print_side_up(); // wyswietla czy orzel czy reszka
	// rzucamy dopoki nie wypadnie reszka
        while (onePLN.get_side_up()!=tails) {
                onePLN.toss();
                onePLN.print_side_up();
        }
	std::string info("I put my coin to the piggybank.");
	std::cout << info << std::endl;
	pig1.put_coin(onePLN); // wrzucamy monete do skarbonki

	Coin fivePLN(five);
	std::cout << "I tossed " << fivePLN.get_coin_value() << " PLN and got:" << std::endl;
	fivePLN.print_side_up();
	std::cout << info << std::endl;
	pig1.put_coin(fivePLN);

	Coin twoPLN(two);
	std::cout << "I tossed " << twoPLN.get_coin_value() << " PLN and got:" << std::endl;
	twoPLN.print_side_up();
	pig1.put_coin(twoPLN);
	std::cout << info << std::endl;


	// wyswietlamy kwote w skarbonce
	std::cout << "\nMy piggybank has " << pig1.get_tot_value() << " PLN in total." << std::endl;


	std::cout << "\n++++++++++++++++++++++++++++++\n\n";

	// nowa skarbonka i test przepelnienia
	unsigned pig2size = 33;
	Piggybank pig2(pig2size);
	for (unsigned k=0;k<pig2size+1;++k) {
		Coin coin;	
		pig2.put_coin(coin); }
	std::cout << "\nMy piggybank has " << pig2.get_tot_value() << " PLN in total." << std::endl;

	std::cout << "\n";

return 0;}

