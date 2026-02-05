#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori()
{
    seuraajat = nullptr;
    cout << "Luotiin Notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja * uusi)
{

    if (seuraajat == nullptr) { // eka lisäys
        seuraajat = uusi;
        cout << "Lisättiin seuraaja " << uusi->getNimi() << endl;
        return;
    }

    Seuraaja * t = seuraajat; // etsitään seuraava
    while (t->next != nullptr) {
        t = t->next;
    }
    t->next = uusi; // ja lisätään jonon loppuun

    cout << "Lisättiin seuraaja " << uusi->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja * poista)
{
    if (seuraajat == nullptr)
        return;

    if (poista == nullptr){
        return;
    }

    if (seuraajat == poista) { // jos kyseessä eka node
        seuraajat = seuraajat->next;
        poista->next = nullptr; // resetointi
        cout << "Poistetiin seuraaja " << poista->getNimi() << endl;
        return;
        }

    Seuraaja * t = seuraajat; // etsitään node
    while (t->next != nullptr && t->next != poista) {
        t = t->next;
        }

    if (t->next == poista){ // kun löyty unlinkataan se
        t->next = poista->next;
        poista->next = nullptr; // resetointi
        cout << "Poistetiin seuraaja " << poista->getNimi() << endl;
        }


}

void Notifikaattori::tulosta()
{
    cout << "Notifikaattorin seuraajat:" << endl;

    Seuraaja * t = seuraajat;
    while (t != nullptr){
        cout << t->getNimi() << endl;
        t = t->next;
        }

}

void Notifikaattori::postita(string viesti)
{
    cout << "Notifikaattorin viesti: " << viesti << endl;

    Seuraaja * t = seuraajat;
    while (t != nullptr){
        t->paivitys(viesti);
        t = t->next;
        }
}
