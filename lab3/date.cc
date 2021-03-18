#include <ctime> // time and localtime
#include <iostream>
#include "date.h"
#include <iomanip>

using std::setfill;
using std::setw;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
	time_t timer = time(0);			 // time in seconds since 1970-01-01
	tm *locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year{y}, month{m}, day{d} {}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::next()
{
	int days_in_a_month = daysPerMonth[month - 1];

	if (days_in_a_month == day)
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
		}
		else
		{
			month++;
		}
	}
	else
	{
		day++;
	}
}

std::ostream &operator<<(std::ostream &os, const Date &dt)
{
	os << setw(4) << setfill('0') << dt.getYear() << '-';
	os << setw(2) << setfill('0') << dt.getMonth() << '-';
	os << setw(2) << setfill('0') << dt.getDay();
	return os;
}

std::istream &operator>>(std::istream &is, Date &dt)
{
	int year = 0;
	int month = 0;
	int day = 0;
	int i1 = 0;
	int i2 = 0;
	std::string s = "";
	std::string line = "";
	std::getline(is, line);
	try
	{
		i2 = line.find("-");
		s = line.substr(i1, i2 - i1);
		year = stoi(s);

		i1 = i2 + 1;
		i2 = line.find("-", i1);
		s = line.substr(i1, i2 - i1);
		month = stoi(s);

		i1 = i2 + 1;
		i2 = line.size();
		s = line.substr(i1, i2 - i1 + 1);
		day = stoi(s);
	}
	catch (...)
	{
		is.setstate(std::ios_base::failbit);
		return is;
	}

	dt = Date(year, month, day);
	return is;
}