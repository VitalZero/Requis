#include "ColeccionRequis.h"
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <exception>

void ColeccionRequis::Insertar(unsigned int requi, unsigned long monto, 
	const std::string& fechaOrigen, unsigned short int impuesto )
{
	requisiciones.emplace_back(requi, monto, fechaOrigen, impuesto );
}

void ColeccionRequis::Guardar()
{
	std::ofstream file("datos.txt", std::ios::trunc);
	assert(file);

	if (file)
	{
		Encabezado encabezado( (unsigned int)requisiciones.size() );

		if ( encabezado.NumRequis() > 0 )
		{
			GuardarEncabezado( file, encabezado );

			for ( auto& r : requisiciones )
			{
				r.Serializar( file );
			}
		}
	}
}

bool ColeccionRequis::Cargar()
{
	std::ifstream file( "datos.txt" );
	assert(file);

	if (file)
	{
		Encabezado encabezado( 0 );

		if ( LeerEncabezado( file, encabezado ) )
		{
			unsigned int numRequis = encabezado.NumRequis();
			if ( numRequis > 0 )
			{
				requisiciones.clear();

				for ( unsigned int i = 0; i < numRequis && file.good(); ++i )
				{
					Requi r;
					r.Deserializar( file );

					requisiciones.emplace_back( r );
				}
			}
		}
		else
		{
			return false;
		}

		return false;
	}

	return true;
}

void ColeccionRequis::ListRequi( bool ordered )
{
}

void ColeccionRequis::SolicitarRequi( int requi, const std::string & fechaSolicitud )
{
	auto itr = std::find( requisiciones.begin(), requisiciones.end(), requi );

	if ( itr != requisiciones.end() )
	{
		itr->Solicitar( fechaSolicitud );
	}
}

void ColeccionRequis::AutorizarRequi( int requi, const std::string & fechaAutorizado )
{
	auto itr = std::find( requisiciones.begin(), requisiciones.end(), requi );

	if ( itr != requisiciones.end() )
	{
		itr->Autorizar( fechaAutorizado );
	}
}

void ColeccionRequis::GuardarEncabezado( std::ofstream & out, Encabezado& encabezado )
{
	try
	{
		encabezado.Serializar( out );
	}
	catch ( std::exception& e )
	{
		std::cout << "Error en guardar el archivo: " << e.what() << "\n";
		std::cout << "El archivo no se guardo." << std::endl;
	}

}

bool ColeccionRequis::LeerEncabezado( std::ifstream& in, Encabezado& encabezado )
{
	try
	{
		encabezado.Deserializar( in );
	}
	catch ( std::exception& e )
	{
		std::cout << "Encabezado incorrecto: " << e.what() << "\n";
		std::cout << "No se pudo leer el archivo." << std::endl;
		return false;
	}

	return true;
}
