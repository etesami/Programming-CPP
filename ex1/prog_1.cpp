#include "myheader.h"
#include <iostream>

// using namespace std;

int main() {
    int result = add(2, 3);
    std::cout << "Result: " << result << std::endl;

    int result_another = anotherFunction(2, 5);
    std::cout << "Result (Another): " << result_another << std::endl;
    return 0;
}

int add(int a, int b) {
    return a + b;
}