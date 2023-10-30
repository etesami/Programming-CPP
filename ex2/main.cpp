#include <iostream>

// Function declarations (prototypes)
// Should be defined before the actual call to the functions
int add(int a, int b);
int subtract(int a, int b);

int main() {
    int result1 = add(5, 3);
    int result2 = subtract(5, 3);
    std::cout << "Addition: " << result1 << std::endl;
    std::cout << "Subtraction: " << result2 << std::endl;
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}