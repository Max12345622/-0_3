#include "date.h"
#include <string>
#include<iomanip>
#include<fstream>
void Date::setDay(int d) 
{
	correctDate(d, 1, 1);
	day = d;
};
void Date::setMonth(int m) 
{
	correctDate(1, m, 1);
	month = m;
};
void Date::setYear(int y) 
{
	correctDate(1, 1, y);
	year = y;
};
int Date::getDay()
{
	return day;
};
int Date::getMonth() 
{
	return month;
};
int Date::getYear() 
{
	return year;
};

void Date::funcia_date(std::istream& ist) 
{
	std::string Date;
	ist >> Date;
	readDate(Date);
};
void Date::printDate(std::ostream& out) 
{
	out << day << "." << month << "." << year;
};
void Date::correctDate(int d, int m, int y) 
{
	int maxDay = 31;
	switch (m) {
	case 2:
		maxDay = leapYear(y) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		break;
	}

	if (d < 1 or !(d <= maxDay)) throw std::runtime_error("Error! DAY not correct");
	if (m < 1 or m>12)throw std::runtime_error("Error! MONTH not correct");
	if (y < 1) throw std::runtime_error("Error! YEAR not correct");
};
bool Date::leapYear(int y) 
{
	if (y < 0) throw std::runtime_error("Error! Year must be positive");
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
};
void Date::readDate(std::string& dateStr) 
{
	if (dateStr[2] == '.' && dateStr[5] == '.')
	{
		int d = stoi(dateStr.substr(0, 2));
		int m = stoi(dateStr.substr(3, 5));
		int y = stoi(dateStr.substr(6, 10));
		correctDate(d, m, y);
		day = d;
		month = m;
		year = y;
	}
	else throw std::runtime_error{"Error! Invalid SEPARATOR"};
};
