#pragma once

#include <string>
#include <vector>

class Vehicle; // Same as #include "Vehicle.h"

class ServiceRecord
{
private:
    Vehicle *vehicle;
    std::string serviceDate;
    std::vector<std::string> partsChanged;

public:
    ServiceRecord(Vehicle *veh, const std::string &date)
        : vehicle(veh), serviceDate(date) {}

    // Getter for vehicle
    int* getVehicle(){
    	return *vehicle;
	}
    // Getter for serviceDate
    char* getServiceDate(){
    	return *serviceDate;
	}
    // Getter for partsChanged
	string getPartsChanged(){
		return partsChanged;
	}
    

    void addPartChanged(const std::string &part);
    void displayRecord() const;
};

#include "ServiceRecord.cpp"
