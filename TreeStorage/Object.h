#pragma once
// Persistent Object
#include <fstream>

class Object
{
public:
	virtual void Serialize( std::ofstream& fs ) = 0;
	virtual void Deserialize( std::ifstream& fs ) = 0;
};