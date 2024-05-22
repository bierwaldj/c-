#pragma once
#include <string>
#include "Figur.h"
class Leer : public Figur
{
public:
	Leer(std::string, bool);
	virtual	std::vector<std::string> erlaubteFelderErrechnen(std::string);
};

