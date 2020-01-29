#include "Element.h"
#include <iostream>

Element::Element(uint32_t requi, time_t fechaElab,
	time_t fechaSol, time_t fechaAut, uint64_t monto, bool aplicaIva, bool authorized)
	:
	requi(requi),
	originDate(originDate),
	requestDate(requestDate),
	authorizedDate(authorizedDate),
	amount(amount),
	hasTax(hasTax),
	authorized(authorized)
{
}

void Element::Authorize()
{
	std::time(&authorizedDate);
	authorized = true;
}

void Element::Print()
{
	std::cout << "Id: " << id << ", Requi: " << requi << ", Monto: $ "
		<< amount << std::endl;
}

