#include "Element.h"

Element::Element(uint16_t requi, time_t originDate,
	time_t requestDate, time_t authorizedDate, uint32_t amount, bool hasTax, bool authorized)
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
	authorizedDate = std::time(nullptr);
	authorized = true;
}

