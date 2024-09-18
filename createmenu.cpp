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

   bool leaving = false;

	do
	{
		choice = ' ';
		accountNum = randomNum(); // no checks yet...
		account = to_string(accountNum);
		ofstream fileout(account);// fileout is cout, but to file
		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(22) << "Create Account" << setw(24) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(15) << " " << "|  Select the Account you would like to make  |" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << "     1.Service Charge Checking Account       |" << endl;
		cout << setw(16) << "|" << "     2.No Service Charge Checking            |" << endl;
		cout << setw(16) << "|" << "     3.High Interest Checking                |" << endl;
		cout << setw(16) << "|" << "     4.Certificate of Deposit                |" << endl;
		cout << setw(16) << "|" << "     5.Savings Account                       |" << endl;
		cout << setw(16) << "|" << "     6.High Interest Savings                 |" << endl;
		cout << setw(16) << "|" << "     0.Exit                                  |" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;
		cout << setw(15) << " " << "Selection : " << endl;

		cin >> choice;
		switch(choice)
		{
			case '1': // Service Charge Checking
			{
				accountChar = 'y';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           Service Charge Checking           |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
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

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "         No Service Charge Checking          |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				cin >> balance;
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				cin>>intRate;
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
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
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           High Interest Checking            |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				cin >> balance;
				cout << endl << setw(15) << " " << "Interest Rate          :  "<<endl;
				cin>>intRate;
				cout << endl << setw(15) << " " << "Minimum Balance        :  "<<endl;
				cin>>minBalance;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				break;
		case '4': //Certificate of Deposit
				accountChar = 'd';

				cout << "\033c";
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           Certificate Of Deposit            |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				cin >> balance;
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				cin>>intRate;
				cout << endl << setw(15) << " " << "Maturity Months        : "<<endl;
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
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "              Savings  Account               |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				cin >> balance;
				cout << endl << setw(15) << " " << "Interest Rate          :  "<<endl;
				cin>>intRate;
				fileout << accountChar << endl;
				fileout << name << endl;
				fileout << balance << endl;
				fileout << intRate<<endl;
				break;
		case '6'://high Interest Savings
				accountChar = 'S';

				cout << "\033c";
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "            High Interest Savings            |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				cin.ignore();
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				cin >> balance;
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				cin>>intRate;
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
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
				cout << endl << endl << setw(15) << " " << "option not available please select a valid option";
				cout << endl << endl << setw(15) << " " << "Press enter to countinue : ";
				cin.ignore();
				cin.ignore();
		}
	}while(!leaving);

   return;
}
