#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Employee : public Person {
private:
    string CompanyID;   
    string Title;       
    string StartDate; 

    Spouse* spouse;
    vector<Child> children;
    Division* division;
    vector<JobDescription*> jobDescriptions;

public:
    Employee(string name, string ssNum, int age,
         string companyID, string title, string startDate,
         Division* div, JobDescription* jd)
    : Person(name, ssNum, age),
      CompanyID(companyID),
      Title(title),
      StartDate(startDate),
      spouse(nullptr),
      division(nullptr)
{
    if (div == nullptr) throw invalid_argument("Employee zaaval Division-toi baih ystoi.");
    if (jd == nullptr) throw invalid_argument("Employee dor hayj neg JobDescription-toi baih ystoi.");

    division = div;
    jobDescriptions.push_back(jd);
}

    string getCompanyID() const { return CompanyID; }
    string getTitle() const { return Title; }
    string getStartDate() const { return StartDate; }

    void setCompanyID(string id) { CompanyID = id; }
    void setTitle(string title) { Title = title; }
    void setStartDate(string date) { StartDate = date; }

    void setSpouse(Spouse* s) { spouse = s; }
    Spouse* getSpouse() const { return spouse; }

    void addChild(Child c) { children.push_back(c); }
    vector<Child>& getChildren() { return children; }

    void setDivision(Division* d) {
        if (d == nullptr) throw invalid_argument("Division null baij bolohgui.");
        division = d;
    }
    Division* getDivision() const { return division; }

    void addJobDescription(JobDescription* jd) {
         if (jd == nullptr) throw invalid_argument("JobDescription null baij bolohgui.");
        jobDescriptions.push_back(jd);
    }
    vector<JobDescription*>& getJobDescriptions() { return jobDescriptions; }

    
    void print() const override {
        cout << "==============================" << endl;
        cout << "[Employee]";
        Person::print();
        cout << endl;
        cout << "  CompanyID  : " << CompanyID << endl;
        cout << "  Title      : " << Title << endl;
        cout << "  Start Date : " << StartDate << endl;

        // Хэлтэс (1 - заавал байна)
        cout << "  Division     : "; division->print();

        // Ажлын байр (1..n - дор хаяж нэг байна)
        cout << "  Job Description (" << jobDescriptions.size() << "):" << endl;
        for (int i = 0; i < jobDescriptions.size(); i++) {
            jobDescriptions[i]->print();
        }
        // Эхнэр/Нөхөр (0..1 - байхгүй байж болно)
        cout << "  Spouse     : ";
        if (spouse != nullptr) spouse->print();
        else cout << "None" << endl;

        // Хүүхдүүд (0..n - байхгүй байж болно)
        cout << "  Children (" << children.size() << "):" << endl;
        if (children.empty()) cout << "None" << endl;
        else {
            for (int i = 0; i < children.size(); i++) {
                children[i].print();
            }
        }
        cout << "==============================" << endl;
    }

    ~Employee() {}
};

#endif