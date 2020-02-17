#include<iostream>
#include <string>
#include "library.h"
#include "book.h"
#include <cstring>


//Konstruktor zwykly
//konstruktor przyjmuje jako argument pojemnosc obiektu klasy Library
//konstruktor alokuje pamiec na tablice wskaznikow
Library::Library(int _size){

    size = _size;
    tab = new Book *[size];
    index = 0;
}
//Konstruktor kopiujacy
//konstruktor przyjmuje jako argument referencje do obiektu klasy Library
//konstruktor kopiuje zawartosc obiektu klasy Library
Library::Library(Library &tmp){
    index = tmp.index;
    size = tmp.size;
    tab = new Book *[size];
    for(int i=0; i<index; i++){
        tab[i] = new Book(*tmp.tab[i]);
    } 
}

//Konstruktor przenoszacy
//Konstruktor przyjmuje jako argument referencje do r-value
Library::Library(Library &&tmp){
    index = tmp.index;
    size = tmp.size;
    tmp.index = 0;
    tmp.size = 0;
    tab = tmp.tab;
    tmp.tab = nullptr;
}

//Destruktor
Library::~Library(){
    if(tab){
        for(int i =0; i<index; i++){
            delete tab[i];
        }
        delete [] tab;
    }
}

//funkcja ktora zwraca tablice obiektow klasy Book
Book ** Library::get_books(){
    return tab;
}

//funkcja ktora zwraca wskaznik na obiekt klasy Book
//funkcja pobiera jako argument zmienna title
//f szuka ksiazki o tytule ktory zgadza sie ze zmienna title
Book * Library::get_book(std::string _title){
    for(int i = 0; i<index; i++){
        
        if(tab[i]-> _tytul == _title)
        return tab[i];
    }
    return nullptr;
}

//funkcja zwraca ilosc ksiazek, u nas opisana jako zmienna index
unsigned int Library::get_n_books(){
    return index;
}


//funkcja dodaje ksiazke do tablicy
//argumentem fumkcji jest typ Book 
void Library::new_book(Book tmp){
    if(index >= size){
        return;
    }
    tab[index] = new Book(tmp);
    index ++;
}
