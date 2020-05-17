#include <iostream>
#include "ColeccionRequis.h"

int main()
{
	ColeccionRequis requis;

	//requis.Insertar( 22334, 4567800, "01/05/2020" );
	//requis.Insertar( 21345, 1672000, "01/04/2020", 16 );
	//
	//requis.Guardar();

	if ( requis.Cargar() )
	{
		//requis.AutorizarRequi( 22334, "17/05/2020" );
		requis.Guardar();
	}

	std::cin.get();
	return 0;
}
