#include <iostream>
#include "student.h"



Student::Student(string o_nimi, int o_age)
{
    Name = o_nimi;
    Age = o_age;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::setName(string s_nimi)
{
    s_nimi = Name;
}

void Student::setAge(int s_age)
{
    s_age = Age;
}

void Student::printStudentInfo()
{
    cout << "Student " << Name << " Age " << Age << endl;
}
