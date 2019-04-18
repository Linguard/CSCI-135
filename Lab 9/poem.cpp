/*
Name: Saqibul Islam Chowdhury
CSCI 136
Lab 9D
Instructor: Anoop Aroor
Fix this program poem.cpp. It should still keep creating poems, but all dynamically allocated memory should get deleted when it is not needed.
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

	delete p;
        // assume that the poem p is not needed at this point
    }
}

