#include <iostream>
#include "Records.h"
#include <algorithm>
#include <ctime>

int main()
{
	//test code to insert elements to records and save to file
	
		time_t sol = 0;
		time_t elab = 0;
		std::time(&sol);
		std::time(&elab);

		Records reg;
		reg.Insert(Element(22132, elab, sol, 0, 1586450, true));
		reg.Insert(Element(22340, elab, sol, 0, 123490, false));
		reg.Insert(Element(45398, elab, sol, 0, 58674, true));
		reg.Insert(Element(21518, elab, sol, 0, 879965, true));
		reg.SaveToFile();
		std::cout << "The following records has been saved: \n";
		reg.ListRequi();
	

	std::cout << "======================================\n";
	//test code to load elements to memory from file
	//{
	//	Records reg;
	//	reg.LoadFromFile();
	//	std::cout << "\nThe following records has been loaded \n";
	//	reg.ListRequi();
	//}

	std::cin.get();
	return 0;
}
