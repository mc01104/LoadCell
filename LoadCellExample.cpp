#include "LoadCell.h"

#include <iostream>
#include <string>

void main(int argc, char* argv[])
{
	int dataInterval = 30;
	LoadCell sensor = LoadCell(dataInterval);

	double measurement = 0;
	int counter = 0;
	while (1)
	{
		sensor.getMeasurement(measurement);
		::std::cout << "counter:" << ::std::to_string(counter++) << "\t sensor value =" << measurement << ::std::endl;

		Sleep(30);
	}

}