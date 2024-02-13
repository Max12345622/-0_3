# include <fstream>
class Date
{
	int day;
	int month;
	int year;
public:	
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
	
	void funcia_date(std::istream& ist);
	void printDate(std::ostream& out);
	void correctDate(int d, int m, int y);
	bool leapYear(int y);
	void readDate(std::string& dateStr);
};

