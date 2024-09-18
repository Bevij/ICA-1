#include "header.h"

// all class functions
// called by editmenu.cpp
// each class has its own edit menu, and will return to editmenu.cpp
// once user has finished inputting everything





// SERVICE CHARGE CHECKING

void serviceChargeCheckingType::editMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(16) << "SERVICE CHARGE CHECKING ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Max # of Checks: " << MAXIMUM_NUM_OF_CHECKS << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Service Charge Check: " << serviceChargeCheck << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Service Charge Amount: " << serviceChargeAmount << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Num Checks    : " << setw(20) << left << numberOfChecksWritten << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new number of checks: ";
				cin >> numberOfChecksWritten;
				break;
		}
	}
	return;
}





// NO SERVICE CHARGE CHECKING

void noServiceChargeCheckingType::editMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(16) << "NO SERVICE CHARGE CHECKING ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Minimum Bal   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				cin >> interestRate;
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new minimum balance: ";
				cin >> minimumBalance;
				break;
		}
	}
	return;
}




// HIGH INTEREST CHECKING

void highInterestCheckingType::editMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(16) << "HIGH INTEREST CHECKING ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Minimum Bal   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				cin >> interestRate;
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new minimum balance: ";
				cin >> minimumBalance;
				break;
		}
	}
	return;
}


































// CERTIFICATE OF DEPOSIT

void certificateOfDepositType::editMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(16) << "NO SERVICE CHARGE CHECKING ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Certificate of Deposit Months: " << NUMBER_OF_MATURITY_MONTHS << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Maturity Months : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				cin >> interestRate;
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new minimum balance: ";
				cin >> minimumBalance;
				break;
		}
	}
	return;
}




















// SAVINGS

void savingsAccountType::editMenu()
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(31) << "SAVINGS ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(40) << "Enter new interest rate: ";
				cin >> interestRate;
				break;
		}
	}
	return;
}







// HIGH INTEREST SAVINGS

void highInverestSavingsType::editMenu()
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(31) << "HIGH INTEREST SAVINGS ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " "                    << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "4.  Min Balance   : " << setw(20) << left << minimumBalance << "|" << endl << right;
		cout << setw(16) << "|" << setw(22) << "0.  SAVE AND EXIT"    << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(40) << "Enter new interest rate: ";
				cin >> interestRate;
				break;
			case '4':
				cout << endl << endl << setw(40) << "Enter new minimumBalance: ";
				cin >> minimumBalance;
				break;
		}
	}
	return;
}

