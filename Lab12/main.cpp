/// \file main.cpp
/// \mainpage
///
/// \n\n
///
/// UWAGA: należy użyć doxygen aby wygenerować czytelną instrukcję (zawiera wzory) 
/// (aby wygenerować pdf należy w katalogu latex wydać komndę 'make')\n 
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
/// *** Klasa Polynomial ***
/// 
/// Klasa implementuje wielomian zmiennej rzeczywistej określonego stopnia:
/// \f[ W_n(x) = a_1 + a_2 x + a_3 x^3 + \dots + a_n x^n \f]
/// Minimalne składniki klasy to:\n
/// 1) dynamiczna tablica współczynników wielomianu.\n
///    Współczynniki wielomianu \f$ a_1,\dots,a_n \f$ są typu double.\n
/// 2) Konstruktory, w tym kopiujący, przenoszący.\n
///    -- Jeden z konstruktorów tworzy wielomian podając stopień wielomianu
///    oraz tablicę współczynników (przykład: patrz fcja main).\n
///    -- Jeden z konstruktorów tworzy wielomian o zadanym stopniu o tablicy
///    współczynników inicjowanej zerami. \n
/// 3) Operatory przypisania kopiującego, przenoszącego\n
/// 4) Operator () wyliczający wartość wielomianu dla zadanego argumentu
///    (przykład: patrz fcja main)\n
/// 5) Operator += dodający wielomiany (przykład: patrz fcja main)\n
/// 6) Operator * mnożący wielomian przez liczbę (przykład: patrz fcja main) 
/// 7) Operator << drukujący wielomian w formacie widocznym w pliku output.txt \n\n
///        
/// -------------------------------------------------------------------------------
///  
/// *** Klasa Legendre ***
/// 
/// Klasa pochodna klasy Legendre. Implementuje wielomiany Legendre'a.\n
/// Wielomiany Legendre'a są rozwiązaniami pewnego równania różniczkowego,
/// i są szeroko stosowane w fizyce i informatyce. \n
/// Klasa powinna posisadać:\n
/// 1) metodę obliczającą współczynniki wielomianu Legendre'a
///    Współczynnik \f$ a_l \f$ wielomianu stopnia \f$ n \f$ 
///     można otrzymać z następującego bezpośredniego wzoru:
///    \f[
///    a_l = \frac{(-1)^{\frac{n-l}{2}}}{2^n}
///    \frac{ (n+l)! } 
///    { (\frac{n-l}{2})! (\frac{n+l}{2})! l! } ,
///    \f]
///    gdzie \f$ l=0,2,4,\dots \f$ jeśli \f$ n \f$ -parzyste
///    oraz \f$ l=1,3,5,\dots \f$ jeśli \f$ n \f$ -nieparzyste.
///    Jako silni można użyć funkcji std::tgamma,
///    n! = std::tgamma(n+1).\n
/// 2) Konstruktory, w tym kopiujący, przenoszący\n
///    Jeden z konstruktorów ma tworzyć wielomian Legendre'a o zadanym stopniu.\n
/// 3) Operatory przypisania kopiującego, przenoszącego.


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#include "polynomial.h"
#include "legendre.h"


// =======================================================================
int main() {

	std::cout << "\n";

	// Tablica współczynników wielomianu {a_0,a_1,...,a_n}	
	double coefs1[] {0.333,3.14,0,1.42,2.72}; 
	// Stopień wielomianu (wymiar tablicy minus 1)
	const int n1 = sizeof(coefs1)/sizeof(coefs1[0])-1;;
	// Tworzymy wielomian
	Polynomial W1(n1,coefs1);
	// Wypisujemy wielomia i jego wartość dla x=6.28
	cout <<  W1 << "\t\t\t"<< W1(6.28) << endl;

	// Tworzymy drugi wielomian
	const int n2 = 5;
	double *coefs2 = new double[n2+1] {1.,2.,3.,4.,5.,6.};
	Polynomial W2(n2,coefs2);

	// Dodajemy do W1 W2, wyświetlamy, oraz wyliczamy wartość dla x=6.28
	cout << (W1+=W2) << "\t" << W1(6.28) << endl;


	cout << "\n-------------------------------------------------------------\n" << endl;

	// Tworzymy wektor pierwszych 50 wielomianów Legendre'a
	vector< Legendre > P;
	const int N=50;
	for (int k=0;k<N;++k)
		P.push_back( Legendre(k) );

	// Wyświetlamy pierwszych pięć wielomianów
	for (int k=0;k<=4;++k) 
		cout << "P" << k << "(x) = " << P[k] << endl; 

	std::cout << "\n";

	// Testujemy pewien wzór znany z teorii wielomianów.
	// Sprawdzimy, czy da się wyliczyć dla t=1/2 
	double t=0.5;
	// następującą wartość:
	double val = 1./sqrt(1+pow(t,2)); 
	// Wartość ta dana jest nieskończoną sumą wielomianów P_k(0)*t^k.
	// My mamy 50 wielomianów.
	double val_P=0;
	Polynomial U(N); // Wielomian o wsp. będących zerami (wielomian 'zerowy')
	for (int k=0;k<N;++k) {
		val_P += P[k](0)*pow(t,k); // pierwszy sposób; testuje operator()
		U += P[k]*pow(t,k); }  // drugi sposób; testuje operator +=
	// Wypisujemy wynik uzyskany dwoma sposobami, oraz prawdziwą wartość
	cout << val_P << "  " << U(0) << "  " << val << endl;

	delete [] coefs2;
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
