#include<iostream>

#include "particle.h"

/// funkcja wpisuje danne do wezlow listy
void SetParticle(Particle &particle, const char* name, double mass){
particle.name = name;  /// przypisania nazwy
particle.mass = mass; /// przypisania masy
}


