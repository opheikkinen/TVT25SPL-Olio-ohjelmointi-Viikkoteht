#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori notif;
    Seuraaja a("Kalle");
    Seuraaja b("Jussi");
    Seuraaja c("Pelle");
    Seuraaja d("Ulf");

    notif.lisaa(&a);
    notif.lisaa(&b);
    notif.lisaa(&c);

    notif.tulosta();

    notif.postita("Kukkuluuruu kullanmurut!");

    notif.poista(&a);
    notif.lisaa(&d);

    notif.tulosta();

    notif.postita("Miten menee?");


    return 0;
}
