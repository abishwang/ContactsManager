#include "AddressList.h"
#include <iostream>

using namespace std;

void selectFunc(AddressList& list, int select) {
    string name;
    int gender;
    int age;
    string phone;
    string addr;
    switch (select)
    {
    case 1: // add one
        cout << "please enter: name, gender, age, telephone, address" << endl;
        cin >> name >> gender >> age >> phone >> addr;
        list.add(name, gender, age, phone, addr);
        break;
    case 2: // show all
        list.show_all();
        break;
    case 3: // delete one by name
        cout << "delete name : ";
        cin >> name;
        list.rm(name);
        break;
    case 4: // find one by name
        cout << "find name: ";
        cin >> name;
        list.findPerson(name);
        break;
    case 5: // edit one
        cout << "edit name:";
        cin >> name;
        list.edit(name);
        break;
    default:
        break;
    }
}

void AddressList::showMenu() {
    cout << "***************************" << endl;
    cout << "1. add one " << endl;
    cout << "2. show all" << endl;
    cout << "3. delete one by name" << endl;
    cout << "4. find one by name" << endl;
    cout << "5. edit one " << endl;
    cout << "0. exit" << endl;
    cout << "***************************" << endl;
}
AddressList::~AddressList() {
    for (int i = 0; i <= length-1; ++i) {
        delete addresses[i];
    }
}

bool AddressList::isEmpty() {
    return length == 0;
}

bool AddressList::isFull() {
    return length+1 == MAXSIZE;
}
void AddressList::add(string in_name, int in_gender, int in_age, string in_phone, string in_addr) {
    if (isFull()) return;
    Person* p = new Person(in_name, in_gender, in_age, in_phone, in_addr);
    addresses[length] = p;
    ++length;
}

void AddressList::show_top() {
    Person* p_cur = addresses[length-1];
    p_cur->show();
    cout << "current lenth: " << length << endl;
}

void AddressList::show_all() {
    cout << "length: " << length << endl;
    for(int i = 0; i <= length-1; ++i) { // todo: if for-base, sth wrong will happend
        auto p = addresses[i];
        p->show();
    }
}

int AddressList::isExist(string name) {
    for(int i = 0; i <= length-1; ++i) {
        if (name == addresses[i]->name) {
            return i;
        }
    }
    return -1;
}

void AddressList::findPerson(string name) {
    auto pos = isExist(name);
    if (pos != -1) {
        cout << "located at postion: " << pos+1 << "th" << endl;
        addresses[pos]->show(); 
    }
    else {
        cout << "no this person here" << endl;
    }
}

void AddressList::rm(string name) {
    auto ret = isExist(name);
    if (ret != -1) {
        // people behind the "name" in the array moves forward
        for(int i = ret+1; i <= length-1; ++i) {
            addresses[i-1] = addresses[i];
        }
        --length;
        cout << "remove " << name << " done" << endl;
    }
    else {
        cout << "failed removal" << endl;
        return;
    }
}

void AddressList::edit(string name) {
    auto pos = isExist(name);
    if (pos != -1) {
        auto p = addresses[pos];
        int age;
        string phone;
        string addr;
        cout << "please enter:age, telephone, address" << endl;
        cin >> age >> phone >> addr;
        p->age = age;
        p->telephone = phone;
        p->address = addr;
        return;
    }
    cout << "no this person here" << endl;
}