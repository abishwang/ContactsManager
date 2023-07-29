#include <iostream>
#include <string>
#include "AddressList.h"

using namespace std;

int main() {
    int select = 1; // select different functionalities
    AddressList contacts{}; // prepare address list
    contacts.showMenu();
    while (select) {
        cout << "choice:"; 
        cin >> select;
        cout << "---------------------------------------------" << endl;
        selectFunc(contacts,select);
        cout << "---------------------------------------------" << endl;
        cout << endl;
    }
}
