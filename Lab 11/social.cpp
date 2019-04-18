/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 11A
In this program, we implement the class Profile that can store the info about a user of the network.
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

Profile::Profile(string usrn, string dspn)
{
	username = usrn;
	displayname = dspn;
}

string Profile::getUsername()	//returns the username
{
	return username;
}

string Profile::getFullName()
{
	string name = displayname + " (@" + username + ")";

	return name;
}

void Profile::setDisplayName(string dspn)
{
	displayname = dspn;

	return;
}

int main()
{
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
