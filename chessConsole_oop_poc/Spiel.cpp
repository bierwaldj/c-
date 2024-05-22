#include "Spiel.h"
#include "consolenfarbe.h"
#include <iostream>
#include <algorithm>

#define DEBUG 1

Spiel::Spiel()
{
	if (DEBUG || ALLDEBUG)
	{
		std::cout << __func__ << "()\t" << __LINE__ << " in " << __FILE__ << "\n";
		std::cout << "Start to build spielstand\n";
	}
	// Grundstellung mit 64 Felder in der map<string,Feld> von A1 bis H8
	for (char spalte = 'A'; spalte <= 'H'; spalte++)
	{
		for (char zeile = '1'; zeile <= '8'; zeile++)
		{
			std::string key{ spalte,zeile }; 
			Spiel::spielStand[key] = Feld(spalte,zeile);
		}
	}

}

void Spiel::ausgeben()
{
	unsigned int startzeile{ 5 };
	unsigned int startspalte{ 5 };
	farbe::concol feldhell = farbe::concol::white;
	farbe::concol felddunkel = farbe::concol::grey;
	farbe::concol umrandung = farbe::concol::green;
	setCursorPosition(startspalte, startzeile);
	farbe::concolinit();
	std::cout << " ABCDEFGH\n";
	setCursorPosition(startspalte, ++startzeile);
	for (char z = '8'; z >= '1'; z--)
	{
		farbe::setcolor(umrandung, farbe::concol::black);
		std::cout << z;
		for (char s = 'A'; s <= 'H'; s++)
		{
			
			std::string feld{ s,z };
			if ((z + s) % 2)
			{
				if (spielStand[feld].hell)
				{
					farbe::setcolor(farbe::concol::black, felddunkel);
				}
				else
				{
					farbe::setcolor(farbe::concol::red, felddunkel);
				}
			}
			else
			{
				if (spielStand[feld].hell)
				{
					farbe::setcolor(farbe::concol::black, feldhell);
				}
				else
				{
					farbe::setcolor(farbe::concol::red, feldhell);
				}

			}
			std::cout << spielStand[feld].figur->get_figurTyp();
		}
		farbe::setcolor(umrandung, farbe::concol::black);
		std::cout << z;
		setCursorPosition(startspalte, ++startzeile);
		farbe::setcolor(farbe::concol::black, farbe::concol::black);
	}
	farbe::setcolor(umrandung, farbe::concol::black);
	// setCursorPosition(startspalte, ++startzeile);
	std::cout << " ABCDEFGH\n";
	farbe::setcolor(farbe::concol::red, farbe::concol::black);		

}

void Spiel::bewegen(std::string vonNach) //A7A6
{
	if (DEBUG)
	{
		std::cout << __func__ << "()\t" << __LINE__ << " in " << __FILE__ << "\n";
		std::cout << "von " << vonNach.substr(0, 2) << 
			        " nach " << vonNach.substr(2, 2) << "\n";
	}
	std::string von = vonNach.substr(0, 2);
	std::string nach =vonNach.substr(2, 2);

	spielStand[nach].figur = spielStand[von].figur;
	spielStand[von].figur = new Figur(vonNach," ");
	// Ende der Bewegung
	// neue Listen von erlaubten Feldern erzeugen

	// über alle Felder, wo Figuren sind
	// foreach durch spielstand -> Felder, sind besetzt wenn figurTyp nicht leer
	for (auto& feld : Spiel::spielStand)
		// Figurentyp ermitteln
	{
	feld.second.erlaubteZiele = feld.second.figur->erlaubteZieleberechnen(feld.first);
		/*if (DEBUG)
		{

		}*/
	  }

	

}

void Spiel::bewegen()
{
	std::string von, nach, vonNach;
	// user zu einer Eingabe auffordern
	std::cout << "Bitte ein Feld bestimmen : ";
	std::cin >> von;
	if (Spiel::spielStand[von].erlaubteZiele.size() == 0)
	{
		std::cout << von << " kann nicht bewegt werden \n";
	}
	else
	{ // es gibt erlaubte Ziele
		std::cout << "wohin soll gezogen werden : ";
		std::cin >> nach;
		// ist nach in der Liste
		std::vector<std::string> eZ = Spiel::spielStand[von].erlaubteZiele;
		if (std::find(eZ.begin(), eZ.end(), nach) != eZ.end())
		{
			std::cout << "Zug ist erlaubt -> \n";
			vonNach += von;
			vonNach += nach;
			bewegen(vonNach);  // delegation an bewegen(string)

		}
		// sonst
		else
		{
			std::cout << von << " Zug nicht erlaubt \n";
		}


	}





}
