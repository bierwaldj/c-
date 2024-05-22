#include "Koenig.h"

Koenig::Koenig(std::string t, bool f)
{
	figurTyp = f ? "K" : "k";
	figurFarbe = f;
}

std::vector<std::string> Koenig::erlaubteZieleberechnen(std::string f)
{
	return std::vector<std::string>();
}
