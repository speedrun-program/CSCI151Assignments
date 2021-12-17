
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <unordered_set>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}

bool anyPrime(const std::vector<int>& values) {
    return std::any_of(values.begin(), values.end(), [](int n)
    {
        if (n < 2)
        {
            return false;
        }
        // instructions said it's okay to use a raw for-loop here
        for (int divisor = 2; divisor <= n / 2; divisor++)
        {
            if (n % divisor == 0)
            {
                return false;
            }
        }
        std::cout << n << " is a prime number\n";
        return true;
    });
}
