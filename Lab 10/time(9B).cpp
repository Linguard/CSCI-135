/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 10B
Add a new function to your program time.cpp:

Time addMinutes(Time time0, int min);
*/

#include <iostream>

using namespace std;

class Time {
public:
    int h;
    int m;
};

void printTime(Time time);
int minutesSinceMidnight(Time time); 		// Minutes passed since 0:00
int minutesUntil(Time earlier, Time later); // Difference of time in minutes
Time addMinutes(Time time0, int min);		// Creates and returns a new moment of time that is min minutes after time0

void printTime(Time time)
{
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
	int minutes = ((time.h * 60) + time.m); // Literally, just the time in minutes
	
	return minutes;
}

int minutesUntil(Time earlier, Time later)
{
	int difference = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
	
	return difference;
}

Time addMinutes(Time time0, int min)
{
	Time newtime;
	
	int minutes;
	int hours = 0;		// Initializing hours bcoz we might not change it
	
	minutes = time0.m + min;	// Adding min to the time
	
	if (minutes >= 60)		// If minutes > 60, mod it down
	{
		hours = minutes/60;		// and add the corresponding amount to hours
		minutes = minutes%60;
	}
	
	newtime.h = time0.h + hours;
	newtime.m = minutes;
	
	return newtime;
}

int main()
{
	Time initial;
	Time final_time;
	
	int min;
	
	cout << "Enter the initial time: ";
	cin >> initial.h >> initial.m;
	
	cout << "Enter the # of minutes: ";
	cin >> min;
	
	final_time = addMinutes(initial, min);
	
	cout << "The new time is ";
	printTime(final_time);
	cout << endl;
}