#include "italianchef.h"
#include "chef.h"
#include <iostream>
#include <string>

using namespace std;

ItalianChef::ItalianChef(string n) : Chef(n)
{
    chefName = n;
    password = "pizza";
    cout << "Italian chef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "Italian chef " << chefName << " destruktori" << endl;
}

bool ItalianChef::askSecret(string salasana, int jauho, int vesi)
{
    if (salasana.compare(password) == 0)
    {
        cout << "Password OK!" <<endl;
        makepizza(jauho, vesi);
     }

    if (salasana.compare(password) != 0)
    {
        cout << "Wrong password" <<endl;
    }
    return 0;
}

int ItalianChef::makepizza(int jauho, int vesi) // tarvii 5 jauhoja ja 5 vettä
{
    int j_maara = jauho / 5 ;
    int v_maara = vesi / 5 ;
    int pizza = min(j_maara, v_maara);


    cout << "Italian Chef " << chefName << " with " << jauho << " flour and "
         << vesi << " water can make " << pizza << " pizzas" << endl;

    return 0;
}

