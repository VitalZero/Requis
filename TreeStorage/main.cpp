#include <iostream>
#include "Records.h"
#include <algorithm>
#include <ctime>

int main()
{
#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
	// Logic using the traditional preprocessor
	std::cout << "usando msvc traditional" << std::endl;
#else
	// Logic using cross-platform compatible preprocessor
	std::cout << "No usando el tradicional" << std::endl;
#endif

	//test code to insert elements to records and save to file
	{
		time_t tRequest = 0;
		time_t tElaboration = 0;
		// get today's date and time
		std::time(&tRequest);
		std::time(&tElaboration);

		Records reg;
		reg.Insert( 22340, "29/04/2020", "04/05/2020", "", 166320, true );
		reg.Insert(Element(22340, tElaboration, tRequest, 0, 123490, false));
		reg.Insert(Element(45398, tElaboration, tRequest, 0, 58674, true));
		reg.Insert(22339, "25/04/2020", "04/05/2020", "", 391320, true);
		reg.SaveToFile();
		std::cout << "The following records will be saved (try): \n";
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
