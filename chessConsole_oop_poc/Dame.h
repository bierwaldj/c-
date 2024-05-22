#pragma once
#include "Figur.h"
class Dame :
    public Figur
{
public:
    Dame(std::string, bool);
    std::vector<std::string> erlaubteZieleberechnen(std::string);
};

