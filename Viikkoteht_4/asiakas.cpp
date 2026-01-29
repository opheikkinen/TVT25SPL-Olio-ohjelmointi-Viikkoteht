#include "asiakas.h"

using namespace std;

Asiakas::Asiakas(string n, double luottoraja)

    :nimi{n}
    ,kayttotili{n}
    ,luottotili{n,luottoraja}
{
    cout << "Asiakkuus luotu " << nimi << ":lle." << endl;
}

string Asiakas::getName()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << nimi << endl;
    kayttotili.getBalance();
    luottotili.getBalance();
}

bool Asiakas::talletus(double talletus)
{
    kayttotili.deposit(talletus);
}

bool Asiakas::nosto(double nosto)
{
    kayttotili.withdraw(nosto);
}

bool Asiakas::luotonMaksu(double maksu)
{
    luottotili.deposit(maksu);
}

bool Asiakas::luotonNosto(double nosto)
{
    luottotili.withdraw(nosto);
}

bool Asiakas::tiliSiirto(double siirto, Asiakas& kohde)
{

    cout << nimi << " siirtää " << siirto << " " << kohde.nimi << ":lle" << endl;

    if (!kayttotili.withdraw(siirto))
    {
        cout << "Tilisiirto epäonnistui." << endl;
        return false;
    }else
    {
        kohde.kayttotili.deposit(siirto);
        cout << "Tilisiirto tehty." << endl;
        return true;
    }
}
