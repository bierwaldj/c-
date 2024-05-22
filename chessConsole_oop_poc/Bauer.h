#pragma once
#include "Figur.h"
class Bauer :
    public Figur
{
public:
    Bauer(std::string, bool); 
    std::vector<std::string> erlaubteZieleberechnen(std::string f);
};

