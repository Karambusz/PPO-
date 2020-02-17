#include "book.h"
#include <utility>

//funkcja zwracajaca imie i nazwisko autora
//funkcja typu const by zapewnic brak zmian zmiennej _autor
std::string Book::get_author() const
{
    return _autor;
}

//konstruktor kopiujacy
//konstruktor przyjmuje jako argument referencje do obiektu klasy Book
//konstruktor kopiuje zawartosc obiektu klasy Book
Book::Book(const Book &x)
{
    _tytul = x._tytul;
    _autor = x._autor;
    _rok_wydania = x._rok_wydania;
    _gatunek = x._gatunek;
    _numer_ISBN = x._numer_ISBN;
}

//konstruktor przenoszacy
//Konstruktor przyjmuje jako argument referencje do r-value
Book::Book (Book &&x): _tytul(std::move(x._tytul)), _autor(std::move(x._autor)), _rok_wydania(std::move(x._rok_wydania)), _gatunek(std::move(x._gatunek)), _numer_ISBN(std::move(x._numer_ISBN))
{
}
