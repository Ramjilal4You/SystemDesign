
#include "VehicleInfo.hxx"

#include <string>
#include <iostream>
using namespace std;

VehicleInfo::VehicleInfo(string vNumber, VehicleCategory vCategory)
{
	vehicleNumber = vNumber;
	vehicleCategory = vCategory;
	cout << "VehicleInfo Created : " << vehicleNumber << " : " << vehicleCategory << endl;
}

string VehicleInfo::getVehicleNumber()
{
	return vehicleNumber;
}

VehicleCategory VehicleInfo::getVehicleCategory()
{
	return vehicleCategory;
}

