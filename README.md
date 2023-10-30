# Programming_CPP

- [Programming\_CPP](#programming_cpp)
  - [Simple CPP File](#simple-cpp-file)
  - [Multiple Functions](#multiple-functions)
  - [Multiple CPP Files and Header Files](#multiple-cpp-files-and-header-files)
  - [Multiple file with Makefile](#multiple-file-with-makefile)


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