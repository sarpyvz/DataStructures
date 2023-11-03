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
    Vehicle getVehicle(){
    	return *vehicle;
	}
    // Getter for serviceDate
    std::string getServiceDate(){
    	return serviceDate;
	}
    // Getter for partsChanged
	std::vector<string> getPartsChanged(){
		return partsChanged;
	}
    

    void addPartChanged(const std::string &part);
    void displayRecord() const;
};

#include "ServiceRecord.cpp"