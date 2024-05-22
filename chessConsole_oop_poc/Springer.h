#pragma once
#include "Figur.h"
class Springer :
    public Figur
{
public:
    Springer (std::string, bool);
    std::vector<std::string> erlaubteZieleberechnen(std::string);
};

