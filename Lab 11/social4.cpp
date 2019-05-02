/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Lab 11D
The three main functionalities of the class Network are:
1) adding new users to the network, 2) following, and 3) posting messages.
Write a new program social4.cpp, in which users can post messages and view their timelines.
*/

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string>

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

struct Post{
	string username;
	string message;
        Post(string usrn, string msg);
        Post();
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
	bool following[MAX_USERS][MAX_USERS];	// friendship matrix:
	// following[id1][id2] == true when id1 is following id2
	static const int MAX_POSTS = 100;
	int numPosts;                    // number of posts
	Post posts[MAX_POSTS];           // array of all posts
public:
	// Constructor, makes an empty network (numUsers = 0)
	Network();
	// Attempts to sign up a new user with specified username and displayname
	// return true if the operation was successful, otherwise return false
	bool addUser(string usrn, string dspn);
	// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
	// return true if success (if both usernames exist), otherwise return false
	bool follow(string usrn1, string usrn2);

	// Print Dot file (graphical representation of the network)
	void printDot();
	// Add a new post
	bool writePost(string usrn, string msg);
	// Print user's "timeline"
	bool printTimeline(string usrn);

};

Profile::Profile(string usrn, string dspn)	// Profile Constructor
{
	username = usrn;
	displayname = dspn;
}

Profile::Profile()
{
	username = "";
	displayname = "";
}

string Profile::getUsername()			// Returns the username
{
	return username;
}

string Profile::getFullName()	// Return name in the format: "displayname (@username)"
{
	string name = displayname + " (@" + username + ")";

	return name;
}

void Profile::setDisplayName(string dspn)
{
	displayname = dspn;

	return;
}

Post::Post(string usrn, string msg)	// Post Constructor
{
	username = usrn;
	message = msg;
}

Post::Post()
{
	username = "";
	message = "";
}

Network::Network()				// Network Constructor
{
	numUsers = 0;
	numPosts = 0;
	for (int i = 0; i < MAX_USERS; i++)
	{
		for (int j = 0; j < MAX_USERS; j++)
		{
			following[i][j] = false;
		}
	}

}

int Network::findID (string usrn)
{
	for (int i = 0; i < numUsers; i++)
	{
		if (profiles[i].getUsername() == usrn)
		{
			return i;
		}
	}
	return -1;
}

bool Network::addUser(string usrn, string dspn)
{
	if (usrn == "" or usrn == " ")
	{
		return false;
	}
	else if (numUsers >= 20)
	{
		return false;
	}
	
	for (int i = 0; i < usrn.length(); i++)
	{
		if (!(isalnum(usrn[i])))
		{
			return false;
		}
	}

	for (int i = 0; i <= numUsers; i++)
	{
		if (profiles[i].getUsername() == usrn)
		{
			return false;
		}
	}

	profiles[numUsers] = Profile(usrn, dspn);
	numUsers++;

	return true;
}
bool Network::follow(string usrn1, string usrn2)
{
	int user1_location = findID (usrn1);
	int user2_location = findID (usrn2);

	//if usrn1 in profiles and usrn2 in profiles,
	//then mark the position in following as true

	if (user1_location == -1)
	{
		return false;
	}
	else if (user2_location == -1)
	{
		return false;
	}
	else
	{
		following[user1_location][user2_location] = true;
		return true;
	}
}

void Network::printDot()
{

	cout << "digraph { " << endl;
	for (int i = 0; i < numUsers; i++)
	{
		cout << "\t\"@" << profiles[i].getUsername() << "\"" << endl;
	}

	cout << endl;

	for (int i = 0; i < numUsers; i++)
	{
		for (int j = 0; j < numUsers; j++)
		{
			if (following[i][j] == true)
			{
				cout << "\t\"@" << profiles[i].getUsername() << "\" -> \"@";
				cout << profiles[j].getUsername() << "\"" << endl;
			}
		}
	}
	cout << "}" << endl;

	return;
}

bool Network::writePost(string usrn, string msg)
{
	if (findID(usrn) != -1 and numPosts < MAX_POSTS)
	{
		posts[numPosts] = Post(usrn, msg);
		numPosts++;

		return true;
	}

	return false;
}

/*
The second function, printTimeline(usrn) prints out the timeline of the user usrn.
The timeline of a user is the list of all posts by the user and by the people they follow,
presented in reverse-chronological order.
*/
bool Network::printTimeline(string usrn)
{
	int user1 = findID(usrn);

	for (int i = numPosts - 1; i >= 0; i--)
	{
		int user2 = findID(posts[i].username);

		if (user1 == user2 or following[user1][user2] == true)
		{
			cout << profiles[user2].getFullName() << ": " << posts[i].message;
			cout << endl;
		}
	}
}

int main()
{
	Network nw;
	// add three users
	nw.addUser("mario", "Mario");
	nw.addUser("luigi", "Luigi");
	nw.addUser("yoshi", "Yoshi");

	nw.follow("mario", "luigi");
	nw.follow("luigi", "mario");
	nw.follow("luigi", "yoshi");
	nw.follow("yoshi", "mario");

	// write some posts
	nw.writePost("mario", "It's a-me, Mario!");
	nw.writePost("luigi", "Hey hey!");
	nw.writePost("mario", "Hi Luigi!");
	nw.writePost("yoshi", "Test 1");
	nw.writePost("yoshi", "Test 2");
	nw.writePost("luigi", "I just hope this crazy plan of yours works!");
	nw.writePost("mario", "My crazy plans always work!");
	nw.writePost("yoshi", "Test 3");
	nw.writePost("yoshi", "Test 4");
	nw.writePost("yoshi", "Test 5");

	cout << endl;
	cout << "======= Mario's timeline =======" << endl;
	nw.printTimeline("mario");
	cout << endl;

	cout << "======= Yoshi's timeline =======" << endl;
	nw.printTimeline("yoshi");
	cout << endl;
}

