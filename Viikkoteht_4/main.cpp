#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"


using namespace std;

int main()
{
    Asiakas testiAsiakas1("Liisa", 1000);
    testiAsiakas1.showSaldo();
    cout << endl;
    testiAsiakas1.talletus(200);
    testiAsiakas1.luotonNosto(150);
    testiAsiakas1.showSaldo();
    cout << endl;

    Asiakas testiAsiakas2("Pekka", 1000);
    testiAsiakas2.showSaldo();
    cout << endl;

    testiAsiakas1.tiliSiirto(150, testiAsiakas2);
    cout << endl;

    testiAsiakas2.showSaldo();
    cout << endl;
    testiAsiakas1.showSaldo();

    return 0;
}
