/*
Name: Saqibul Islam Chowdhury
CSCI 135
Instructor: Genady Maryash
HW E7.20
Define a data-only class Employee with a name and an Employee* pointer to the employee's manager.
For the CEO, that pointer will be a nullptr.
Write a program that defines several employees and their managers.
For each employee, print the chain of superiors.
*/

#include <iostream>

using namespace std;

class Employee {
public:
	string name;
	Employee* manager;
};

int main()
{
	Employee CEO;
	CEO.name = "John Hastings";
	CEO.manager = nullptr;
	
	Employee Executive;
	Executive.name = "Charles Dickens";
	Executive.manager = &CEO;
	
	Employee Supervisor1;
	Supervisor1.name = "Karen Abstergo";
	Supervisor1.manager = &Executive;
	
	Employee Supervisor2;
	Supervisor2.name = "Joseph Auditore";
	Supervisor2.manager = &Executive;
	
	Employee Worker1;
	Worker1.name = "Ramanujan";
	Worker1.manager = &Supervisor1;
	
	Employee Worker2;
	Worker2.name = "Paul Diablo";
	Worker2.manager = &Supervisor1;
	
	Employee Worker3;
	Worker3.name = "Michael Angelo";
	Worker3.manager = &Supervisor2;

	cout << Supervisor1.manager->name << " - " << (Supervisor1.manager)->manager->name  << endl;
	cout << Supervisor2.manager->name << " - " << (Supervisor2.manager)->manager->name  << endl;
	cout << Worker1.manager->name << " - " << (Worker1.manager)->manager->name << " - " << (Worker1.manager)->manager->manager->name  << endl;
	cout << Worker2.manager->name << " - " << (Worker2.manager)->manager->name << " - " << (Worker2.manager)->manager->manager->name    << endl;
	cout << Worker3.manager->name << " - " << (Worker3.manager)->manager->name << " - " << (Worker3.manager)->manager->manager->name    << endl;
}