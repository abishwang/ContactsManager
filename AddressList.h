#pragma once
#include "Person.h"

constexpr int MAXSIZE{1000};
class Person;
class AddressList {
private:
    Person* addresses[MAXSIZE]{};
    int length{}; // current length

public:
    ~AddressList();
    friend void selectFunc(AddressList& list, int select); // switch to other methods

    bool isEmpty();
    bool isFull();
    int isExist(string name);

    void showMenu();
    void add(string in_name, int in_gender, int in_age, string in_phone, string in_addr);
    void findPerson(string name);
    void rm(string name);
    void edit(string name);

    void show_top(); // show the top contact info
    void show_all();
};