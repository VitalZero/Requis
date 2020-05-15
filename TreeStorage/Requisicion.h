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
	Requi(unsigned int requi, unsigned long monto, Estatus estado = Estatus::Libre, unsigned short int impuesto = 16,
		const std::string& fechaOrigen = "0", const std::string& fechaSolicitud = "0",
		const std::string& fechaAutorizado = "0");

public:
	void Serialize( std::ofstream& fs ) override;
	void Deserialize( std::ifstream& fs ) override;

private:
	unsigned int requi;
  Estatus estado;
	std::string fechaOrigen;
	std::string fechaSolicitud;
	std::string fechaAutorizado;
	unsigned long monto;
	unsigned short int impuesto;
};