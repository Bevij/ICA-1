#include "header.h"



string randomNum(){

	int cycles = 0;
	int randNum = 0;
	//int numAccountsDifferent;
	time_t seconds = time(NULL);							// Seed for random numbers, can be used to determine time out in lock function
	bool exit = false;
	string filename;
	string accountNum;

	do{

		srand((unsigned) seconds * (cycles + 27));	// Setting the random number seed
		randNum = (10000 + rand() % 90000);				// Sets range for random number from 10000 - 99999
		accountNum = to_string(randNum);					// Starts at 10000 in order for the number to always be 5 digits
		filename = accountNum;

		ifstream filein(filename);

		if(!filein)
		{
			exit = true;
		}

		cycles++;												// Ensures that the seed will get randomized again while looping

	}while(!exit);

	cout << accountNum << endl;
	cin.ignore();
	cin.ignore();

	return accountNum;										// Returns string instead of int
}
