#pragma once
#include <cstdint>
#include <ctime>

class Element
{
public:
	Element(uint16_t requi, time_t originDate,
		time_t requestDate, time_t authorizedDate, uint32_t amount, bool hasTax, bool authorized = false);
	void SetId(uint16_t id)
	{
		this->id = id;
	}
	uint16_t GetId() const
	{
		return id;
	}
	uint16_t GetRequi() const
	{
		return requi;
	}
	time_t GetOriginDate() const
	{
		return originDate;
	}
	time_t GetRequestDate() const
	{
		return requestDate;
	}
	time_t GetAuthorizedDate() const
	{
		return authorizedDate;
	}
	uint32_t GetAmount() const
	{
		return amount;
	}
	bool IsTaxed() const
	{
		return hasTax;
	}
	bool IsAuthorized() const
	{
		return authorized;
	}
	bool operator<(const Element& rhs)
	{
		return requi < rhs.requi;
	}
	bool operator>(const Element& rhs)
	{
		return requi > rhs.requi;
	}
	bool operator==(const Element& rhs)
	{
		return requi == rhs.requi;
	}
	bool operator!=(const Element& rhs)
	{
		return !(*this == rhs);
	}
	void Authorize();
	void Print();
private:
	uint16_t id;
	uint16_t requi;
	time_t originDate;
	time_t requestDate;
	time_t authorizedDate;
	uint32_t amount;
	bool hasTax;
	bool reviewed = true;
	bool authorized = false;
};