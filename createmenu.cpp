#include "header.h"

void createMenu()
{
	char choice;
	char accountChar;
	string name;
	int accountNum;
	string account;
	double balance;
	double   intRate;
	double   minBalance;
	int		maturityMon;
	int numChecksWritten;

   bool leaving;

	while(!leaving)
	{

		accountNum = randomNum(); // no checks yet...
		account = accountNum;
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

		cin >> choice;
		switch(choice)
		{
			case '1': // Service Charge Checking
			{
				accountChar = 'y';

				cout << "\033c";
				cout << "Name of Account Holder: "<<endl;
				getline(cin, name);
				cout << "Initial Deposit: "<<endl;
				cin >> balance;
				numChecksWritten = 0; // it's a new account, after all

				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << numChecksWritten;
				break;
			}
		case '2': //No Service Charge Checking
			    accountChar = 'n';

				cout << "\033c";
				cout << "Name of Account Holder: "<<endl;
				getline(cin, name);
				cout << "Initial Deposit: "<<endl;
				cin >> balance;
				cout <<" Interest Rate:  "<<endl;
				cin>>intRate;
				cout<<"Minimum Balance:  "<<endl;
				cin>>minBalance;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout<< intRate<<endl;
				fileout<< minBalance<<endl;
				break;
		case '3': //High Interest Checking
				accountChar = 'C';

				cout << "\033c";
				cout << "Name of Account Holder: "<<endl;
				getline(cin, name);
				cout << "Initial Deposit: "<<endl;
				cin >> balance;
				cout <<" Interest Rate:  "<<endl;
				cin>>intRate;
				cout<<"Minimum Balance:  "<<endl;
				cin>>minBalance;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
		case '4': //Certificate of Deposit
				accountChar = 'd';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;
				cout <<" Interest Rate:  "<<endl;
				cin>>intRate;
				cout<<"Maturity Months:  "<<endl;
				cin>>maturityMon;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << intRate<<endl;
				fileout << maturityMon<<endl;
				break;
		case '5'://Savings Account
				accountChar = 's';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;
				cout <<" Interest Rate:  "<<endl;
				cin>>intRate;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << intRate<<endl;
				break;
		case '6'://high Interest Savings
				accountChar = 'S';

				cout << "\033c";
				cout << "Name of Account Holder: ";
				getline(cin, name);
				cout << "Initial Deposit: ";
				cin >> balance;
				cout <<" Interest Rate:  "<<endl;
				cin>>intRate;
				cout<<"Minimum Balance:  "<<endl;
				cin>>minBalance;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout<< intRate<<endl;
				fileout<< minBalance<<endl;
				break;
			case '0':
			{
				cout << "Exit" << endl;
				leaving = true;
			}
			break;
			default:
				cout << "option not available please select a valid option" << endl;
				cin >> choice;
		}
	}

   return;
}
