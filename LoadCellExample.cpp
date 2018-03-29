#include "LoadCell.h"

#include <iostream>
#include <string>

void main(int argc, char* argv[])
{
	int dataInterval = 10;
	LoadCell sensor1 = LoadCell(dataInterval, BRIDGE_GAIN_1, 1);
	LoadCell sensor2 = LoadCell(dataInterval, BRIDGE_GAIN_1, 0);

	double measurement1 = 0;
	double measurement2 = 0;

	int counter = 0;
	while (1)
	{
		sensor1.getMeasurement(measurement1);
		sensor2.getMeasurement(measurement2);
		::std::cout  << "sensor 1 value =" << measurement1 << "\t sensor 2 value =" << measurement2 << ::std::endl;
		Sleep(100);
	}

}