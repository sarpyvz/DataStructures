#pragma once

#include <string>
using namespace std;


class Vehicle
{
protected:
    std::string licensePlate;
    std::string model;
    int year;
    double mileage;

public:
    Vehicle(std::string license, std::string mod, int yr, double miles)
        : licensePlate(license), model(mod), year(yr), mileage(miles) {}

    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Vehicle() {}                 // Virtual destructor

    // Getter for license plate
	string getLicensePlate(){
		return licensePlate;
	}
    
    // Getter for model
    string getModel(){
    	return model;
	}
    // Getter for year
    int getYear(){
    	return year;
	}

    // Getter for mileage
    double getMileage(){
    	return mileage;
	}

    // Getter for license plate
	string getLicensePlate(){
		return licensePlate;
	}
    
    // Getter for model
    string getModel(){
    	return model;
	}
    // Getter for year
    int getYear(){
    	return year;
	}

    // Getter for mileage
    double getMileage(){
    	return mileage;
	}
};
