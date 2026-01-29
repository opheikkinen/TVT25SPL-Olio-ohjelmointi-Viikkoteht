#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

using namespace std;

class Luottotili : public Pankkitili
{
public:
    Luottotili(string, double);
    double getBalance() override;
    bool deposit(double) override;
    bool withdraw(double) override;
protected:
    double luottoraja = 0;
};

#endif // LUOTTOTILI_H
