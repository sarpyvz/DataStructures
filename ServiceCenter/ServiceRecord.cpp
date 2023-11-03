#include "ServiceRecord.h"
#include <iostream>

void ServiceRecord::addPartChanged(const std::string &part)
{
    ServiceRecord::partsChanged.push_back(part);
}

void ServiceRecord::displayRecord() const
{
    std::cout << ServiceRecord::getPartsChanged<< ServiceRecord::getVehicle<< ServiceRecord::getServiceDate << std::endl;
}
