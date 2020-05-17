#pragma once
// Persistent Object
#include <fstream>

class Object
{
public:
	virtual void Serializar( std::ofstream& fs ) = 0;
	virtual void Deserializar( std::ifstream& fs ) = 0;
};