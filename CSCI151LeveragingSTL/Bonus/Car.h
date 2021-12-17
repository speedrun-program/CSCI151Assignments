#pragma once
#include <string>
#include <ostream>
#include <random>

class Car {
public:
    Car(std::string vin, double price);

    std::string vin() const;
    double price() const;
    void updatePrice(double value);

    static Car createRandom();

private:
    std::string _vin;
    double _price;
};

bool operator==(const Car& first, const Car& second);
std::ostream& operator<<(std::ostream& out, const Car& car);