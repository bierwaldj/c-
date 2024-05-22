#pragma once
#include "Figur.h"
class Koenig :
    public Figur
{
public:
    Koenig (std::string, bool);
    std::vector<std::string> erlaubteZieleberechnen(std::string);
};

