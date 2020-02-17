/// Biblioteka implemetujaca proste szyfrowanie XOR.
/// Polega ona na rozkladzie szyfrowanego wyrazenia oraz hasla na
/// pojedyncze bity i zastosowaniu operacji exclusive OR (XOR)
/// do kazdej pary bitow.
/// Czyli: (message XOR passphrase) = encoded_message,
/// gdzie operacja XOR dziala na pojedyncze bity, zas passphrase 
/// jest powtarzane cyklicznie.
/// Odszyfrowanie wiadomosci:
/// (encoded_message XOR passphrase) = message

/// UWAGA: Nie wolno modyfikowac tego pliku.

#include "cipher.h"

#include <iostream>
#include <cmath>


/// Funkcja szyfrujaca.
/// Funkcja zwraca wskaznik do typu char, pod ktorym bedzie zaalokowana 
/// pamiec dla zaszyfrowanego napisu (nalezy pamietac o jej zwolnieniu).
/// Dwa argumenty to MyString'i napisu do zaszyfrowania oraz hasla.
char* Encode(MyString* str, MyString* passwd) {

	// Obliczamy reprezentacje binarna napisu str i zapisujemy dlugosc
	Binary binin = NULL;
	unsigned binin_l = ObtainBinary(str,binin);

	// Obliczamy reprezentacje binarna hasla i zapisujemy jego dlugosc
	Binary binpass = NULL;
	unsigned binpass_l = ObtainBinary(passwd,binpass);

	// Tworzymy tablice na repr.  binarna hasla powtarzanego cyklicznie,
	// tak, zeby dlugosc binarna byla taka jak dla napisu str
	Binary binpass_ext = new bool[binin_l];
	// Wypelniamy ta tablice
	unsigned m = 0;
	for (unsigned k=0;k<binin_l;++k) { 
		if (m>=binpass_l) 
			m=0;	
		binpass_ext[k] = binpass[m];
		++m;
	}

	// Tworzymy tablice na zaszyfrowany napis w repr. binarnej
	Binary binout = new bool[binin_l];
	// Wypelniamy ta tablice, szyfrujac operacja XOR
	for (unsigned int l=0;l<binin_l;++l) 
		binout[l] = XOR(binin[l],binpass_ext[l]);

	// Robimy konwersje do reprezentacji decymalnej,
	// tak aby po 8 bitow skladalo sie na liczbe (lub znak ASCII).
	const int NBit = 8; // liczba bitow 
	unsigned Nchars = binin_l/NBit+1; // plus 1 bo musimy uwzglednic '\0' na koncu
	char* textout = new char[Nchars]; // tutaj alokujemy pamiec do wyjsciwego napisu
	char* textout_begin = textout; // zapamietujemy wskaznik do poczatku tablicy
	// Przeliczamy...
	for (unsigned p=0;p<binin_l;p=p+NBit) {
		*textout=0; // inicjalizujemy zerem
		for (unsigned l=0;l<NBit;++l) 	
			*textout += binout[p+l]*pow(2,NBit-l-1);
		if (*textout==0) { // Uwaga na zero -- powoduje problemy bo urywa ciag tekstowy...
			std::cout << "Encode: 0 character encountered while encoding, please choose another passphrase." << std::endl;
			delete [] textout;
			return NULL;	
		}
		textout++;
	}
	*textout = '\0'; // dodajemy znak konca ciagu znakow
	textout = textout_begin; // cofamy wskaznik na poczatek tablicy


	// Czyscimy...
	delete [] binin;
	delete [] binout;
	delete [] binpass;
	delete [] binpass_ext;

	return textout;
}


/// Funkcja deszyfrujaca. Wystarczy zaaplikowac operacje XOR na bitach.
/// Ponownie uwaga: zostanie zaalokowana pamiec na napis wskazany przez textdec
/// -- patrz opis funkcji Encode
char* Decode(MyString* str, MyString* passwd) {
	return Encode(str,passwd);
}
