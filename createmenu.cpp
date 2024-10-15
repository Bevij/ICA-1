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
	int tempNum;
	int		maturityMon;
	int numChecksWritten;

	bool randomNumUsed = false;
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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				numChecksWritten = 0; // it's a new account, after all

				ofstream fileouty(account);// fileout is cout, but to file

				fileouty << accountChar << endl;
				fileouty << account << endl;
				fileouty << name << endl;
				fileouty << balance << endl;
				fileouty << numChecksWritten << endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number :  ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
				getposdouble(intRate);
				cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
				getposdouble(minBalance);

				ofstream fileoutn(account);// fileout is cout, but to file

				fileoutn << accountChar << endl;
				fileoutn << tempNum << endl;
				fileoutn << name << endl;
				fileoutn << balance << endl;
				fileoutn << intRate<<endl;
				fileoutn << minBalance<<endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     :  " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         :  ";
				waitforenter();

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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
				getposdouble(intRate);
				cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
				getposdouble(minBalance);

				ofstream fileoutC(account);// fileout is cout, but to file

				fileoutC << accountChar << endl;
				fileoutC << tempNum << endl;
				fileoutC << name << endl;
				fileoutC << balance << endl;
				fileoutC << intRate << endl;
				fileoutC << minBalance << endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     :  " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         :  ";
				waitforenter();

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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
				getposdouble(intRate);
				cout << endl << endl << setw(15) << " " << "Maturity Months                 :  ";
				getposint(maturityMon);

				ofstream fileoutd(account);// fileout is cout, but to file

				fileoutd << accountChar << endl;
				fileoutd << tempNum << endl;
				fileoutd << name << endl;
				fileoutd << balance << endl;
				fileoutd << intRate << endl;
				fileoutd << maturityMon << endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";

					cout << setw(15) << " " << "Your Bank Account Number is     :  " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         :  ";
				waitforenter();

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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
				getposdouble(intRate);

				ofstream fileouts(account);// fileout is cout, but to file

				fileouts << accountChar << endl;
				fileouts << tempNum << endl;
				fileouts << name << endl;
				fileouts << balance << endl;
				fileouts << intRate << endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

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
				cout << endl << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}
				cout << endl << endl << setw(15) << " " << "Name of Account Holder          :  ";
				getline(cin, name);
				cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
				getposdouble(balance);
				cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
				getposdouble(intRate);
				cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
				getposdouble(minBalance);

				ofstream fileoutS(account);// fileout is cout, but to file

				fileoutS << accountChar << endl;
				fileoutS << tempNum << endl;
				fileoutS << name << endl;
				fileoutS << balance << endl;
				fileoutS << intRate << endl;
				fileoutS << minBalance << endl;

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already

				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

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
