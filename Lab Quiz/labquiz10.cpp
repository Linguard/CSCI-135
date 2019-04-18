


#include <iostream>

using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;
	string day_of_week;
};

int main()
{
	Date* today = new Date;

	today->year = 2019;
	today->month = 4;
	today->day = 11;
	today->day_of_week = "Thursday";
}
