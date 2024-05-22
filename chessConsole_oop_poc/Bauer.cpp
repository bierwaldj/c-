#include "Bauer.h"
#include "Spiel.h"
#include <string>
#include <iostream>

#define DEBUG 1

Bauer::Bauer(std::string typ, bool f)
{
	figurTyp = f ? "B" : "b";
	figurFarbe = f;

}

std::vector<std::string> Bauer::erlaubteZieleberechnen(std::string f)
{
	if (DEBUG)
	{
		std::cout << __func__ << " Bauer auf " << f << "\n";
	}
	std::vector<std::string> eF; //erlaubte Felder

	// Bauer darf alles
	for (auto& feld : Spiel::spielStand) {
		eF.push_back(feld.first);
	}


	return eF;
}


