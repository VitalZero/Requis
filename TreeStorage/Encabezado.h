#pragma once
#include "Object.h"

class Encabezado : public Object
{
public:
	Encabezado( unsigned int numRequis );

public:
	void Serializar( std::ofstream& fs ) override;
	void Deserializar( std::ifstream& fs ) override;
	unsigned int NumRequis() const
	{
		return numRequis;
	}

private:
	unsigned int numRequis;
	static constexpr char versionMayor = 1;
	static constexpr char versionMenor = 0;
	static constexpr char firma[2] = { 'V','Z' };
	bool correcto;
};