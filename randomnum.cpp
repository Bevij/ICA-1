#include "header.h"



int randomNum(){

	int cycles = 0;
	int randNum = 0;
	//int numAccountsDifferent;
	time_t seconds = time(NULL);							// Seed for random numbers, can be used to determine time out in lock function
	bool exit = false;

	do{

		srand((unsigned) seconds * (cycles + 27));	// Setting the random number seed
		randNum = (10000 + rand() % 90000);				// Sets range for random number from 10000 - 99999
																	// Starts at 10000 in order for the number to always be 5 digits

		// Waiting for database, but will just return a random 5 digit number for now
		/*
		numAccountsDifferent = 0;							// Checks to see if all the accounts have a different number than generated

		// Loops through to check if any account number match and counts them, will exit loop if any numbers match

		for(int i = 0; i < numAccounts; i++)
		{
			if(randNum != accounts->AcctNumber)
			{
				numAccountsDifferent++;
			}
			else
			{
				i = numAccounts;
			}
		}

		// Exit check to see if random number is different than all accounts numbers

		if(numAccountsDifferent == numAccounts)
		{
			exit = true;
		}
		*/
		cycles++;												// Ensures that the seed will get randomized again while looping
		exit = true;

	}while(!exit);

	return randNum;
}
