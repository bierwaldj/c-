#include "Laeufer.h"

Laeufer::Laeufer(std::string t, bool f)
{
    figurTyp = f ? "L" : "l";
    figurFarbe = f;
}

std::vector<std::string> Laeufer::erlaubteZieleberechnen(std::string)
{
    return std::vector<std::string>();
}
