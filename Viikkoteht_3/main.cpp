#include <iostream>
#include "chef.h"
#include "italianChef.h"


using namespace std;

int main()
{
    Chef kokki1("Kolmonen");

    kokki1.makeSalad(11);
    kokki1.makeSoup(14);

    ItalianChef kokki2("Luigi");

    kokki2.makeSalad(9);
    kokki2.askSecret("pizza",12,12);

    return 0;
}
