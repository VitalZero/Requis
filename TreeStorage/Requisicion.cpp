#include "Requisicion.h"

Requi::Requi( unsigned int requi, unsigned long monto, Estatus estado, unsigned short int impuesto, 
	const std::string & fechaOrigen, const std::string & fechaSolicitud, 
	const std::string & fechaAutorizado )
	:
	requi(requi), monto(monto), estado(estado), impuesto(impuesto), fechaOrigen(fechaOrigen),
	fechaSolicitud(fechaSolicitud), fechaAutorizado(fechaAutorizado)
{}

void Requi::Serialize( std::ofstream & fs )
{
	fs << requi << " ";
	fs << monto << " ";
	fs << (char)estado << " ";
	fs << impuesto << " ";
	fs << fechaOrigen << " ";
	fs << fechaSolicitud << " ";
	fs << fechaAutorizado << " ";
}

void Requi::Deserialize( std::ifstream & fs )
{
	fs >> requi;
	fs >> monto;
	char tmp;
	fs >> tmp;
	estado = (Estatus)tmp;
	fs >> impuesto;
	fs >> fechaOrigen;
	fs >> fechaSolicitud;
	fs >> fechaAutorizado;
}
