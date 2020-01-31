#include <iostream>
#include "Records.h"
#include <algorithm>
#include <ctime>

int main()
{
	//test code to insert elements to records and save to file
	{
		time_t tRequest = 0;
		time_t tElaboration = 0;
		// get today's date and time
		std::time(&tRequest);
		std::time(&tElaboration);

		Records reg;
		reg.Insert(Element(22132, tElaboration, tRequest, 0, 1586450, true));
		reg.Insert(Element(22340, tElaboration, tRequest, 0, 123490, false));
		reg.Insert(Element(45398, tElaboration, tRequest, 0, 58674, true));
		reg.Insert(21518, "15/01/2020", "18/01/2020", "", 879965, true);
		reg.SaveToFile();
		std::cout << "The following records has been saved: \n";
		reg.ListRequi();
	}

	std::cout << "======================================\n";
	//test code to load elements to memory from file
	{
		Records reg;
		reg.LoadFromFile();
		std::cout << "\nThe following records has been loaded \n";
		reg.ListRequi(true);
	}

	std::cin.get();
	return 0;
}
