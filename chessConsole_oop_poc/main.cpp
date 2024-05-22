

#include <iostream>
#include <map>
#include <locale>    // für deutsche Umlaute
#include "Spiel.h"

#define cls system("CLS")

std::map<std::string, Feld> Spiel::spielStand;

int main()
{
    setlocale(LC_ALL, "de_DE"); // deutscher Zeichensatz

    Spiel s;            // füllt mir den spielStand mit der Grundaufstellung
    Spiel::spielStand;  // Klassenvariable static in Spiel
    s.ausgeben();
    // system("Pause");
    while (true)
    {
        // eingabe
        cls;

        s.ausgeben();
        s.bewegen();  // und eF neu berechnen
        s.ausgeben();
        system("Pause");

    }
}

