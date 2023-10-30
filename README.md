# Programming_CPP

- [Programming\_CPP](#programming_cpp)
  - [Simple CPP File](#simple-cpp-file)
  - [Multiple Functions](#multiple-functions)
  - [Multiple CPP Files and Header Files](#multiple-cpp-files-and-header-files)
  - [Multiple file with Makefile](#multiple-file-with-makefile)
  - [Object Oriented Programming](#object-oriented-programming)
  - [Pointers](#pointers)
  - [Linked List with Strcut](#linked-list-with-strcut)
  - [File Stream](#file-stream)
  - [StringStreams (sstream)](#stringstreams-sstream)
  - [Operators](#operators)
    - [Overloading Binary Operators](#overloading-binary-operators)
    - [Overloading Unary Operators](#overloading-unary-operators)
    - [Overloading Comparison Operators](#overloading-comparison-operators)


## Simple CPP File

A basic hello world. Take a look at the [ex0](./ex0/) folder:
```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, world!";
    return 0;
}
```

```bash
g++ -std=c++11 -g -Wall hello.cpp -o hello
# -g: Generate debug symbol information
# -Wall: All warnings
```


## Multiple Functions
```cpp
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
```

## Multiple CPP Files and Header Files

Take a look at files in [ex1](./ex1) folder.

```cpp
// myheader.h
#ifndef MYHEADER_H
#define MYHEADER_H

int add(int a, int b);
int anotherFunction(int a, int b);

#endif // MYHEADER_H
```

Assume we have `prog_1.cpp` and `prog_2.cpp` with same content as:
```cpp
#include "myheader.h"
#include <iostream>

int main() {
    int result = add(4, 5);
    std::cout << "Result: " << result << std::endl;

    int result_another = anotherFunction(2, 5);
    std::cout << "Result (Another): " << result_another << std::endl;
    return 0;
}

// Function definition comes after the main function
int add(int a, int b) {
    return a + b;
}
```

To compile:
```bash
# Compile separately:
# 1. Compile into object files (*.o) using the C++ compiler
g++ -c prog_1.cpp -o prog_1.o
g++ -c prog_2.cpp -o prog_2.o

# 2. The object files and any necessary libraries are linked together into an executable.
g++ prog_1.o prog_2.o -o myprogram
```

## Multiple file with Makefile

Consider example in [ex3](./ex3/) folder. Then:
```Makefile
CC = g++
CFLAGS = -g -Wall
TARGET = myprogram

# This detects all .cpp files in the current directory
SRCS = $(wildcard *.cpp) 
# SRCS = main.cpp other.cpp

OBJS = $(SRCS:.cpp=.o)

# default target
all: $(TARGET)

# depends on the object files ($(OBJS)) and links them to create the executable.
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# A pattern rule that compiles .cpp files to .o files.
# Any target file ending with .o can be built from a source file ending with .cpp. 
# The % symbol is a wildcard that matches any characters
# $<: This is an automatic variable that represents the first prerequisite of the rule
# $@: The $@ automatic variable represents the target file name.
%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)

```

## Object Oriented Programming
Take a look at [ex4](./ex4/) folder.


## Pointers

```cpp
int* intPtr; // Pointer to an integer
int someVariable = 42;
intPtr = &someVariable; // Point to the address of someVariable
std::cout << *intPtr; // Access the value at the address pointed to

int** doublePtr; // Pointer to a pointer to an integer
int someValue = 42;
int* intPtr = &someValue; // intPtr: A pointer
doublePtr = &intPtr; // Point to the address of a pointer (intPtr)
std::cout << **doublePtr; // Access the value at the address pointed to by doublePtr

const int* constPtr; // Pointer to a constant integer
int x = 42;
constPtr = &x; // Can read, but not modify the value pointed to

int y = 10;
int* const constIntPtr = &y; // A constant pointer to an integer
*constIntPtr = 20; // You can modify the value at the address, but you can't change constIntPtr to point to a different address.


void sayHello() {
    std::cout << "Hello, World!" << std::endl;
}
void (*functionPtr)() = sayHello; // Pointer to a function
functionPtr(); // Call the function indirectly through the pointer


int arr[] = {1, 2, 3, 4, 5};
int* arrPtr = arr; // Pointer to an array
for (int i = 0; i < 5; i++) {
    std::cout << *(arrPtr + i) << " "; // Access elements using pointer arithmetic
}

```

## Linked List with Strcut
```cpp
#include <iostream>

// Define a struct for a singly linked list node
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize data and set next to nullptr
    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    // Create nodes for the linked list
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Link the nodes to form the linked list
    head->next = second;
    second->next = third;

    // Traverse and print the linked list
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    // Clean up memory (deallocate nodes)
    delete head;
    delete second;
    delete third;

    return 0;
}

```

## File Stream
Take a look at [ex5](./ex5/) directory.
```cpp
#include <iostream>
#include <fstream>

int main() {
    // Writing to a file
    std::ofstream outFile("sample.txt"); // Create a file named "sample.txt" for writing

    if (outFile.is_open()) {
        outFile << "Hello, world!" << std::endl;
        outFile << "This is a sample file." << std::endl;
        outFile.close();
        std::cout << "Data written to the file." << std::endl;
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }

    // Reading from a file
    std::ifstream inFile("sample.txt"); // Open the file for reading

    if (inFile.is_open()) {
        std::string line;
        std::cout << "Contents of the file:" << std::endl;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Failed to open the file for reading." << std::endl;
    }

    return 0;
}

```

## StringStreams (sstream)
```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Convert an integer to a string
    int num = 42;
    std::stringstream intToStringStream;
    intToStringStream << num; // Insert the integer into the stringstream
    std::string numAsString = intToStringStream.str(); // Get the string representation
    intToStringStream.str(""); // Clear the stringstream
    intToStringStream.clear(); // Clear any error flags

    // Convert a string to an integer
    std::string str = "12345";
    std::stringstream stringToIntStream(str);
    int stringAsInt;
    stringToIntStream >> stringAsInt; // Extract the integer from the stringstream

    std::cout << "Original integer: " << num << std::endl;
    std::cout << "Integer as a string: " << numAsString << std::endl;
    std::cout << "String as an integer: " << stringAsInt << std::endl;

    return 0;
}

```

## Operators
Take a look at the [ex6](./ex6) folder.

### Overloading Binary Operators
```cpp
class Complex {
public:
    double real;
    double imag;

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

### Overloading Unary Operators
```cpp
class Integer {
public:
    int value;

    Integer(int v) : value(v) {}

    Integer& operator++() {
        // Prefix increment (++x)
        value++;
        return *this;
    }

    Integer operator++(int) {
        // Postfix increment (x++)
        Integer copy = *this;
        value++;
        return copy;
    }
};

```

### Overloading Comparison Operators
```cpp
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int den) : numerator(num), denominator(den) {}

    bool operator==(const Fraction& other) {
        return (numerator * other.denominator == other.numerator * denominator);
    }
};

```