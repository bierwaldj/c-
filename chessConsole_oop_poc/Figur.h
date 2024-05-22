#pragma once
#include <string>
#include <vector>
class Figur
{
protected:
	
public:
	Figur();
	Figur(std:: string key, bool f);
	std::string figurTyp;
	bool figurFarbe;

	// ! polymorphe Funktion, in den spezialisierten Figurentypen
	virtual std::vector<std::string> erlaubteZieleberechnen(std::string);

	std::string get_figurTyp()   { return figurTyp; }
	bool get_figurFarbe() { return figurFarbe; }
	void set_figurTyp(std::string t);
	void set_figurFarbe(bool f);

	bool aufDemSpielfeld(std::string);
	bool eigeneFigur(std::string, std::string);
	bool nichtLeer(std::string);
	bool istLeer(std::string f) { return !nichtLeer(f); }
	bool schlagbarerGegner(std::string f, std::string nZ) 
	      { return !eigeneFigur(f, nZ) && aufDemSpielfeld(nZ); }
};

