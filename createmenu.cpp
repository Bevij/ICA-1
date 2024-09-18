#include "header.h"

void createMenu()
{
	char choice;
	char accountChar;
	string name;
	int accountNum;
	string account;
	double balance;
	int numChecksWritten;

   bool leaving = false;

	while(!leaving)
	{

		accountNum = randomNum(); // no checks yet...
		account = to_string(accountNum);
		ofstream fileout(account);// fileout is cout, but to file

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

		cin.get(choice);
		cin.ignore(1000, '\n');
		switch(choice)
		{
			case '1': // Service Charge Checking
			{
				accountChar = 'y';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;
				numChecksWritten = 0; // it's a new account, after all

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << numChecksWritten;
				break;
			}
			case '2': //No Service Charge Checking
			{
			    accountChar = 'n';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
			}
			case '3': //High Interest Checking
			{
				accountChar = 'C';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
			}
			case '4': //Certificate of Deposit
			{
				accountChar = 'd';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
			}
			case '5'://Savings Account
			{
				accountChar = 's';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
			}
			case '6'://high Interest Savings
			{
				accountChar = 'S';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
			}
			case '0':
			{
				cout << "Exit" << endl;
				leaving = true;
			}
			break;
		}
	}

   return;
}
