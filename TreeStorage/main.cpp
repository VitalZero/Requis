#include <iostream>
#include "Records.h"
#include <algorithm>
#include <ctime>
#include "Requisicion.h"
#include <vector>
#include <cassert>

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
	//{
	//	time_t tRequest = 0;
	//	time_t tElaboration = 0;
	//	// get today's date and time
	//	std::time(&tRequest);
	//	std::time(&tElaboration);

	//	Records reg;
	//	reg.Insert( 22340, "29/04/2020", "04/05/2020", "", 166320, true );
	//	reg.Insert(Element(22340, tElaboration, tRequest, 0, 123490, false));
	//	reg.Insert(Element(45398, tElaboration, tRequest, 0, 58674, true));
	//	reg.Insert(22339, "25/04/2020", "04/05/2020", "", 391320, true);
	//	reg.SaveToFile();
	//	std::cout << "The following records will be saved (try): \n";
	//	reg.ListRequi();
	//}

	//std::cout << "======================================\n";
	////test code to load elements to memory from file
	//{
	//	Records reg;
	//	reg.LoadFromFile();
	//	std::cout << "\nThe following records has been loaded \n";
	//	reg.ListRequi(true);
	//}
	std::vector<Requi> Requisiciones;

	Requisiciones.emplace_back( 22366, 1916003, Requi::Estatus::Libre, 16, "12/05/2020" );
	Requisiciones.emplace_back( 22367, 1571001, Requi::Estatus::Libre, 16, "12/05/2020" );
	Requisiciones.emplace_back( 22262, 2918560, Requi::Estatus::Libre, 16, "07/03/2020" );

	{
		std::ofstream file( "prueba.txt", std::ios::trunc );

		//if ( !file.is_open() )
		//{
		//	throw std::exception( "No se pudo abrir el archivo" );
		//}

		for ( auto& r : Requisiciones )
		{
			r.Serialize( file );
		}
	}

	{
		std::ifstream file( "prueba.txt" );

		Requi r;
		r.Deserialize( file );
	}

	std::cin.get();
	return 0;
}
