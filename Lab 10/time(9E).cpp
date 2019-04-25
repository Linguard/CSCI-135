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

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time {
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printTime(Time time);
int minutesSinceMidnight(Time time); 		// Minutes passed since 0:00
int minutesUntil(Time earlier, Time later); // Difference of time in minutes
Time addMinutes(Time time0, int min);		// Creates and returns a new moment of time that is min minutes after time0
void printMovie(Movie m);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);

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

void printMovie(Movie mv)
{
	string g;
	switch (mv.genre)
	{
		case ACTION   : g = "ACTION"; break;
		case COMEDY   : g = "COMEDY"; break;
		case DRAMA    : g = "DRAMA";  break;
		case ROMANCE  : g = "ROMANCE"; break;
		case THRILLER : g = "THRILLER"; break;
	}
	cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
	Time endTime;
	
	endTime = addMinutes(ts.startTime, (ts.movie).duration);
	
	printMovie(ts.movie);
	cout << " [starts at ";
	printTime(ts.startTime);
	cout << ", ends by ";
	printTime(endTime);
	cout << "]";
	cout << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
	TimeSlot newslot;
	Time newtime;
	
	newtime = addMinutes(ts.startTime, ts.movie.duration);
	
	newslot.movie = nextMovie;
	newslot.startTime = newtime;
	
	return newslot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	Time end_timeslot;
	
	if (minutesUntil(ts1.startTime, ts2.startTime) > 0)			// If ts1 starts before ts2
	{
		end_timeslot = addMinutes(ts1.startTime, ts1.movie.duration);	// time when ts1 ends
		if (minutesUntil(end_timeslot, ts2.startTime) >= 0)				// If its earlier than start of ts2
		{
			return false;												// then no overlap
		}
		else
		{
			return true;
		}
	}
	else if (minutesUntil(ts1.startTime, ts2.startTime) < 0)	// If ts2 starts before ts1
	{
		end_timeslot = addMinutes(ts2.startTime, ts2.movie.duration);	//time when ts2 ends
		if (minutesUntil(end_timeslot, ts1.startTime) >= 0)				// If its earlier than start of ts1
		{
			return false;										// then no overlap
		}
		else
		{
			return true;
		}
	}
	else														//If they start at the same time
	{
		return true;
	}
}

int main()
{
	Movie movie1 = {"Back to the Future", COMEDY, 116};
	Movie movie2 = {"Black Panther", ACTION, 134};
	Movie movie3 = {"Shazam!", ACTION, 134};
	Movie movie4 = {"Titanic", ROMANCE, 194};

	TimeSlot morning = {movie1, {9, 15}};
	TimeSlot daytime = {movie2, {12, 15}};
	TimeSlot evening = {movie2, {16, 45}};
	TimeSlot noon = {movie3, {11, 10}};
	TimeSlot night = {movie4, {19, 30}};
	
	cout << timeOverlap(morning, noon) << endl;		
	cout << timeOverlap(noon, daytime) << endl;
	cout << timeOverlap(morning, daytime) << endl;	
	cout << timeOverlap(daytime, night) << endl;

}