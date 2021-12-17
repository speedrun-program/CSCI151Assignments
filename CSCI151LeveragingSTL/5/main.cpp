
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    std::transform(cars.begin(), cars.end(), std::back_inserter(taggedCars), [](const Car& car)
    {
        char firstChar = car.vin()[0];
        return Tag<Car>{ (firstChar >= 'A' && firstChar <= 'F') || car.price() < 10000.0, car };
    });
    std::cout << "\nTagged Cars before partition: " << taggedCars << "\n";

    std::partition(taggedCars.begin(), taggedCars.end(), [](const Tag<Car>& taggedCar){ return taggedCar.isTagged(); });
    std::cout << "\nTagged Cars after partition: " << taggedCars << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
