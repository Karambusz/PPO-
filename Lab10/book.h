#ifndef book_h
#define book_h
#include <iostream>
#include <string>

enum Genre
{
    thiller,
    crime,
    sci_fi,
    undefined
};

/* ******************

     Klasa Book - klasa implementujaca informacje na temat ksiazki w programie

****************** */
class Book
{
    public:

        friend class Library; 
        std::string get_author() const;

        //konstruktor default
        Book(std::string tytul, std::string autor, short unsigned rok_wydania, Genre gatunek, long unsigned numer_ISBN): _tytul(tytul), _autor(autor), _rok_wydania(rok_wydania), _gatunek(gatunek), _numer_ISBN(numer_ISBN){}
        
        Book(const Book &x);
    
        Book(Book &&x); 

        //operator konwersji z Book na string
        operator std::string() {return _tytul;}
        
        //operator konwersji z Book na typ wyliczeniowy enum
        operator Genre() {return _gatunek;}

        //operator konwersji z Book na short unsigned int
        operator short unsigned() {return _rok_wydania;}

        //operator konwersji z Book na long unsigned int
        operator long unsigned () {return _numer_ISBN;}

    private:

        std::string  _tytul;
        std::string  _autor;
        short unsigned _rok_wydania;
        Genre _gatunek;
        long unsigned _numer_ISBN;
};







#endif
