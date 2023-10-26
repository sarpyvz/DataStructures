#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
private:
    std::string carType; // e.g., sedan, SUV, etc.

public:
    Car(std::string license, std::string mod, int yr, double miles, std::string type)
        : Vehicle(license, mod, yr, miles), carType(type) {} // bu şey ile aynı 
                                                             // Car(std::string license, std::string mod, int yr, double miles, std::string type){burda variable yaparsan}

    void displayInfo() const override;
};

#include "Car.cpp"
