#pragma once
#include <string>
#include <vector>
#include "Requisicion.h"
#include "Encabezado.h"

using Requisiciones = std::vector<Requi>;

class ColeccionRequis
{
public:
	void Insertar( unsigned int requi, unsigned long monto, const std::string& fechaOrigen,
		unsigned short int impuesto = 16);
	void Guardar();
	bool Cargar();
	void ListRequi( bool ordered = false );
	void SolicitarRequi( int requi, const std::string& fechaSolicitud );
	void AutorizarRequi( int requi, const std::string& fechaAutorizado );

private:
	void GuardarEncabezado( std::ofstream& out, Encabezado& encabezado );
	bool LeerEncabezado( std::ifstream& in, Encabezado& encabezado );

private:
	Requisiciones requisiciones;
};