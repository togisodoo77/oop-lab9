#include <iostream>
#include <vector>
#include "Employee.h"
using namespace std;

int main() {
    try {
        Division divIT("Information Technology Division");
        Division divHR("Human Resource Division");
        Division divFin("Finance Division");

        JobDescription jdTeacher("Teacher / Associate Professor");
        JobDescription jdMentor("Mentor");
        JobDescription jdCEO("Chief Executive Officer");
        JobDescription jdHR("HR Manager");
        JobDescription jdAnalyst("Financial Analyst");

        Employee bat("Bold", "NN001", 35,"EMP-001", "Senior Engineer", "2020-03-01", &divIT, &jdTeacher);
        bat.addJobDescription(&jdMentor);

        Spouse s1("Nomin", "NN002", 32, "2018-06-15");
        bat.setSpouse(&s1);

        Child c1("Temuulen", "NN010", 5, "Lego");
        Child c2("Erdene", "NN011", 3, "Toy Car");
        bat.addChild(c1);
        bat.addChild(c2);

        Employee oyun("Oyun", "NN003", 28, "EMP-002", "HR Director", "2021-07-10", &divHR, &jdHR);

        Child c3("Anu", "NN012", 2, "Doll");
        oyun.addChild(c3);

        Employee gan("Ganbayar", "NN004", 45, "EMP-003", "Director", "2015-01-01", &divFin, &jdCEO);
        gan.addJobDescription(&jdAnalyst);

        Spouse s2("Sarnai", "NN005", 42, "2005-09-20");
        gan.setSpouse(&s2);

        vector<Employee*> employees;
        employees.push_back(&bat);
        employees.push_back(&oyun);
        employees.push_back(&gan);

        for (int i = 0; i < employees.size(); i++) {
            employees[i]->print();
        }

        cout << "\nTotal number of employees: " << employees.size() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}