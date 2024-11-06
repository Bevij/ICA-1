#include "header.h"

void createMenu() {

	char choice;
	char accountChar;
	string lastName = user.lastName;
	string firstName = user.firstName;
	string username = user.username;
	string account;
	double balance;
	double intRate;
	double minBalance;
	int tempNum;
	int maturityMon;
	int numChecksWritten;
	int exitChoice;

	bool randomNumUsed = false;
   bool leaving = false;

	do {
		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << setw(30) << "Create  Account" << setw(18) << "║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : ";

		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << left << "Client" << right << "│" << endl;
				break;
			}
			case 2:
			{
				cout << setw(25) << left << "Clerk" << right << "│" << endl;
				break;
			}
			case 3:
			{
				cout << setw(25) << left << "Manager" << right << "│" << endl;
				break;
			}
			case 4:
			{
				cout << setw(25) << left << "Admin" << right << "│" << endl;
				break;
			}
			default:
			{
				cout << setw(25) << left << "ERROR" << right << "│" << endl;
				break;
			}
		}		// End Switch

		cout << setw(15) << " " << "├─────────────────────────────────────────────┤" << endl;
		cout << setw(15) << " " << "│         Select The Account To Create        │" << endl;
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
		cout << setw(15) << " " << "Selection : ";

		getchar(choice);

		switch(choice) {

			case '1': // Service Charge Checking
			{
				accountChar = 'y';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "           Service Charge Checking           ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role output

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					numChecksWritten = 0; // it's a new account, after all

					ofstream fileouty(newAcctPath); // fileout is cout, but to file
					fileouty << accountChar << endl;
					fileouty << account << endl;
					fileouty << lastName << endl;
					fileouty << firstName << endl;
					fileouty << balance << endl;
					fileouty << numChecksWritten << endl;
				}

				cout << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made

				break;

			} // End case 1
			case '2': //No Service Charge Checking
			{
			   accountChar = 'n';

				cout << "\033c" << endl << endl;
				cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
				cout << setw(18) << "║" << setw(48) << "║" << endl;
				cout << setw(18) << "║" << "         No Service Charge Checking          ║" << endl;
				cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role selection

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
					getposdouble(intRate);
					cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
					getposdouble(minBalance);

					ofstream fileoutn(newAcctPath); // fileout is cout, but to file
					fileoutn << accountChar << endl;
					fileoutn << account << endl;
					fileoutn << lastName << endl;
					fileoutn << firstName << endl;
					fileoutn << balance << endl;
					fileoutn << intRate <<endl;
					fileoutn << minBalance <<endl;
				}

				cout << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made

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
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role selection

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
					getposdouble(intRate);
					cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
					getposdouble(minBalance);

					ofstream fileoutC(newAcctPath); // fileout is cout, but to file
					fileoutC << accountChar << endl;
					fileoutC << account << endl;
					fileoutC << lastName << endl;
					fileoutC << firstName << endl;
					fileoutC << balance << endl;
					fileoutC << intRate <<endl;
					fileoutC << minBalance <<endl;
				}

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made

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
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role selection

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
					getposdouble(intRate);
					cout << endl << endl << setw(15) << " " << "Maturity Months                 :  ";
					getposint(maturityMon);

					ofstream fileoutd(newAcctPath); // fileout is cout, but to file
					fileoutd << accountChar << endl;
					fileoutd << account << endl;
					fileoutd << lastName << endl;
					fileoutd << firstName << endl;
					fileoutd << balance << endl;
					fileoutd << intRate <<endl;
					fileoutd << maturityMon <<endl;
				}

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made

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
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role selection

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
					getposdouble(intRate);

					ofstream fileouts(newAcctPath); // fileout is cout, but to file
					fileouts << accountChar << endl;
					fileouts << account << endl;
					fileouts << lastName << endl;
					fileouts << firstName << endl;
					fileouts << balance << endl;
					fileouts << intRate <<endl;
				}

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made

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
				cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
				cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << right << endl;
				cout << setw(15) << " " << "│     Role         : ";

				// Switch for role selection

				switch(user.role)
				{
					case 1:
					{
						cout << setw(25) << left << "Client" << right << "│" << endl;
						break;
					}
					case 2:
					{
						cout << setw(25) << left << "Clerk" << right << "│" << endl;
						break;
					}
					case 3:
					{
						cout << setw(25) << left << "Manager" << right << "│" << endl;
						break;
					}
					case 4:
					{
						cout << setw(25) << left << "Admin" << right << "│" << endl;
						break;
					}
					default:
					{
						cout << setw(25) << left << "ERROR" << right << "│" << endl;
						break;
					}
				}		// End Switch
				cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl;

				cout << setw(15) << " " << "       Enter a 5 Digit Number" << endl;
				cout << setw(15) << " " << "Or Enter 0 For a Random Number  : ";

				getposint(tempNum);

				if(tempNum == 0)
				{
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else if(tempNum > 99999)
				{
					cout << endl << endl << setw(15) << " " << "Error Invalid Input. Generating A Random Number..." << endl;
					account = randomNum(); // Checks installed
					randomNumUsed = true;
				}
				else
				{
					account = to_string(tempNum);
				}

				// Account file creation
				fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
				if (fs::exists(newAcctPath)) {
					cout << "Account already exists!" << endl << "1. Generate a random account number" << endl << "0. Exit the program" << endl << endl;
					getposint(exitChoice);
					switch (exitChoice) {
						case 1:
							account = randomNum();
							randomNumUsed = true;
							break;
						case 0:
							cout << "Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
						default:
							cout << "Invalid choice. Exiting..." << endl;
							waitforenter();
							leaving = true;
							break;
					}
					break;
				} else if (!fs::exists(newAcctPath)) {
					if (user.role != 1) {
						cout << endl << endl << setw(15) << " " << "Last name of Account Holder          :  ";
						getline(cin, lastName);
						cout << endl << endl << setw(15) << " " << "First name of Account Holder          :  ";
						getline(cin, firstName);
						cout << endl << endl << setw(15) << " " << "Username of Account Holder          :  ";
						getline(cin, username);
					}
					fs::path newAcctPath = "./Data/Accounts/" + lastName + "/" + firstName + "/" + username + "/" + account;
					fs::create_directories(newAcctPath.parent_path());

					cout << endl << endl << setw(15) << " " << "Initial Deposit                 :  ";
					getposdouble(balance);
					cout << endl << endl << setw(15) << " " << "Interest Rate                   :  ";
					getposdouble(intRate);
					cout << endl << endl << setw(15) << " " << "Minimum Balance                 :  ";
					getposdouble(minBalance);

					ofstream fileoutS(newAcctPath); // fileout is cout, but to file
					fileoutS << accountChar << endl;
					fileoutS << account << endl;
					fileoutS << lastName << endl;
					fileoutS << firstName << endl;
					fileoutS << balance << endl;
					fileoutS << intRate << endl;
					fileoutS << minBalance << endl;
				}

				cout << endl << endl;
				cout << setw(15) << " " << "Bank Account Successfully Created!" << endl;

				// Only Tells you your bank account number if you randomly generated it, if you created it you should be able to remember / write it down already
				if(randomNumUsed)
				{
					cout << setw(15) << " " << "Your Bank Account Number is     : " << account << endl << endl;
				}
				cout << setw(15) << " " << "Press Enter to Continue         : ";
				waitforenter();

				encrypt(account);				// Account Encyption after file is made
				break;
			}
			case '0':
			{
				cout << "Exit" << endl;
				leaving = true;
				break;
			}
			default:
			{
				cout << endl << endl << setw(15) << " " << "option not available please select a valid option";
				cout << endl << endl << setw(15) << " " << "Press enter to countinue : ";
				waitforenter();
				break;
			}
		} // End account type choice switch

	} while(!leaving);

   return;
}
