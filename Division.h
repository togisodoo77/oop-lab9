#ifndef DIVISION_H
#define DIVISION_H

#include <iostream>
#include <string>
using namespace std;

class Division {
private:
    string DivisionName;

public:
    Division() {DivisionName = "";}
    Division(string divisionName) {DivisionName = divisionName;}

    string getDivisionName() const {return DivisionName;}
    void setDivisionName(string divisionName) {DivisionName = divisionName;}

    void print() const {
        cout << DivisionName << endl;
    }

    ~Division() {}
};

#endif