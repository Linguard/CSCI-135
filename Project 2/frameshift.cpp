/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Project 2D
This program that compares the results of Task B with the mutated strands
The only thing I am changing here is the check_Met function.
It checks every nucelotide instead of every three.
Also, if Met is not found, it just moves on.This does not affect downstream 
as there are less than 3 nucleotides left so nothing gets printed from print_codon
*/

#include <iostream>
#include <fstream>		//including fstream to read file
#include <cstdlib>		//Including cstdlib to convert to uppercase

using namespace std;

char DNAbase_to_mRNAbase(char DNAbase);			//Convert DNA to RNA(one base pair)
string DNA_to_mRNA(string DNA);						//Convert DNA to RNA(string)
void dictionary_read(ifstream &dict, string rna, string &codon);	//refers to the dictionary
bool check_Met(string tRNA, int i, ifstream &dict, string &codon);	//Checks for Met
void print_codon(string tRNA, int i, ifstream &dict, string &codon);	//prints the codon

char DNAbase_to_mRNAbase(char DNAbase)		//Convert DNA to RNA(one base pair)
{
	char mRNAbase = '0';			//initializing mRNA

	if (DNAbase == 'A')			//Value of mRNA is determined based on the DNA value
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
	else				//If it is not an accepted value, give error
	{
		mRNAbase = 'e';
	}

	return mRNAbase;
}

string DNA_to_mRNA(string DNA)				//Convert DNA to RNA(string)
{
	string mRNA = "";				//Create an empty string for returning output 
	char tempmRNA = 'o';				//Creating tempmRNA to store the RNA value temporarily
	for (int i = 0; i < DNA.length(); i++)		//For each character in the DNA string
	{
		DNA[i] = toupper(DNA[i]);		//Convert to uppercase
		tempmRNA = DNAbase_to_mRNAbase(DNA[i]);	//hold the RNA value got from the DNAbase_to_mRNAbase function
		if (tempmRNA == 'e')			//Give ERROR for unaccepted values
		{
			mRNA = "ERROR";
			return mRNA;
		}
		else
		{
			mRNA = mRNA + tempmRNA;		//Concatenate the tempmRNA to the mRNA 
		}
	}
	return mRNA;
}

void dictionary_read(ifstream &dict, string rna, string &codon)	//refers to the dictionary
{
	string key, value;
	dict.clear(); 	// reset error state
	dict.seekg(0); 	// return file pointer to the beginning
	while (dict >> key >> value)
	{
		if (key == rna)
		{
			codon = value;
		}
	}
}

bool check_Met(string tRNA, int i, ifstream &dict, string &codon)	//Checks for Met
{
	string three_nucleotides = tRNA.substr(i,3);

	if (three_nucleotides.length() < 3)
	{
		cout << endl;
		return true;
	}
	dictionary_read(dict, three_nucleotides, codon);

	
	if (codon == "Met")
	{
		cout << "Met";
		return true;
	}
	else
	{
		return false;
	}
}

void print_codon(string tRNA, int i, ifstream &dict, string &codon)	//prints the codon
{
	for (int x = i + 3; x < tRNA.length(); x = x + 3)
	{
		string three_nucleotides = tRNA.substr(x,3);

		if (three_nucleotides.length() > 2)
		{
			dictionary_read(dict, three_nucleotides, codon);
			if (codon != "Stop")
			{
				cout << '-' << codon;
			}
			else
			{
				cout << endl;
				return;
			}
		}
		else
		{
			cout << endl;
			return;
		}
	}
}

int main()
{
	string codon;

	ifstream dna("frameshift_mutations.txt");	//Calling frameshift_mutations.text and storing it
	ifstream codon_dict("codons.tsv");		//Calling codons dictionary and storing it

	if (dna.fail())
	{
		cerr << "DNA file cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	if (codon_dict.fail())
	{
		cerr << "Codon Dictionary cannot be read, opened, or does not exist.\n";
		exit(-1);
	}

	string strand;

	while(getline(dna, strand))
	{
		if (strand.length() > 2)		//If nothing in string, dont do it
		{
			int i = 0;

			string tRNA = DNA_to_mRNA(strand);

			while (check_Met(tRNA, i, codon_dict, codon) == false)	//Until Met, nothing happens
			{
					i++;		//Increment i to get the next codon
			}

			print_codon(tRNA, i, codon_dict, codon);	//Prints codons
		}
	}
	dna.close();

}
