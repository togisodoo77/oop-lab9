#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include <iostream>
#include <string>
using namespace std;

class JobDescription {
private:
    string Description;

public:
    JobDescription() {Description = "";}
    JobDescription(string description) {Description = description;}

    string getDescription() const {return Description;}
    void setDescription(string description) {Description = description;}

    void print() const {
        cout << Description << endl;
    }

    ~JobDescription() {}
};

#endif