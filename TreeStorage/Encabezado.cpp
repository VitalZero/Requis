#include "Encabezado.h"
#include <exception>

Encabezado::Encabezado( unsigned int numRequis )
	:
	numRequis(numRequis)
{
}

void Encabezado::Serializar( std::ofstream & fs )
{
	fs << firma << " ";
	fs << versionMayor << " ";
	fs << versionMenor << " ";
	fs << numRequis << "\n";
}

void Encabezado::Deserializar( std::ifstream & fs )
{
	char tmpFirma[3];
	fs >> tmpFirma;

	if ( tmpFirma[0] != firma[0] && tmpFirma[1] != firma[1] )
	{
		throw "Archivo invalido, no conocido";
	}

	char tmpMayor;
	fs >> tmpMayor;

	if ( tmpMayor != versionMayor )
	{
		throw std::exception( "Verison invalida" );
	}

	char tmpMenor;
	fs >> tmpMenor;

	if ( tmpMenor != versionMenor )
	{
		throw std::exception( "Verison invalida" );
	}

	fs >> numRequis;
}
