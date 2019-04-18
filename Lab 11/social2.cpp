/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 11B
The three main functionalities of the class Network are:
1) adding new users to the network, 2) following, and 3) posting messages.
Write a program social2.cpp, implementing the first version of the class Network
*/

#include <iostream>

using namespace std;

class Profile {
private:
	string username;
	string displayname;
public:
	// Profile constructor for a user (initializing 
	// private variables username=usrn, displayname=dspn)
	Profile(string usrn, string dspn);
	// Default Profile constructor (username="", displayname="")
	Profile();
	// Return username
	string getUsername();
	// Return name in the format: "displayname (@username)"
	string getFullName();
	// Change display name
	void setDisplayName(string dspn);
};

class Network {
private:
	static const int MAX_USERS = 20;// max number of user profiles
	int numUsers;			// number of registered users
	Profile profiles[MAX_USERS];	// user profiles array:
					// mapping integer ID -> Profile

	// Returns user ID (index in the 'profiles' array) by their username
	// (or -1 if username is not found)
	int findID (string usrn);
public:
	// Constructor, makes an empty network (numUsers = 0)
	Network();
	// Attempts to sign up a new user with specified username and displayname
	// return true if the operation was successful, otherwise return false
	bool addUser(string usrn, string dspn);
};

Profile::Profile(string usrn, string dspn)	// Profile Constructor
{
	username = usrn;
	displayname = dspn;
}

string Profile::getUsername()			// returns the username
{
	return username;
}

string Profile::getFullName()			// Return name in the format: "displayname (@username)"
{
	string name = displayname + " (@" + username + ")";

	return name;
}

void Profile::setDisplayName(string dspn)
{
	displayname = dspn;

	return;
}

Network::Network()				//Network Constructor
{
	numUsers = 0;
}

// Returns user ID (index in the 'profiles' array) by their username
// (or -1 if username is not found)
int Network::findID (string usrn)
{
	
}

bool Network::addUser(string usrn, string dspn)
{
	
}
int main()
{
	Network nw;
	cout << nw.addUser("mario", "Mario") << endl;		// true (1)
	cout << nw.addUser("luigi", "Luigi") << endl;		// true (1)

	cout << nw.addUser("mario", "Mario2") << endl;		// false (0)
	cout << nw.addUser("mario 2", "Mario2") << endl;	// false (0)
	cout << nw.addUser("mario-2", "Mario2") << endl;	// false (0)

	for(int i = 2; i < 20; i++)
		cout << nw.addUser("mario" + to_string(i), 
			"Mario" + to_string(i)) << endl;	// true (1)

	cout << nw.addUser("yoshi", "Yoshi") << endl;		// false (0)
}

