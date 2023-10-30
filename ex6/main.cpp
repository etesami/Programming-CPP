#include <iostream>
#include <fstream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};


int main() {
    Complex a(1.0, 2.0);
    Complex b(2.0, 3.0);
    Complex c = a + b; // Calls the overloaded + operator
    std::cout << "Real: " << c.real << ", and imag: " << c.imag << std::endl;


    return 0;
}
