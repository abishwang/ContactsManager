#include <string>
using namespace std;

class Person {
public:
    string name{"wang ao"};
    int gender{1};
    int age{20};
    string telephone{"xxx-xxxx-xxxx"};
    string address{"department 2 in songjiang"};

public:
    Person() {};
    Person(string in_name, int in_gender, int in_age, string in_phone, string in_addr) 
        : name(in_name), gender(in_gender), age(in_age), telephone(in_phone), address(in_addr) {}

    void show();
};