#include "seuraaja.h"
#include <iostream>

using namespace std;


Seuraaja::Seuraaja(string olioNimi)
{
    nimi = olioNimi;
    cout << "Luotiin seuraaja " << nimi << endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string saatuViesti)
{
    cout << nimi << " sai viestin: " << saatuViesti << endl;
}
