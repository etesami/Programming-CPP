// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a);
    std::string getName();
    int getAge();
    void setName(std::string n);
    void setAge(int a);
};

#endif // PERSON_H
