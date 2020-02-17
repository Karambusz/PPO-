/// \file main.cpp
/// \mainpage
///
/// Program implememtuje 'robota' na 2D plaszczyznie.
/// Roboty moga wykonywac dwie operacje: ruch wkierunku x lub y
/// o zdana liczbe pol.
/// W jednym punkcie nie moze znajdowac sie wiecej niz 1 robot. 
/// Nakladamy ograniczenie na maskymalna liczbe robotow: 5; \n\n
///
///
/// Nalezy utworzyc brakujace pliki naglowkowe
/// i utworzyc w nich odpowiedni kod, tak aby 
/// program sie kompilowal i poprawnie wykonywal,
/// dajac DOKLADNIE wynik podany na koncu tego pliku.
/// Prosze NIE UZYWAC klas (mozna uzywac struktur, ale tylko jako 
/// POD -- plain-old-data). 
/// 
/// Wskazowki:
/// -- W miare mozliwosci prosze uzyc alokacji pamieci w stylu C++
///    tj. zamiast: 
///    Typ *wsk = (Typ*) malloc(sizeof(Typ)); oraz free(wsk);
///    uzywamy:
///    Typ *wsk = new Typ; oraz delete wsk;
///
///    \n\n
///
/// Zasady ogolne pracowni: \n
/// 1) Nie wolno modyfikowac pliku main.cc oraz ewentualnych innych 
///  plikow gdzie jest to explicite zastrzezone odpowiednim komentarzem. \n 
/// 2) Nie wolno korzystac z pomocy kolegow/prowadzacego, internetu, notatek,
/// ani zadnych innych materialow (w tym wlasnych wczesniej
/// przygotowanych plikow).\n
/// 2) Kod zrodlowy musi znajdowac sie w katalogu o prawach dostepu 
/// tylko dla uzytkownika.\n
/// 3) Nalezy zadbac o przejrzystosc programu oraz dobre zarzadzanie pamiecia.\n
/// 4) Punktacja: poprawna kompilacja - 2pkt, poprawne wyjscie oraz brak wyciekow pamieci -- 3pkt,
/// dokumentacja -- 1pkt, ocena kodu -- max 4pkt. Kod MUSI sie kompilowac aby byl w ogole oceniany.
///
/// POWODZENIA!


#include<iostream>
#include <cstdlib>
#include<string>

#include "robots.h"


int main() {

	
	std::cout << "\n";

	// Tworzymy robota nr 1 w punkcie x=0, y=0
	Position pos1 = {0,0};
	Robot *robot1 = InitializeRobot("Alice",pos1);
	// Robocie, odezwij sie
	 EchoRobot(robot1);
	
	// Tworzymy robota nr 2
	Position pos2 = {5,-3};
	Robot *robot2 = InitializeRobot("Bob",pos2);
	EchoRobot(robot2);

	// Proba utworzenia 3go robota
	Robot *robot3 = InitializeRobot("Freddy",pos1);
	EchoRobot(robot3);

	// Proba utworzenia kolejnych robotow
	for (int i=1;i<5;++i) {
		Position pos = {i*2,i*3};
		Robot *robot = InitializeRobot(pos);
		EchoRobot(robot); 
	}

	std::cout << "\n";
	
	// Przesuwamy robota nr 1 o dx=1 i dy=3
	MoveX(robot1,1);
	MoveY(robot1,3);
	EchoRobot(robot1);
	
	std::cout << "\n";

	// Proba przesuniecia robota 1
	MoveX(robot1,4);
	MoveY(robot1,-6);
	EchoRobot(robot1);


	std::cout << "\n";

	// Kilka operacji na robocie
	Operation moveXY[] = {MoveX,MoveY,MoveX,MoveY,MoveY};
	int shifts[] = {-2,3,5,100,-23};
	int opsize = sizeof(moveXY)/sizeof(Operation);
	for (int i=0;i<opsize;++i) 
		moveXY[i](robot2,shifts[i]);
	EchoRobot(robot2);

	DeleteRobots();

return 0;}

/*
> Hello, I'm robot Alice at x=0, y=0.
> Hello, I'm robot Bob at x=5, y=-3.
InitializeRobot: Two robots cannot be placed in the same position.
EchoRobot: No such robot.
> Hello, I'm robot noname at x=2, y=3.
> Hello, I'm robot noname at x=4, y=6.
> Hello, I'm robot noname at x=6, y=9.
InitializeRobot: No space for an additional robot.
EchoRobot: No such robot.

> Hello, I'm robot Alice at x=1, y=3.

MoveY: Cannot place robots in the same position.
> Hello, I'm robot Alice at x=5, y=3.

> Hello, I'm robot Bob at x=8, y=77.
*/
