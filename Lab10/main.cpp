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
/// b) program musi się kompilować z flagami '-Wall -g', jako minimum
/// c) Jako rozwiązanie, proszę przeslać spakowany katalog źrodlowy, 
///    WŁĄCZAJĄC plik main.cpp, ale BEZ katalogu 'build'. 
/// d) Nie wolno modyfikować pliku main.cpp.
//  --------------------------------------------------------------------------------- 
///
///    \n\n


/// ZESPOL: Vadym Semkovych i Bartosz Mikolajczyk


#include<iostream>
#include <fstream>


// -------------------------------------------------------------------------------
//
/// *** Klasa Book ***
///
/// 1) Klasa implementuje następujące informacje nt. książki:
///    -- tytuł,
///    -- autor,
///    -- rok wydania
///    -- gatunek (ang. genre)
///       Gatunek musi być typu 'Genre' zaimplementowany jako enum
///       (poza klasą).
///       Należy uwzględnić następujące gatunki:
///        -- thiller,
///        -- crime,
///        -- sci_fi,
///        -- undefined
///    -- numer ISBN
///    Typy powyższych danych należy dobrać odpowiednio do przechowywanych 
///    danych (patrz funkcja main).
/// 2) Metody zwracające przechowywane dane muszą być rozwiązane następująco:
///    -- autor jest zwracany metodą 'get_author'
///    -- pozostałe dane są zwracane odpowiednimi operatorami konwersji
///       (patrz fcja main), tak aby program działał poprawnie.
/// 3) Należy również zaimplementować konstruktory cp/mv.
/// 
#include "book.h"
// -----------------------------------------------------------------------------


// ------------------------------------------------------------------------------
//
/// *** Klasa Library ***
///
/// Klasa implementuje bibliotekę przechowującą książki. 
/// -- Należy użyć dynamicznej tablicy wskaźników Book** jako kontenera.
/// -- Musi być metoda 'get_books' zwracającą tablicę książek w bibliotece (patrz fcja main).
/// -- Musi być metoda 'get_book' zwracająca wskaźnik do książki o podanym tytule (patrz fcja main).
/// -- Musi być metoda 'new_book' dodająca książkę do biblioteki.
/// -- Musi być metoda 'get_n_book' zwracająca liczbę książek w bibliotece. 
/// -- Konstruktor musi określać maksymalny rozmiar bibioteki (pojemność książek).
/// -- Klasa musi posiadać konstruktory cp/mv.
///
#include "library.h"
// -------------------------------------------------------------------------------


//  -------------------------------------------------
/// Szablon funkcji testującej konstruktory cp/mv
template <class Type> Type  mkcopy(Type obj) {
	return obj; }
//  -------------------------------------------------


//  ---------------------------------------------------------------------
/// Przeładowanie operatora >> aby odczytać typ Genre z pliku
/// ** Proszę się zapoznać (np. w domu) z jego działaniem! **
std::istream& operator >> (std::istream& cin_, Genre& genre) {
	std::string genre_str;
	cin_ >> genre_str;
	if (genre_str=="thiller") genre=thiller;
	else  
	if (genre_str=="crime") genre=crime;
	else
	if (genre_str=="sci-fi") genre=sci_fi;
	else
	   genre=undefined;
	return cin_;
}
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
/// Przeładowanie operatora << aby drukować typ Genre do std wyjścia.
/// ** Proszę się zapoznać (np. w domu) z jego działaniem! **
std::ostream& operator << (std::ostream& cout_, const Genre& genre) {
		switch (genre) {
			case thiller: cout_ << "thiller"; break;
			case crime: cout_ << "crime"; break;
			case sci_fi: cout_ << "sci-fi"; break;
			default: cout_ << "undefined";
		}
		return cout_; }
// -----------------------------------------------------------------------



// =======================================================================
int main() {
	

	std::cout << "\n";

	// Tworzymy bibliotekę o pojemności wstępnej 100 książek.
	Library NY_library(100);

	// Otwieramy plik o nazwie books.in, zawierający pozycje
	// książkowe, które dodamy do biblioteki.
	std::ifstream file("books.in");

	// Poniższy blok instrukcji wprowadza książki 
	// do biblioteki NY_library
	if (file) {

		// Definiujmey zmienne do przechowania danych
		// z pliku; dla każdego pola w wierszu pliku
		// (oddzielonych spacją) mamy jedną zmienną.
		std::string lastname, firstname, title, author;
		short unsigned year;
		Genre genre;
	        long ISBN;

		// Wczytujemy dane do zmiennych, następnie wprowadzamy
		// do obiektu NY_library. Powtarzamy, aż dojdziemy
		// do końca pliku.
		while(	file >> firstname >> lastname >> title
			     >> year >> genre >> ISBN ) {

			// Pole 'autor' w klasie Library przechowuje
			// imię i nazwisko razem:
			author = firstname+" "+lastname;

			// Definiujmey obiekt książki na podstawie
			// danych z pliku.
			Book book(title,author,year,genre,ISBN);

			// Wprowadzamy książkę do biblioteki.
			// (następuje test konstruktorów cp/mv)
			NY_library.new_book(mkcopy(book));	}
	}
	else {
		std::cout << "ERROR: unable to open the file." << std::endl;
		exit(1); }



	// Wypisujemy książki w bibliotece:
	
	for (unsigned k=0; k<NY_library.get_n_books(); ++k) {

		Book* book=NY_library.get_books()[k];
		std::string title = *book;
		short unsigned year = *book;
		Genre genre = *book;
		long unsigned ISBN = *book;

		std::cout << title << ", " 
			  << book->get_author() << ", "
			  << year << ", "
			  << genre << ", "
			  << ISBN << std::endl;   }


	
	// Testujemy konstruktor cp/mv
	Library NY_library_cp(mkcopy(NY_library));
	
	std::cout << "\n";

	// Wyszukajmy książkę o zadanym tytule (w kopii biblioteki):
	std::string src_title[] {"Cujo","Institute"};
	
	for (unsigned k=0; k<sizeof(src_title)/sizeof(std::string); ++k) {

		std::cout << "Looking for book: " << src_title[k] << " ... ";
		Book* book = NY_library_cp.get_book(src_title[k]);
		if (book) 
			std::cout << "  found. Author: " << book->get_author() << std::endl;
		else
			std::cout << "  not found." << std::endl;
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
