#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
public:
    Student(string,int);
    string getName();
    int getAge();
    void setName(string);
    void setAge(int);
    void printStudentInfo();
private:
    string Name;
    int Age;
};

#endif // STUDENT_H
