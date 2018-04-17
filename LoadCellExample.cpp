#include "LoadCell.h"

#include <iostream>
#include <fstream>
#include <string>

::std::string GetDateString()
{
  time_t rawtime;
  struct tm * timeinfo;

  char buffer [80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime (buffer,80,"%Y-%m-%d-%H-%M-%S", timeinfo);

  return ::std::string(buffer);
}

void main(int argc, char* argv[])
{
	int dataInterval = 10;
	LoadCell sensor1 = LoadCell(dataInterval, BRIDGE_GAIN_128, 1);
	LoadCell sensor2 = LoadCell(dataInterval, BRIDGE_GAIN_128, 0, voltageRatioToForce2);

	::std::string filename = GetDateString() + ".txt";
	::std::ofstream os(filename);
	double measurement1 = 0;
	double measurement2 = 0;

	int counter = 0;
	while (1)
	{
		sensor1.getMeasurement(measurement1);
		sensor2.getMeasurement(measurement2);
		//::std::cout  << "sensor 1 value =" << measurement1 << "\t sensor 2 value =" << measurement2 << ::std::endl;
		os  <<  measurement1 << "\t" << measurement2 << ::std::endl;
		Sleep(8);
	}

}