#include "PrimeNumber.h"
#include <iostream>
#include <stdexcept>

// Check if a number is prime
bool PrimeNumber::isPrime(long long num) const {
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Default Constructor
PrimeNumber::PrimeNumber() : value(2) {}

// One-Parameter Constructor
PrimeNumber::PrimeNumber(long long val) {
    if (isPrime(val)) {
        value = val;
    } else {
        throw std::invalid_argument("Value must be a prime number.");
    }
}

// Get value
long long PrimeNumber::getValue() const {
    return value;
}

// Set value with validation
void PrimeNumber::setValue(long long val) {
    if (isPrime(val)) {
        value = val;
    } else {
        throw std::invalid_argument("Value must be a prime number.");
    }
}

// Overload << operator for output
std::ostream& operator<<(std::ostream& os, const PrimeNumber& prime) {
    os << prime.value;
    return os;
}

// Overload >> operator for input
std::istream& operator>>(std::istream& is, PrimeNumber& prime) {
    long long val;
    is >> val;
    if (!prime.isPrime(val)) {
        throw std::invalid_argument("Input must be a prime number.");
    }
    prime.value = val;
    return is;
}

// Get the next prime number
PrimeNumber& PrimeNumber::operator++() { // Prefix
    long long next = value + 1;
    while (!isPrime(next)) ++next;
    value = next;
    return *this;
}

PrimeNumber PrimeNumber::operator++(int) { // Postfix
    PrimeNumber temp = *this;
    ++(*this);
    return temp;
}

// Get the previous prime number
PrimeNumber& PrimeNumber::operator--() { // Prefix
    long long prev = value - 1;
    while (prev > 1 && !isPrime(prev)) --prev;
    if (prev < 2) prev = 2; // The smallest prime number is 2
    value = prev;
    return *this;
}

PrimeNumber PrimeNumber::operator--(int) { // Postfix
    PrimeNumber temp = *this;
    --(*this);
    return temp;
}

// Overload == operator
bool PrimeNumber::operator==(const PrimeNumber& other) const {
    return value == other.value;
}

// Overload != operator
bool PrimeNumber::operator!=(const PrimeNumber& other) const {
    return value != other.value;
}

// Overload + operator
PrimeNumber PrimeNumber::operator+(const PrimeNumber& other) const {
    return PrimeNumber(value + other.value);
}

// Overload - operator
PrimeNumber PrimeNumber::operator-(const PrimeNumber& other) const {
    return PrimeNumber(value - other.value);
}
