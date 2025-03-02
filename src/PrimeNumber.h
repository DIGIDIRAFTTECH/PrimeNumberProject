#ifndef PRIMENUMBER_H
#define PRIMENUMBER_H

#include <iostream>

class PrimeNumber {
private:
    long long value;

    bool isPrime(long long num) const;

public:
    // Constructors
    PrimeNumber();
    PrimeNumber(long long val);

    // Accessors and Mutators
    long long getValue() const;
    void setValue(long long val);

    // Operator Overloads
    friend std::ostream& operator<<(std::ostream& os, const PrimeNumber& prime);
    friend std::istream& operator>>(std::istream& is, PrimeNumber& prime);

    PrimeNumber& operator++();      // Prefix increment
    PrimeNumber operator++(int);    // Postfix increment
    PrimeNumber& operator--();      // Prefix decrement
    PrimeNumber operator--(int);    // Postfix decrement

    bool operator==(const PrimeNumber& other) const;
    bool operator!=(const PrimeNumber& other) const;

    PrimeNumber operator+(const PrimeNumber& other) const;
    PrimeNumber operator-(const PrimeNumber& other) const;
};

#endif
