#include "Figur.h"
#include "Spiel.h"
#include <vector>
#include <iostream>

#define DEBUG 1

Figur::Figur()
{
	figurTyp = " ";
	
}

Figur::Figur(std::string t, bool f) 
{
	figurTyp = " ";
	figurFarbe = f;
}

void Figur::set_figurTyp(std::string t)
{
	figurTyp = t;
}

void Figur::set_figurFarbe(bool f)
{
	figurFarbe = f;
}

std::vector<std::string> Figur::erlaubteZieleberechnen(std::string f)
{
	if (DEBUG)
	{
		std::cout << __func__ << " auf Feld " << f << "\n";
}
	std::vector<std::string> eF; // { "Berechne erlaubte Felder f�r Basisklasse Figur " + f };
 
	return eF;
}

bool Figur::aufDemSpielfeld(std::string zielFeld)
{
	//return zielFeld.at(0) >= 'A' && zielFeld.at(0) <= 'H' &&
	//	   zielFeld.at(1) >= '1' && zielFeld.at(1) <= '8'; 

	if (zielFeld.at(0) >= 'A' && zielFeld.at(0) <= 'H' &&
		zielFeld.at(1) >= '1' && zielFeld.at(1) <= '8')
		return true;
	return false;

}



bool Figur::eigeneFigur(std::string feld1, std::string feld2)
{

	return aufDemSpielfeld(feld2) &&
		Spiel::spielStand[feld1].figur->get_figurFarbe() == Spiel::spielStand[feld2].figur->get_figurFarbe() &&
		Spiel::spielStand[feld2].figur->get_figurTyp() != "Leer";
}


bool Figur::nichtLeer(std::string f)
{
	return Spiel::spielStand[f].figur->get_figurTyp() != "Leer";


}


