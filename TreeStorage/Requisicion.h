#pragma once
#include "Object.h"
#include <string>
#include <fstream>

class Requi : public Object
{
public:
	enum class Estatus : char
	{
		Libre = 'L', Solicitado = 'S', Autorizado = 'A', Rechazado = 'R', Cancelado = 'C'
	};

public:
	Requi() = default;
	Requi(unsigned int requi, unsigned long monto, const std::string& fechaOrigen, 
		unsigned short int impuesto );

public:
	void Serializar( std::ofstream& fs ) override;
	void Deserializar( std::ifstream& fs ) override;
	void Solicitar( const std::string& fechaSolicitud );
	void Autorizar( const std::string& fechaAutorizado );
	bool operator==( int requi )
	{
		return this->requi == requi;
	}

private:
	unsigned int requi;
  Estatus estado;
	std::string fechaOrigen;
	std::string fechaSolicitud;
	std::string fechaAutorizado;
	unsigned long monto;
	unsigned short int impuesto;
};