#include "header.h"

void createMenu()
{
	char choice;
	char accountChar;
	string name;
	int accountNum;
	double balance;
	int numChecksWritten;

   bool leaving;

	while(!leaving)
	{
		cout << "\033c";
		cout << "\033[2J\033[1;1H" << endl;
		cout << "What Type of Account would you like to make?" << endl;
		cout << "1.Service Charge Checking Account" << endl;
		cout << "2.No Service Charge Checking" << endl;
		cout << "3.High Interest Checking" << endl;
		cout << "4.Certificate of Deposit" << endl;
		cout << "5.Savings Account" << endl;
		cout << "6.High Interest Savings" << endl;
		cout << "0.Exit" << endl;
		cout << "Please enter a choice" << endl;

		cin >> choice;
		switch(choice)
		{
			case '1': // Service Charge Checking
				accountChar = 'y';
				accountNum = randomNum(); // no checks yet...

				ofstream fileout(accountNum);// fileout is cout, but to file

				cout << "\033c";
				cout << "Name of Account Holder: "
				getline(cin, name);
				cout << "Initial Deposit: "
				cin >> balance;
				numChecksWritten = 0; // it's a new account, after all

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << numChecksWritten;
				break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '0':
				cout << "Exit" << endl;
				leaving = true;
			break;
			default:
				cout << "option not available please select a valid option" << endl;
				cin >> choice;
		}
	}

   return;
}
