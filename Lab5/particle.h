#ifndef particle_h
#define particle_h

// ** UWAGA ** NIE MODYFIKOWAC

#include <iostream>

/// Struktura zapamietujaca nazwe czastki i jej mase
struct Particle {
	const char* name;
	double mass;
};


/// Funkcja wpisuje dane do podanego obiektu typu Particle
/// (pierwszy argument przekazany przez referencje). 
void SetParticle(Particle &particle, const char* name, double mass);

/// Funkcja drukuje obiekt typu particle
inline void PrintParticle(const Particle &particle) {
	std::cout << particle.name << "(" << particle.mass << ")" << std::endl;
}

#endif
