#pragma once
#include <string>
#include <vector>
#include "Element.h"

class Records
{
public:
	friend std::ostream& operator<<(std::ostream& out, const Element& rhs)
	{
		out << "Id: " << rhs.GetId() << ", Requi: " << rhs.GetRequi() << ", Monto: $ "
			<< int(rhs.GetAmount() / 100) << "." << int(rhs.GetAmount() % 100) 
			<< (rhs.IsTaxed() ? " mas IVA":" neto (no aplica IVA)");

		return out;
	}
	void Insert(Element& element);
	void Insert(unsigned int requi, std::string orignDate, std::string requestDate, std::string authorizedDate,
		unsigned long amount, bool hasTax);
	void SaveToFile();
	void LoadFromFile();
	void ListRequi(bool ordered = false);
private:
	std::vector<Element> elements;
	unsigned int nRecords = 0;
};