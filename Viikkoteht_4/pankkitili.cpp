#include "pankkitili.h"

using namespace std;

Pankkitili::Pankkitili(string nimi)
{
    omistaja = nimi;
    cout << "Pankkitili luotu " << omistaja << ":lle." << endl;
}

double Pankkitili::getBalance()
{
    cout << "Käyttötilin saldo: " << saldo << endl;
    return saldo;
}

bool Pankkitili::deposit(double talletus)
{
    if (talletus>0)
        {
        saldo = saldo + talletus;
        cout << omistaja << " Pankkitili: talletus " << talletus << " tehty." << endl;
        return true;
    }else
        {
        return false;
    }
}

bool Pankkitili::withdraw(double nosto)
{
    if (nosto>0 && (saldo-nosto)>0)
    {
        saldo = saldo - nosto;
        cout << omistaja << " Pankkitili: nosto " << nosto << " tehty." << endl;
        return true;
    }else
        {
        cout << "Yritit nostaa " << omistaja << " Pankkitilillä "<< nosto << endl;
        cout << "Tililtä on mahdollista nostaa enintään " << saldo << endl;
        return false;
    }
}
