#ifndef CHILD_H
#define CHILD_H

#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

class Child : public Person {
private:
    string FavoriteToy;   

public:
    Child() : Person(), FavoriteToy("") {}

    Child(string name, string ssNum, int age, string favoriteToy)
        : Person(name, ssNum, age),
          FavoriteToy(favoriteToy)
    {
    }

    string getFavoriteToy() const { return FavoriteToy; }

    void setFavoriteToy(string favoriteToy) { FavoriteToy = favoriteToy; }

    void print() const override {
        cout << "    [Child]" << endl;
        Person::print();
        cout << "    Favorite Toy : " << FavoriteToy << endl;
    }

    ~Child() {}
};

#endif