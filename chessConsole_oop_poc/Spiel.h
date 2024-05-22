#pragma once
#include <map>
#include <string>
#include <array>
#include "Feld.h"
#include "config.h"

class Spiel
{
	std::array<std::string, 2> spielerName{ "sp1","sp2" };
	int zugNumer{ 0 };
public:

	Spiel();  // Grundstellung

	static std::map<std::string, Feld> spielStand;
	// z.B  spielstand["A7"] enth�lt ein Feld mit einem dunklen Bauern
	// in jedem Feld ist eine Liste hinterlegt, welche Felder im
	// n�chsten Zug erreicht werden k�nnen

	void ausgeben();
	void bewegen(std::string vonNach);
	void bewegen();

};

