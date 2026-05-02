#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

// Хүн - үндсэн эх класс
class Person {
private:
    string name;
    string ssNum;
    int    age;
public:
    Person() : name(""), ssNum(""), age(0) {}
    Person(string n, string ss, int a) : name(n), ssNum(ss), age(a) {}

    string getName()  const { return name; }
    string getSSNum() const { return ssNum; }
    int    getAge()   const { return age; }

    void setName(string n)  { name  = n; }
    void setSSNum(string s) { ssNum = s; }
    void setAge(int a)      { age   = a; }
};

#endif
