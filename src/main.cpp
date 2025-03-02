#include "PrimeNumber.h"
#include <iostream>

int main() {
    try {
        std::cout << "Testing PrimeNumber Class" << std::endl;

        // Test Constructors
        PrimeNumber p1;  // Default constructor (should be 2)
        PrimeNumber p2(7); // Valid prime
        std::cout << "Prime 1: " << p1 << std::endl;
        std::cout << "Prime 2: " << p2 << std::endl;

        // Test Increment Operators
        std::cout << "p2 before increment: " << p2 << std::endl;
        ++p2;
        std::cout << "p2 after prefix increment: " << p2 << std::endl;
        p2++;
        std::cout << "p2 after postfix increment: " << p2 << std::endl;

        // Test Decrement Operators
        std::cout << "p2 before decrement: " << p2 << std::endl;
        --p2;
        std::cout << "p2 after prefix decrement: " << p2 << std::endl;
        p2--;
        std::cout << "p2 after postfix decrement: " << p2 << std::endl;

        // Test Input
        PrimeNumber p3;
        std::cout << "Enter a prime number: ";
        std::cin >> p3;
        std::cout << "You entered: " << p3 << std::endl;

        // Test Equality Operators
        if (p1 == p3) {
            std::cout << "p1 and p3 are equal." << std::endl;
        } else {
            std::cout << "p1 and p3 are not equal." << std::endl;
        }

        // Test Addition and Subtraction
        PrimeNumber p4 = p1 + p2;
        std::cout << "p1 + p2 = " << p4 << std::endl;

        PrimeNumber p5 = p2 - p1;
        std::cout << "p2 - p1 = " << p5 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
