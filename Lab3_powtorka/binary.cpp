/// Prosta biblioteka do konwersji MyString na reprezentacje binarna
/// oraz drukowania jej na ekran.

/// UWAGA: nie wolno modyfikowac tego pliku.


#include <iostream>
#include "binary.h"


/// Funkcja oblicza reprezentacje binarna napisu MyString
/// i zachowuje ja w przekazanym do funkcji (jako referncja) obiekcie typu Binary.
/// Funkcja zwraca dlugosc otrzymanego ciagu bitow.
unsigned int ObtainBinary(MyString *str, Binary &binary) {

	// Zabezpieczamy sie przed zerowym wskaznikiem str
	if (str != NULL) {
		// zapisujemy dlugosc wlasciwego textu (dl. ciagu znakow, minus znak terminacji 0)
		unsigned int length = str->length-1;
		// ilosc bitow w bajcie
		const unsigned NofBits = 8;
		// obliczamy dl. potrzebnego ciagu bitow
		unsigned int binlength = length*sizeof(char)*NofBits;

		// Niszczymy ewentualny niepusty obiekt Binary, przed utworzeniem nowego.
		// Uwaga: zakladamy, ze zawsze wskazniki sa poprawnie zainicjalizowane.
		if (binary != NULL) {
			std::cout << "ObtainBinary: Warning: passed non-null Binary object. Has been deleted." << std::endl;
			delete [] binary;
		}
		// tworzymy nowy obiekt typu Binary
		binary = new bool[binlength]; // bool = true,false; odpowiada 1,0

		// Konwersja decymal -> binary
		for (unsigned i=0;i<length;++i) {
			unsigned int ascii = (unsigned int) str->str[i];
			unsigned int N = 1<<(NofBits-1);// przesuniecie w lewo o (NofBits-1) bitow
			unsigned int j = 0;
			for (;N>0;N=N/2) {
				if (ascii & N) // binarne AND (czyli bit-po-bicie AND)
				       	binary[8*i+j] = 1;
				else
					binary[8*i+j] = 0;
				j++;
			}
		}

		return binlength;

	}
	else {
		std::cout << "ObtainBinary: passed a NULL string. Nothing's been done to binary." << std::endl;
		return 0;
	}
}


/// Funkcja do drukowania reprezentacji binarnej na ekran
void PrintBinary(Binary binary, unsigned int binlength) {
	for (unsigned i=0;i<binlength;++i)
		std::cout << binary[i];
        std::cout << std::endl;
}

/// Funkcja do drukowania reprezentacji binarnej napisu MyString na ekran
void PrintBinary(MyString *str) {
	Binary binary = NULL;
	unsigned int l = ObtainBinary(str,binary);
	PrintBinary(binary,l);
	if (binary != NULL) 
		delete [] binary;
}
