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
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "     SERVICE CHARGE CHECKING ACCOUNT EDIT    ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(15) << " " << "├─────────────────────────────────────────────┤" << endl << right;
		cout << setw(18) << "│" << setw(28) << "Service Charge Check : " << left << setw(17) << serviceChargeCheck << "│" << endl << right;
		cout << setw(18) << "│" << setw(28) << "Service Charge Amount: " << left << setw(17) << serviceChargeAmount << "│" << endl << right;
		cout << setw(18) << "│" << setw(19) << " "                    << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(25) << "Max # of Checks   : " << MAXIMUM_NUM_OF_CHECKS << setw(22) << "│" << endl;
		cout << setw(18) << "│" << setw(25) << "1.  Name          : " << setw(20) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "3.  Num Checks    : " << setw(20) << left << numberOfChecksWritten << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new number of checks: ";
				getposint(numberOfChecksWritten);
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
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "   NO SERVICE CHARGE CHECKING ACCOUNT EDIT   ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(18) << "│" << setw(19) << right <<  " "                    << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(25) << "1.  Name          : " << setw(20) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "4.  Minimum Bal   : " << setw(20) << left << minimumBalance << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				getposdouble(interestRate);
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new minimum balance: ";
				getposdouble(minimumBalance);
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
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "     HIGH INTEREST CHECKING ACCOUNT EDIT     ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(18) << "│" << setw(19) << right <<  " "                    << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(27) << "1.  Name            : " << setw(18) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "2.  Balance         : " << setw(18) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "3.  Interest Rate   : " << setw(18) << left << interestRate << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "4.  Minimum Balance : " << setw(18) << left << minimumBalance << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				getposdouble(interestRate);
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new minimum balance: ";
				getposdouble(minimumBalance);
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
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "     CERTIFICATE OF DEPOSIT ACCOUNT EDIT     ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(18) << "│" << right << "     Certificate of Deposit Months: " << left << setw(9) << NUMBER_OF_MATURITY_MONTHS << "│" << endl << right;
		cout << setw(18) << "│" << setw(19) << " "                    << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(27) << "1.  Name            : " << setw(18) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "2.  Balance         : " << setw(18) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "3.  Interest Rate   : " << setw(18) << left << interestRate << "│" << endl << right;
		cout << setw(18) << "│" << setw(27) << "3.  Maturity Months : " << setw(18) << left << maturityMonths << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(34) << "Enter new interest rate: ";
				getposdouble(interestRate);
				break;
			case '4':
				cout << endl << endl << setw(34) << "Enter new maturity months: ";
				getposint(maturityMonths);
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
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << setw(33) << "SAVINGS ACCOUNT EDIT" << setw(15) << "║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(18) << "│" << setw(19) << " "                    << right << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(25) << "1.  Name          : " << setw(20) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(40) << "Enter new interest rate: ";
				getposdouble(interestRate);
				break;
		}
	}
	return;
}

// HIGH INTEREST SAVINGS

void highInterestSavingsType::editMenu()
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "      HIGH INTEREST SAVINGS ACCOUNT EDIT     ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : " << left;

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(18) << "│" << right << setw(19) << " "                    << setw(29) << "│" << endl;
		cout << setw(18) << "│" << setw(12) << "Acct # " << accountNumber << setw(31) << "│" << endl;
		cout << setw(18) << "│" << setw(25) << "1.  Name          : " << setw(20) << left << name << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "4.  Min Balance   : " << setw(20) << left << minimumBalance << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE AND EXIT"    << setw(26) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		getchar(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				getline(cin, name);
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				getposdouble(balance);
				break;
			case '3':
				cout << endl << endl << setw(40) << "Enter new interest rate: ";
				getposdouble(interestRate);
				break;
			case '4':
				cout << endl << endl << setw(40) << "Enter new minimumBalance: ";
				getposdouble(minimumBalance);
				break;
		}
	}
	return;
}

