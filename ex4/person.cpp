// Person.cpp
#include "person.h"

// Constructor
// : name(n), age(a) {} is called an initializer list
// It is used to initialize the member variables of the class
// with the value of n and a that are passed to the constructor
Person::Person(std::string n, int a) : name(n), age(a) {}

std::string Person::getName() {
    return name;
}

int Person::getAge() {
    return age;
}

void Person::setName(std::string n) {
    name = n;
}

void Person::setAge(int a) {
    age = a;
}
