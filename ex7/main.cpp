#include <iostream>

class ShallowCopy {
public:
    int* data;
    ShallowCopy(int val) {
        data = new int(val);
    }
};


class DeepCopy {
public:
    int* data;
    DeepCopy(int val) {
        data = new int(val);
    }
    
    // Custom copy constructor for deep copy
    // const DeepCopy& other: a reference to a constant DeepCopy object
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);
    }
    
    // Custom copy assignment operator for deep copy
    DeepCopy& operator=(const DeepCopy& other) {
        if (this != &other) {
            delete data; // Free the existing resource
            data = new int(*other.data); // Perform deep copy
        }
        return *this;
    }
};


int main() {
    ShallowCopy obj1(42);
    std::cout << *obj1.data << std::endl;

    ShallowCopy obj2 = obj1; // Shallow copy
    *obj1.data = 10;
    
    std::cout << *obj1.data << " " << *obj2.data << std::endl;
    // Output: 10 10 (both objects share the same data)
    
    delete obj1.data; // This can cause issues when obj2 tries to access data


    DeepCopy obj3(42);
    DeepCopy obj4 = obj3; // Deep copy
    *obj3.data = 10;
    
    std::cout << *obj3.data << " " << *obj4.data << std::endl;
    // Output: 10 42 (each object has its own data)
    
    delete obj3.data; // No issue for obj4 because of deep copy

    return 0;
}