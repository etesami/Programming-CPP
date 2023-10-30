#include <iostream>
#include <fstream>

int main() {
    // Writing to a file
    std::ofstream outFile("sample.txt.o"); // Create a file named "sample.txt" for writing

    if (outFile.is_open()) {
        outFile << "Hello, world!" << std::endl;
        outFile << "This is a sample file." << std::endl;
        outFile.close();
        std::cout << "Data written to the file." << std::endl;
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }

    // Reading from a file
    std::ifstream inFile("sample.txt.o"); // Open the file for reading

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
