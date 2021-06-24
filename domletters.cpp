//This is the main driver program for the dominant letters counter program. It takes in the input file when ran and scans that text file to count all dominant letters, then outputs the total. 

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int findLetterCount(string word);				//finds the dominant letter count from word


int main()
{
	string word;					//holds word to be sent to letter count function
	string temp;					//holds word temporarily before changing to lowercase

	int domCount = 0;				//running total of dom letters
	
	while(cin >> temp)				//reads in a "word" at a time
	{
		int length = temp.length();		//holds word length
		for(int i = 0; i < length; ++i)		//changes word to lowercase
		{
			word += tolower(temp[i]);
		}
		domCount += findLetterCount(word);	//adds each word dom count to total
		word.clear();
	}

	cout << "Total count = " <<domCount <<endl;     //outputs total dom letter count to screen

	return 0;
}


//this function takes in a word as a string and calculates which letter occurs most.
//if any invalid characters (not a-z) are read, the word count stops and this returns 0
//returns the highest count otherwise
int findLetterCount(string word)
{
	int letters[26]; 			//to keep track of each letter count
	int count = 0;
	int length = word.length();
	
	for(int i = 0; i < 26; ++i)		//sets all to zero to avoid messed up count
		letters[i] = 0;
	
	for(int i=0; i < length; ++i)		//cycles through word, makes sure all valid characters 	
	{					//then adds the letter count in letters array
		if(word[i] > 96 && word[i] < 123)
		{
			int a = word[i];
			a = a - 97; 
			letters[a] += 1;
		}
		else				//if an invalid character is found, returns 0 for count
			return 0;		//ignoring the rest of the word
	}

	for(int i = 0; i < 26; ++i)		//loops through letters array to find highest
	{
		if(letters[i] > count)
			count = letters[i];
	}

	return count;				//returns dom count
}

