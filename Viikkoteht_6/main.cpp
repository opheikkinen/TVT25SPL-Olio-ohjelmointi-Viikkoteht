#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;


int main ()
{
    int selection =0;
    string mainName;
    int mainAge;

    vector<Student>studentList;
    studentList.reserve(10);
    vector<Student> :: iterator it;

    do{
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            cout << "Student name ?" << endl;
            cin >> mainName;
            cout << "Student age ?" << endl;
            cin >> mainAge;
            studentList.emplace_back(mainName,mainAge);
            break;

        case 1:
            for(auto & tiedot : studentList)
                {
                    tiedot.printStudentInfo();
                }
            break;

        case 2:
            sort(studentList.begin(), studentList.end(),[](Student & a, Student & b)
                {
                     return a.getName() < b.getName();
                });

            for(auto & tiedot : studentList)
                {
                    tiedot.printStudentInfo();
                }
            break;

        case 3:
            sort(studentList.begin(), studentList.end(),[](Student & a, Student & b)
                {
                     return a.getAge() > b.getAge();
                });

            for(auto & tiedot : studentList)
                {
                    tiedot.printStudentInfo();
                }
            break;

        case 4:
            cout << "Student to be found name ?" << endl;
            cin >> mainName;

            it = find_if(studentList.begin(), studentList.end(),[mainName](Student & a)
                {
                    return a.getName() == mainName;
                });

            if(it != studentList.end()){
                cout << "Student found:" << endl;
                it->printStudentInfo();
            } else {
                cout << "Student not found." << endl;
            }

            break;

        default:
             cout<< "Wrong selection, stopping..."<<endl;
              break;
        }

    }while(selection < 5);

return 0;
}
