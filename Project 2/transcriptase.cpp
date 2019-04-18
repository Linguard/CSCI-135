/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Project 2A
This program reads a text file called dna.txt that contains one DNA strand per line
and outputs to the console (terminal) the corresponding mRNA strands
*/

#include <iostream>
#include <fstream>						//including fstream to read file
#include <cstdlib>						//Including cstdlib to convert to uppercase

using namespace std;

char DNAbase_to_mRNAbase(char DNAbase);
string DNA_to_mRNA(string DNA);

char DNAbase_to_mRNAbase(char DNAbase)
{
	char mRNAbase = '0';					//initializing mRNA

	if (DNAbase == 'A')					//Value of mRNA is determined based on the DNA value
	{
		mRNAbase = 'U';
	}
	else if (DNAbase == 'T')
	{
		mRNAbase = 'A';
	}
	else if (DNAbase == 'C')
	{
		mRNAbase = 'G';
	}
	else if (DNAbase == 'G')
	{
		mRNAbase = 'C';
	}
	else							//If it is not an accepted value, give error
	{
		mRNAbase = 'e';
	}

	return mRNAbase;
}

string DNA_to_mRNA(string DNA)
{
	string mRNA = "";					//Create an empty string for returning output 
	char tempmRNA = 'o';					//Creating tempmRNA to store the RNA value temporarily
	for (int i = 0; i < DNA.length(); i++)			//For each character in the DNA string
	{
		DNA[i] = toupper(DNA[i]);			//Convert to uppercase
		tempmRNA = DNAbase_to_mRNAbase(DNA[i]);		//hold the RNA value got from the DNAbase_to_mRNAbase function in the tempmRNA
		if (tempmRNA == 'e')				//Give ERROR for unaccepted values
		{
			mRNA = "ERROR";
			return mRNA;
		}
		else
		{
			mRNA = mRNA + tempmRNA;			//Concatenate the tempmRNA to the mRNA 
		}
	}
	return mRNA;
}

int main()
{

	ifstream fin("dna.txt");

	if (fin.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	string strand;

	while(getline(fin, strand))
	{
		cout << DNA_to_mRNA(strand) << endl;
	}

	fin.close();

}
