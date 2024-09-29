#include "header.h"

void createMenu()
{
	char choice;
	char accountChar;
	string name;
	string account;
	string tempNum;
	double balance;
	double   intRate;
	double   minBalance;
	int		maturityMon;
	int numChecksWritten;

   bool leaving = false;

	do
	{
		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << setw(30) << "Create  Account" << setw(18) << "║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│  Select the Account you would like to make  │" << endl;
		cout << setw(18) << "│" << setw(48) << "│" << endl;
		cout << setw(18) << "│" << setw(48) << "│" << endl;
		cout << setw(18) << "│" << "     1.Service Charge Checking Account       │" << endl;
		cout << setw(18) << "│" << "     2.No Service Charge Checking            │" << endl;
		cout << setw(18) << "│" << "     3.High Interest Checking                │" << endl;
		cout << setw(18) << "│" << "     4.Certificate of Deposit                │" << endl;
		cout << setw(18) << "│" << "     5.Savings Account                       │" << endl;
		cout << setw(18) << "│" << "     6.High Interest Savings                 │" << endl;
		cout << setw(18) << "│" << "     0.Exit                                  │" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;
		cout << setw(15) << " " << "Selection : " << endl;

		getchar(choice);
		switch(choice)
		{

			case '1': // Service Charge Checking
			{
				accountChar = 'y';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "           Service Charge Checking           ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder          : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit                 : "<<endl;
				getposdouble(balance);
				numChecksWritten = 0; // it's a new account, after all

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileouty(account);// fileout is cout, but to file

				fileouty << accountChar << endl;
				fileouty << account << endl;
				fileouty << name << endl;
				fileouty << balance << endl;
				fileouty << numChecksWritten << endl;

				break;

			}


			case '2': //No Service Charge Checking
			{
			   accountChar = 'n';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "         No Service Charge Checking          ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
				getposdouble(minBalance);

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileoutn(account);// fileout is cout, but to file

				fileoutn << accountChar << endl;
				fileoutn << tempNum << endl;
				fileoutn << name << endl;
				fileoutn << balance << endl;
				fileoutn << intRate<<endl;
				fileoutn << minBalance<<endl;
				break;

			}
			case '3': //High Interest Checking
			{
				accountChar = 'C';

				cout << "\033c";
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "           High Interest Checking            ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder : "<<endl;
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : "<<endl;
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          :  "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        :  "<<endl;
				getposdouble(minBalance);

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileoutC(account);// fileout is cout, but to file

				fileoutC << accountChar << endl;
				fileoutC << tempNum << endl;
				fileoutC << name << endl;
				fileoutC << balance << endl;
				fileoutC << intRate << endl;
				fileoutC << minBalance << endl;
				break;

			}
			case '4': //Certificate of Deposit
			{
				accountChar = 'd';

				cout << "\033c";
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "           Certificate Of Deposit            ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Maturity Months        : "<<endl;
				getposint(maturityMon);

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileoutd(account);// fileout is cout, but to file

				fileoutd << accountChar << endl;
				fileoutd << tempNum << endl;
				fileoutd << name << endl;
				fileoutd << balance << endl;
				fileoutd << intRate << endl;
				fileoutd << maturityMon << endl;
				break;

			}
			case '5'://Savings Account
			{
				accountChar = 's';

				cout << "\033c";
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "              Savings  Account               ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          :  " << endl;
				getposdouble(intRate);

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileouts(account);// fileout is cout, but to file

				fileouts << accountChar << endl;
				fileouts << tempNum << endl;
				fileouts << name << endl;
				fileouts << balance << endl;
				fileouts << intRate << endl;
				break;

			}
			case '6'://high Interest Savings
			{
				accountChar = 'S';

				cout << "\033c";
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "            High Interest Savings            ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << endl << setw(15) << " " << "       Enter a 5 digit number" << endl;
				cout << setw(15) << " " << "Or enter -1 for a random number : " << endl;
				getline(cin, tempNum);
				cout << endl << setw(15) << " " << "Name of Account Holder : ";
				getline(cin, name);
				cout << endl << setw(15) << " " << "Initial Deposit        : ";
				getposdouble(balance);
				cout << endl << setw(15) << " " << "Interest Rate          : "<<endl;
				getposdouble(intRate);
				cout << endl << setw(15) << " " << "Minimum Balance        : "<<endl;
				getposdouble(minBalance);

				if(tempNum == "-1")
				{
					account = randomNum(); // Checks installed
				}
				else
				{
					account = tempNum;
				}

				ofstream fileoutS(account);// fileout is cout, but to file

				fileoutS << accountChar << endl;
				fileoutS << tempNum << endl;
				fileoutS << name << endl;
				fileoutS << balance << endl;
				fileoutS << intRate << endl;
				fileoutS << minBalance << endl;
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
