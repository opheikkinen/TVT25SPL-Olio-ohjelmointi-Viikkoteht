#include "luottotili.h"

using namespace std;

Luottotili::Luottotili(string nimi, double luotto) : Pankkitili(nimi)
{
    luottoraja = -luotto;
    cout << "Luottotili luotu " << omistaja << ":lle. Luottoraja: " << luotto << endl;
}

double Luottotili::getBalance()
{
    cout << "Luottotilin saldo: " << -luottoraja << endl;
    return luottoraja;
}

bool Luottotili::deposit(double velkamaksu)
{
    if (luottoraja - velkamaksu <= 0)
    {
        luottoraja = luottoraja - velkamaksu;
        cout << omistaja << " Luottotili: takaisin maksu " << velkamaksu << " tehty."
        << " ,luottoa löytyy: " << -luottoraja << endl;
        return true;
    }else
    {
        cout << omistaja << " Luottotilin saldo täynnä" << endl;
        cout << "Yritit maksaa takaisin " << velkamaksu << " ja tilillä on velkaa vain " << -(luottoraja+velkamaksu) << endl;
        return false;
    }
}

bool Luottotili::withdraw(double velkanosto)
{
    if (luottoraja + velkanosto <= 0)
    {
        luottoraja = luottoraja + velkanosto;
        cout << omistaja << " Luottotililtä nosto " << velkanosto
        << " ,luottoa jäljellä: " << -luottoraja << endl;
        return true;
    }else
    {
        cout << omistaja << "Luottotilillä ei katetta" << endl;
        cout << "Yritit nostaa " << velkanosto << " ja tililtä on nostettavissa vain " << -luottoraja << endl;
        return false;
    }
}
