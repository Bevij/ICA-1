#include "header.h"

// all class functions
// called by editmenu.cpp
// each class has its own edit menu, and will return to editmenu.cpp
// once user has finished inputting everything





// SERVICE CHARGE CHECKING

void serviceChargeCheckingType::viewMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "     SERVICE CHARGE CHECKING ACCOUNT VIEW    |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(28) << "Service Charge Check : " << left << setw(17) << serviceChargeCheck << "|" << endl << right;
		cout << setw(16) << "|" << setw(28) << "Service Charge Amount: " << left << setw(17) << serviceChargeAmount << "|" << endl << right;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "Max # of Checks   : " << MAXIMUM_NUM_OF_CHECKS << setw(20) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Num Checks    : " << setw(20) << left << numberOfChecksWritten << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "'0' to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}





// NO SERVICE CHARGE CHECKING

void noServiceChargeCheckingType::viewMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "   NO SERVICE CHARGE CHECKING ACCOUNT VIEW   |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Minimum Bal   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "'0' to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}




// HIGH INTEREST CHECKING

void highInterestCheckingType::viewMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "     HIGH INTEREST CHECKING ACCOUNT VIEW     |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Minimum Bal   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "0 to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}


































// CERTIFICATE OF DEPOSIT

void certificateOfDepositType::viewMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "     CERTIFICATE OF DEPOSIT ACCOUNT VIEW     |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << "     Certificate of Deposit Months: " << left << setw(9) << NUMBER_OF_MATURITY_MONTHS << "|" << endl << right;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(27) << "1.  Name            : " << setw(18) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(27) << "2.  Balance         : " << setw(18) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(27) << "3.  Interest Rate   : " << setw(18) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(27) << "3.  Maturity Months : " << setw(18) << left << maturityMonths << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "0 to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}




















// SAVINGS

void savingsAccountType::viewMenu()
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(31) << "SAVINGS ACCOUNT VIEW" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "0 to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}







// HIGH INTEREST SAVINGS

void highInterestSavingsType::viewMenu()
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "      HIGH INTEREST SAVINGS ACCOUNT VIEW     |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Min Balance   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "0 to exit: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
		}
	}
	return;
}

