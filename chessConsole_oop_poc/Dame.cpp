#include "Dame.h"

Dame::Dame(std::string typ, bool f)
{
    figurTyp = f ? "D" : "d";
    figurFarbe = f;

}

std::vector<std::string> Dame::erlaubteZieleberechnen(std::string f)
{
    return std::vector<std::string>();
}
