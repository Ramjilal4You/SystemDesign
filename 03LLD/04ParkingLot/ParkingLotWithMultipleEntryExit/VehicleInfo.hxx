#pragma once

#include "Constants.hxx"

#include <string>
using namespace std;

class VehicleInfo {
protected:
	string vehicleNumber;
	VehicleCategory vehicleCategory;
public:
	VehicleInfo(string vNumber, VehicleCategory vCategory);
	string getVehicleNumber();
	VehicleCategory getVehicleCategory();
};