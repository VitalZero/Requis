#pragma once
#include <string>
#include <ctime>
#include <cassert>

// Maybe functor???
//class DateConverter
//{
//public:
//	time_t operator()(std::string& date)
//	{
//		// assert on 2 digits for day, 2 digits for month, 2 digits for year
//		assert(date.size() != DateLength);
//
//		tm tmDate = { 0 };
//
//		tmDate.tm_hour = 11; //set noon, just for fun
//		tmDate.tm_mday = std::stoi( date.substr(0, 2) ); // get day
//		tmDate.tm_mon = std::stoi( date.substr(3, 2) ); // get month
//		tmDate.tm_year = std::stoi( date.substr(6, 4) ); // get year
//
//		time_t ttDate = std::mktime(&tmDate);
//
//		return ttDate;
//	}
//private:
//	static constexpr int DateLength = 10;
//};

namespace Util
{
	time_t ConvertDate(std::string& date)
	{
		const unsigned int DateLength = 10;
		// assert on 2 digits for day, 2 digits for month, 2 digits for year
		assert(date.size() == DateLength);

		tm tmDate = { 0 };

		tmDate.tm_hour = 11; //set noon, just for fun
		tmDate.tm_mday = std::stoi(date.substr(0, 2)); // get day
		tmDate.tm_mon = std::stoi(date.substr(3, 2)); // get month
		tmDate.tm_year = std::stoi(date.substr(6, 4)); // get year

		time_t ttDate = std::mktime(&tmDate);

		return ttDate;
	}
}