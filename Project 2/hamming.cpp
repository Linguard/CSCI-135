/*
Name: Saqibul Chowdhury
CSCI 135
Lab Instructor: Anoop Aroor
Project 2C
This program calculates the Hamming distance between two strings
and also tells if the mutated DNA produces the same protein or not
*/

#include <iostream>
#include <fstream>						//including fstream to read file
#include <cstdlib>						//Including cstdlib to convert to uppercase

using namespace std;

char DNAbase_to_mRNAbase(char DNAbase);						//Convert DNA to RNA(one base pair)
string DNA_to_mRNA(string DNA);							//Convert DNA to RNA(string)
void dictionary_read(ifstream &dict, string rna, string &codon);		//Refers to the dictionary
bool check_Met(string tRNA, int i, ifstream &dict, string &codon);		//Checks for Met
string find_codon(string tRNA, int i, ifstream &dict, string &codon);		//finds the string of codons

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
		tempmRNA = DNAbase_to_mRNAbase(DNA[i]);		//hold the RNA value got from the DNAbase_to_mRNAbase function
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

void dictionary_read(ifstream &dict, string rna, string &codon)
{
	string key, value;
	dict.clear(); // reset error state
	dict.seekg(0); // return file pointer to the beginning
	while (dict >> key >> value)
	{
		if (key == rna)
		{
			codon = value;
		}
	}
}

bool check_Met(string tRNA, int i, ifstream &dict, string &codon)
{
	dictionary_read(dict, tRNA.substr(i,3), codon);
	if (codon == "Met")
	{
		return true;
	}
	else
	{
		return false;
	}
}

string find_codon(string tRNA, int i, ifstream &dict, string &codon)
{
	string protein;
	
	for (int x = i + 3; x < tRNA.length(); x = x + 3)
	{
		dictionary_read(dict, tRNA.substr(x,3), codon);
		if (codon != "Stop")
		{
			protein.append('-' + codon);
		}
		else
		{
			return protein;
		}
	}
}

int main()
{
	string codon;

	ifstream mutations("mutations.txt");		//Calling mutations.text and storing it
	ifstream codon_dict("codons.tsv");		//Calling codons dictionary and storing it

	if (mutations.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	if (codon_dict.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(2);
	}

	string strand1;
	string strand2;

	while(getline(mutations, strand1) and getline(mutations, strand2))
	{
		int hamming = 0;

		for (int x = 0; x < strand1.length(); x++)
		{
			if (strand1[x] != strand2[x])
			{
				hamming += 1;
			}
		}

		cout << hamming;

		if (strand1.length() > 2 and strand2.length() > 2)			//If nothing in string, don't do it
		{
			int i = 0;

			string tRNA1 = DNA_to_mRNA(strand1);
			string tRNA2 = DNA_to_mRNA(strand2);

			while (check_Met(tRNA1, i, codon_dict, codon) == false)		//Until Met, nothing happens
			{
				i = i + 3;						//Increment by 3 to get the next codon
			}
			string protein1 = find_codon(tRNA1, i, codon_dict, codon);	//Finds codons

			i = 0;

			while (check_Met(tRNA2, i, codon_dict, codon) == false)		//Until Met, nothing happens
			{
				i = i + 3;						//Increment by 3 to get the next codon
			}
			string protein2 = find_codon(tRNA2, i, codon_dict, codon);	//Finds codons

			if (protein1 == protein2)
			{
				cout << " no" << endl;
			}
			else
			{
				cout << " yes" << endl;
			}
		}
	}

	mutations.close();

}
