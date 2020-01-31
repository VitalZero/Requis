#pragma once
#include <string>
#include <vector>
#include "Element.h"

class Records
{
public:
	void Insert(Element& element);
	void Insert(Element&& element);
	void Insert(unsigned int requi, std::string orignDate, std::string requestDate, std::string authorizedDate,
		unsigned long amount, bool hasTax);
	void SaveToFile();
	void LoadFromFile();
	void ListRequi(bool ordered = false);
private:
	std::vector<Element> elements;
	unsigned int nRecords = 0;
};