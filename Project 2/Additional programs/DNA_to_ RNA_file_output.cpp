/*
Name: Saqibul Chowdhury
CSCI 136

This program reads a text file which contains one DNA strand per line
and outputs a file with the corresponding mRNA strands
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
		tempmRNA = DNAbase_to_mRNAbase(DNA[i]);		//hold the RNA value got from the DNAbase_to_mRNAbase
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

	ifstream dna("frameshift_mutations.txt"); 	//Put your file name here
	ofstream rna("rna.txt");	//Make sure a file with this name exists

	if (dna.fail())
	{
		cerr << "DNA file cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	if (rna.fail())
	{
		cerr << "Output file most likely does not exist.\n";
		exit(1);
	}

	string strand;

	while(getline(dna, strand))
	{
		rna << DNA_to_mRNA(strand) << endl;
	}

	dna.close();
	rna.close();
}
