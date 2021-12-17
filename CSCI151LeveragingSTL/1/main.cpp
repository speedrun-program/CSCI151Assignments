
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Initial: " << cars << "\n";

    std::sort(cars.begin(), cars.end(), [](const Car& car1, const Car& car2){ return car1.price() > car2.price(); });
    std::cout << "\nReversed: " << cars << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
