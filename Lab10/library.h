#ifndef library_h
#define library_h
#include "book.h"
#include<iostream>

/* ***************************

    Klasa Library - klasa implementujaca biblioteke z ksiazkami w niej

**************************** */



class Library{
private:
    Book **tab;
    int index;
    int size;
public:
    Library(int _size);
    ~Library();
    Library(Library &tmp);
    Library(Library &&tmp);
    Book **get_books();
    Book *get_book(std::string _title);
    unsigned int get_n_books();
    void new_book(Book tmp);


};



#endif