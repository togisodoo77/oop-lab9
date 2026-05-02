#ifndef SPOUSE_H
#define SPOUSE_H

#include "Person.h"

// Гэр бүлийн хамтрагч - Person-аас удамшина
class Spouse : public Person {
private:
    string anniversaryDate; // Гэрлэсэн огноо
public:
    Spouse() : Person(), anniversaryDate("") {}
    Spouse(string n, string ss, int age, string date)
        : Person(n, ss, age), anniversaryDate(date) {}

    string getAnniversaryDate() const { return anniversaryDate; }
    void   setAnniversaryDate(string d) { anniversaryDate = d; }
};

#endif
