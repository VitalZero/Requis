#pragma once
#include <string>
#include <ctime>
#include <cassert>

class DateConverter
{
public:
	DateConverter(std::string& date)
		:
		date(date),
		ttDate(0)
	{
		// assert on 2 digits for day, 2 digits for month, 2 digits for year
		assert(date.size() != DateLength);

		tm tmDate = { 0 };

		tmDate.tm_hour = 11; //set noon, just for fun
		tmDate.tm_mday = std::stoi( date.substr(0, 2) ); // get day
		tmDate.tm_mon = std::stoi( date.substr(3, 2) ); // get month
		tmDate.tm_year = std::stoi( date.substr(6, 4) ); // get year

		ttDate = std::mktime(&tmDate);
	}
	time_t GetDateTT() const
	{
		return ttDate;
	}
private:
	std::string date;
	time_t ttDate;
	static constexpr int DateLength = 10;
};