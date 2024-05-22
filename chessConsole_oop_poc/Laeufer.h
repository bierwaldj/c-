#pragma once
#include "Figur.h"
class Laeufer :
    public Figur
{
public:
    Laeufer(std::string, bool);
    std::vector<std::string> erlaubteZieleberechnen(std::string);
};

