#include "Requisicion.h"

Requi::Requi( unsigned int requi, unsigned long monto, const std::string& fechaOrigen,
	unsigned short int impuesto = 16 )
	:
	requi(requi), monto(monto), fechaOrigen(fechaOrigen), estado( Estatus::Libre ),
	impuesto( impuesto ), fechaSolicitud("0"), fechaAutorizado("0")
{}

void Requi::Serializar( std::ofstream & fs )
{
	fs << requi << " ";
	fs << monto << " ";
	fs << (char)estado << " ";
	fs << impuesto << " ";
	fs << fechaOrigen << " ";
	fs << fechaSolicitud << " ";
	fs << fechaAutorizado << " ";
}

void Requi::Deserializar( std::ifstream & fs )
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

void Requi::Solicitar( const std::string & fechaSolicitud )
{
	estado = Estatus::Solicitado;
	this->fechaSolicitud = fechaSolicitud;
}

void Requi::Autorizar( const std::string & fechaAutorizado )
{
	estado = Estatus::Autorizado;
	this->fechaAutorizado = fechaAutorizado;
}
