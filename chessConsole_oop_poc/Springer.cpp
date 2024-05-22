#include "Springer.h"

Springer::Springer(std::string t, bool f)
{
    figurTyp = f ? "S" : "s";
    figurFarbe = f;
}

std::vector<std::string> Springer::erlaubteZieleberechnen(std::string)
{
    return std::vector<std::string>();
}
