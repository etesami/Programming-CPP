// main.cpp
#include <iostream>
#include "person.h"

int main() {
    Person person1("Alice", 25);
    Person* person2 = new Person("Bob", 30);;


    // methods are accessed through '.' operator or '->' operator
    // depending on how the object is declared
    std::cout << "Person 1: " << person1.getName() << ", Age: " << person1.getAge() << std::endl;
    std::cout << "Person 2: " << person2->getName() << ", Age: " << person2->getAge() << std::endl;

    person1.setName("Eve");
    person1.setAge(21);

    std::cout << "Updated Person 1: " << person1.getName() << ", Age: " << person1.getAge() << std::endl;

    return 0;
}
