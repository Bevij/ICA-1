#include "header.h"

void createMenu()
{
	char choice;
	char accountChar;
	string name;
	string account;
	double balance;
	double   intRate;
	double   minBalance;
	int		maturityMon;
	int numChecksWritten;

   bool leaving = false;

	do
	{
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

		getchar(choice);
		switch(choice)
		{

			case '1': // Service Charge Checking
			{
				account = randomNum(); // Checks installed
				ofstream fileouty(account);// fileout is cout, but to file

				accountChar = 'y';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           Service Charge Checking           |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				getposdouble(balance);
				numChecksWritten = 0; // it's a new account, after all

				fileouty << accountChar << endl;
				fileouty << name << endl;
				fileouty << balance << endl;
				fileouty << numChecksWritten;
				break;
			}


			case '2': //No Service Charge Checking
			{
				account = randomNum(); // Checks installed
				ofstream fileoutn(account);// fileout is cout, but to file

			   accountChar = 'n';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "         No Service Charge Checking          |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
				getposdouble(minBalance);

				fileoutn << accountChar << endl;
				fileoutn << name << endl;
				fileoutn << balance << endl;
				fileoutn << intRate<<endl;
				fileoutn << minBalance<<endl;
				break;

			}
			case '3': //High Interest Checking
			{
				account = randomNum(); // Checks installed
				ofstream fileoutC(account);// fileout is cout, but to file

				accountChar = 'C';

				cout << "\033c";
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           High Interest Checking            |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          :  "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        :  "<<endl;
				getposdouble(minBalance);

				fileoutC << accountChar << endl;
				fileoutC << name << endl;
				fileoutC << balance << endl;
				break;

			}
			case '4': //Certificate of Deposit
			{
				account = randomNum(); // Checks installed
				ofstream fileoutd(account);// fileout is cout, but to file

				accountChar = 'd';

				cout << "\033c";
				cout << setw(15) << " " << "_______________________________________________" << endl;
				cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
				cout << setw(16) << "|" << "           Certificate Of Deposit            |" << endl;
				cout << setw(15) << " " << "|_____________________________________________|" << endl;
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Maturity Months        : "<<endl;
				getposint(maturityMon);

				fileoutd << accountChar << endl;
				fileoutd << name << endl;
				fileoutd << balance << endl;
				fileoutd << intRate<<endl;
				fileoutd << maturityMon<<endl;
				break;

			}
			case '5'://Savings Account
			{
				account = randomNum(); // Checks installed
				ofstream fileouts(account);// fileout is cout, but to file

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
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          :  " << endl;
				getposdouble(intRate);

				fileouts << accountChar << endl;
				fileouts << name << endl;
				fileouts << balance << endl;
				fileouts << intRate<<endl;
				break;

			}
			case '6'://high Interest Savings
			{
				account = randomNum(); // Checks installed
				ofstream fileoutS(account);// fileout is cout, but to file

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
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
				getposdouble(minBalance);

				fileoutS << accountChar << endl;
				fileoutS << name << endl;
				fileoutS << balance << endl;
				fileoutS << intRate<<endl;
				fileoutS << minBalance<<endl;
				break;

			}
			case '0':
			{
				cout << "Exit" << endl;
				leaving = true;
			}
			break;
			default:
			{
				cout << endl << endl << setw(15) << " " << "option not available please select a valid option";
				cout << endl << endl << setw(15) << " " << "Press enter to countinue : ";
				cin.ignore();
				cin.ignore();
			}
		}
	}while(!leaving);

   return;
}
