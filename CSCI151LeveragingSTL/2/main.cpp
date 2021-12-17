
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    int midpoint = integers.size() / 2;
    std::sort(integers.begin(), integers.begin() + midpoint);
    std::sort(integers.begin() + midpoint, integers.end(), [](int n1, int n2){ return n2 < n1; });
    std::cout << "\nBitonic: " << integers << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
