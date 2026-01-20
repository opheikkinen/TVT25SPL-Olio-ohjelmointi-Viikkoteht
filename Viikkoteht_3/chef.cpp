#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(string n)
{
    chefName = n;
    cout << "Chef " << chefName << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int salad) // yhteen annokseen 5
{
    int annos = salad / 5;
    cout << "Chef " << chefName << " with " << salad
         << " ingredients can make " << annos << " salad portions" << endl;
    return 0;
}

int Chef::makeSoup(int soup) // yhteen annokseen 3
{
    int annos = soup / 3;
    cout << "Chef " << chefName << " with " << soup
         << " ingreddients can make " << annos << " soup portions" << endl;
    return 0;
}
