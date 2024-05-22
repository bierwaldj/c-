#pragma once
#include "Figur.h"
class Turm :
    public Figur
{
public:
    Turm (std::string, bool);
    std::vector<std::string> erlaubteZieleberechnen(std::string);
};

