#include "Turm.h"
#include <iostream>
#include "Spiel.h"

#define DEBUG 1

Turm::Turm(std::string t, bool f)
{
	figurTyp = f ? "T" : "t"; 
    figurFarbe = f;
}

std::vector<std::string> Turm::erlaubteZieleberechnen(std::string f)
{
	std::vector<std::string> eF; //erlaubte Felder
	// alle erlaubten Felder für Turm berechnen und eintragen

	// vom feld (f)  auf dem wir stehen ausgehend 
	// in zeilen und spalten nach rechts links oben unten
	// je 1 Feld solange bis wir auf ein besetzes Feld stoßen
	// wenn Feld besetzt, dann wenn eigen -> stop, wenn fremd schlagen, dann stop
	// 

	// f = key // A1 / H7 usw.

	std::cout << f << " <-- Start der Zielberechnung\n";

	char z;
	char s;
	std::string ziel{ 2,'\0' };

	/// oben unten
	ziel[0] = f[0];

	// Turm geht nach oben
	z = f[1];
	while (z < '8')
	{
		z++; // '1' + 1 = '2'
		ziel[1] = z; // "A2"
		std::cout << ziel << " <-- Ziel zähler in Schleife \n";
		if (Spiel::spielStand[ziel].figur->figurTyp == " ") // figur auf feld leer?
		{
			eF.push_back(ziel);
		}
		else
		{
			if (Spiel::spielStand[ziel].figur->figurFarbe != figurFarbe)
			{
				eF.push_back(ziel);
				if (DEBUG) {
					std::cout << "\n" << f << " kann " << ziel << " schlagen\n";
				}
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "\nEigene Figur auf " << ziel << " kann nicht geschlagen werden\n";
				}
			}
			break;
		}
	}

	// Turm geht nach unten
	z = f[1];
	while (z > '1')
	{
		z--; // '1' + 1 = '2'
		ziel[1] = z; // "A2"
		std::cout << ziel << " <-- Ziel zähler in Schleife \n";
		if (Spiel::spielStand[ziel].figur->figurTyp == " ") // figur auf feld leer?
		{
			eF.push_back(ziel);
		}
		else
		{
			if (Spiel::spielStand[ziel].figur->figurFarbe != figurFarbe)
			{
				eF.push_back(ziel);
				if (DEBUG) {
					std::cout << "\n" << f << " kann " << ziel << " schlagen\n";
				}
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "\nEigene Figur auf " << ziel << " kann nicht geschlagen werden\n";
				}
			}
			break;
		}
	}

	/// links rechts 
	ziel[1] = f[1];

	// Turm geht nach rechts
	s = f[0];
	while (s < 'H')
	{
		s++; // '1' + 1 = '2'
		ziel[0] = s; // "A2"
		std::cout << ziel << " <-- Ziel zähler in Schleife \n";
		if (Spiel::spielStand[ziel].figur->figurTyp == " ") // figur auf feld leer?
		{
			eF.push_back(ziel);
		}
		else
		{
			if (Spiel::spielStand[ziel].figur->figurFarbe != figurFarbe)
			{
				eF.push_back(ziel);
				if (DEBUG) {
					std::cout << "\n" << f << " kann " << ziel << " schlagen\n";
				}
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "\nEigene Figur auf " << ziel << " kann nicht geschlagen werden\n";
				}
			}
			break;
		}
	}

	// Turm geht nach links
	s = f[0];
	while (s > 'A')
	{
		s--; // '1' + 1 = '2'
		ziel[0] = s; // "A2"
		std::cout << ziel << " <-- Ziel zähler in Schleife \n";
		if (Spiel::spielStand[ziel].figur->figurTyp == " ") // figur auf feld leer?
		{
			eF.push_back(ziel);
		}
		else
		{
			if (Spiel::spielStand[ziel].figur->figurFarbe != figurFarbe)
			{
				eF.push_back(ziel);
				if (DEBUG) {
					std::cout << "\n" << f << " kann " << ziel << " schlagen\n";
				}
			}
			else
			{
				if (DEBUG)
				{
					std::cout << "\nEigene Figur auf " << ziel << " kann nicht geschlagen werden\n";
				}
			}
			break;
		}
	}
	
	if (DEBUG)
	{
		std::cout << __func__ << " Turm auf " << f << "\n";
		for (auto ef : eF)
		{
			std::cout << ef;
		}
		std::cout << "\n";
	}

	return eF;
}
