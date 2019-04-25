/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 10A
Create a new program time.cpp and mplement two new functions:

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
*/

#include <iostream>

using namespace std;

class Time {
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time); 		// Minutes passed since 0:00
int minutesUntil(Time earlier, Time later); // Difference of time in minutes

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

int main()
{
	Time first;
	Time second;
	
	cout << "Enter first time:  ";
	cin >> first.h >> first.m;
	
	cout << "Enter second time: ";
	cin >> second.h >> second.m;
	
	cout << "These moments of time are " << minutesSinceMidnight(first) << " and " << minutesSinceMidnight(second) << " minutes after midnight." << endl;
	cout << "The interval between them is " << minutesUntil(first, second) << " minutes.";
}