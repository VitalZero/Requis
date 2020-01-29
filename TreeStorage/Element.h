#pragma once
#include <cstdint>
#include <ctime>

class Element
{
public:
	Element(uint32_t requi, time_t originDate,
		time_t requestDate, time_t authorizedDate, uint64_t amount, bool hasTax, bool authorized = false);
	void SetId(uint32_t id)
	{
		this->id = id;
	}
	uint32_t GetId() const
	{
		return id;
	}
	bool operator<(const Element& rhs) const
	{
		return requi < rhs.requi;
	}
	uint32_t GetRequi() const
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
	uint64_t GetAmount() const
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
	void Authorize();
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
	void Print();
private:
	uint32_t id;
	uint32_t requi;
	time_t originDate;
	time_t requestDate;
	time_t authorizedDate;
	uint64_t amount;
	bool hasTax;
	bool reviewed = true;
	bool authorized = false;
};