#include "Person.h"
#include <iostream>

void Person::show() {
    cout << "name: " << name << " gender: " << gender;
    cout << " age: " << age << " phone: " << telephone;
    cout << " address: " << address << endl;
}