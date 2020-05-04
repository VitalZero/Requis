#pragma once
#include <string>
#include <vector>
#include "Element.h"

using RecordSet = std::vector<Element>;

class Records
{
public:
	void Insert( Element& element );
	void Insert( Element&& element );
	void Insert( unsigned int requi, std::string orignDate, std::string requestDate, std::string authorizedDate,
		unsigned long amount, bool hasTax );
	void SaveToFile();
	void LoadFromFile();
	void ListRequi( bool ordered = false );

private:
	void WriteHeader( std::ostream& out );
	bool ReadHeader( std::istream& in );

private:
	RecordSet elements;
	unsigned int nRecords = 0;
	static constexpr char nVersionMajor = 1;
	static constexpr char nVersionMinor = 0;
	static constexpr char sSignature[2] = {'V','Z'};
};