#include "header.h"



int randomNum(){

	int randNum = 0;
	time_t seconds = time(NULL);					// Seed for random numbers, can be used to determine time out in lock function
	bool exit = false;
	//int numAccountsDifferent;

	srand((unsigned) seconds);						// Setting the random number seed

	do{
		randNum = (10000 + rand() % 90000);		// Sets range for random number from 10000 - 99999
															// Starts at 10000 in order for the number to always be 5 digits

		// Waiting for database, but will just return a random 5 digit number for now
		/*
		numAccountsDifferent = 0;					// Checks to see if all the accounts have a different number than generated

		// loops through to check if any account number match and counts them, will exit if any do

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

		// final check to see if all the accounts are different

		if(numAccountsDifferent == numAccounts)
		{
			exit = true;
		}
		*/
		exit = true;
	}while(!exit);

	return randNum;
}
