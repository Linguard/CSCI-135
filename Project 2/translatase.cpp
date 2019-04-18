/*
Name: Saqibul Chowdhury
CSCI 136
Lab Instructor: Anoop Aroor
Project 2B
This program takes strands of DNA (from dna2b.txt) and 
outputs to the console the corresponding amino-acid chain
*/

#include <iostream>
#include <fstream>						//including fstream to read file
#include <cstdlib>						//Including cstdlib to convert to uppercase

using namespace std;

char DNAbase_to_mRNAbase(char DNAbase);				//Convert DNA to RNA(one base pair)
string DNA_to_mRNA(string DNA);					//COnvert DNA to RNA(string)
void dictionary_read(ifstream &dict, string rna, string &codon);	//refers to the dictionary
bool check_Met(string tRNA, int i, ifstream &dict, string &codon);	//Checks for Met
void print_codon(string tRNA, int i, ifstream &dict, string &codon);	//prints the codon

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
		cout << "Met";
		return true;
	}
	else
	{
		return false;
	}
}

void print_codon(string tRNA, int i, ifstream &dict, string &codon)
{
	for (int x = i + 3; x < tRNA.length(); x = x + 3)
	{
		dictionary_read(dict, tRNA.substr(x,3), codon);
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
}

int main()
{
	string codon;

	ifstream dna("dna2b.txt");			//Calling dna2b.text and storing it
	ifstream codon_dict("codons.tsv");		//Calling codons dictionary and storing it

	if (dna.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	if (codon_dict.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(-1);
	}

	string strand;

	while(getline(dna, strand))
	{
		if (strand.length() > 2)				//If nothing in string, dont do it
		{
			int i = 0;

			string tRNA = DNA_to_mRNA(strand);

			while (check_Met(tRNA, i, codon_dict, codon) == false)	//Until Met, nothing happens
			{
				i = i + 3;		//Increment by 3 to get the next codon
			}

			print_codon(tRNA, i, codon_dict, codon);	//Prints codons
		}
	}
	dna.close();

}
