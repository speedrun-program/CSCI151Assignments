
#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    int howManyCars = cars.size();
    double totalPrice = std::accumulate(cars.begin(), cars.end(), 0.0, [](double currentPrice, const Car& car) { return currentPrice + car.price(); });
    std::cout << "\nThe average price is: $" << totalPrice << " / " << howManyCars << " = $" << totalPrice / howManyCars << "\n";

    auto costRangePair = std::minmax_element(cars.begin(), cars.end(), [](const Car& car1, const Car& car2){ return car1.price() < car2.price(); });
    double minCost = costRangePair.first->price();
    double maxCost = costRangePair.second->price();
    std::cout << "The range is: $" << maxCost << " - $" << minCost << " = $" << maxCost - minCost << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
