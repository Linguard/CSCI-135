/*
Test program for translatase.cpp
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

int main()
{
	int i = 0;
	int x = 0;

	string codon;
	ofstream rna_file;
  	rna_file.open ("rna.txt");
  	
  	
	ifstream dna("dna2b.txt");
	ifstream codons("codons.tsv");

	if (dna.fail())
	{
		cerr << "File cannot be read, opened, or does not exist.\n";
		exit(1);
	}

	string strand;

	while(getline(dna, strand))
	{
		string tRNA = DNA_to_mRNA(strand);
		
		rna_file << tRNA << endl;
	}
	dna.close();
	rna_file.close();

}
