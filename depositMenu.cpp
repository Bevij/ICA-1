#include "header.h"



void depositMenu()
{

	string filename;
	double amount;
	double balance;
	char choice = ' ';
	char acctType;
	int filetime;
	time_t t;

	// This is the deposit function, this will promt the client to choose what account to deposit in and the amount
	// In order for Managers, Clients, and Admins to do this they will use Edit menu unless you think they should use this menu

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(18) << "║" << setw(26) << "Deposit Menu" << setw(17) << "║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
	cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
	cout << setw(15) << " " << "│     User Role    : ";

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

	cout << setw(15) << " " << "├─────────────────────────────────────────────┤" << endl;

	cout << setw(18) << "│" << setw(16) << "1.  Deposit" << setw(27) << "│" << endl;
	cout << setw(18) << "│" << setw(13) << "0.  Exit" << setw(30) << "│" << endl;
	cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl << endl;
	cout << setw(15) << " " << "Selection : "; // will show listing of accounts later!

	bool invalid = true;
	do { // input validity for 0 or 1, eventually for all possible accounts
		getchar(choice);
		invalid = (!(choice == '1' || choice == '0'));
		if(invalid)
		{
			cout << setw(15) << " " << "Invlalid choice! (1 or 0): ";
		}
	}while(invalid);

	switch(choice)
	{
		case '1':

			cout << "\033c" << endl << endl;

			cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
			cout << setw(18) << "║" << setw(43) << "║" << endl;
			cout << setw(18) << "║" << setw(26) << "Deposit Menu" << setw(17) << "║" << endl;
			cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
			cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
			cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
			cout << setw(15) << " " << "│     User Role    : ";

			// Switch for role selection

			switch(user.role)
			{
				case 1:
				{
					cout << setw(25) << "Client" << "│" << endl;
				}
				case 2:
				{
					cout << setw(25) << "Clerk" << "│" << endl;
				}
				case 3:
				{
					cout << setw(25) << "Manager" << "│" << endl;
				}
				case 4:
				{
					cout << setw(25) << "Admin" << "│" << endl;
				}
				default:
				{
					cout << setw(25) << "ERROR" << "│" << endl;
				}
			}		// End Switch

			cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl << endl;


			cout << setw(15) << " " << "Enter the account number to Deposit to : ";
			getline(cin, filename);

			try
			{
				ifstream fileintemp(filename);
				if(!fileintemp)
				{
					throw cantFind();
				}
				fileintemp.close();

				decrypt(filename);
				ifstream filein(filename);
				encrypt(filename);

				string tempfilename = filename + ".temp";
				if(fs::exists(tempfilename))
				{
					ifstream fileintemp(tempfilename);
					t = time(NULL);

					fileintemp >> filetime;

					if(t >= filetime + OVERRIDE_TIME)
					{
						cout << "\nFile has been opened and edited without save. \nWARNING: Override may cause unwanted discards to changes made on file!\nOverride? : ";
						char yn;
						getyn(yn);
						if(yn = 'n')
							throw abortOverride();
					}
					else
						throw deadlock();
				}// fi temptfilename deadlock check

				lock(filename);

				cout << endl << endl << endl;
				cout << setw(15) << " " << "Enter the amount of money to Deposit   : ";
				getposdouble(amount);

				filein >> acctType;

				balance = deposit(acctType, filename, amount);

				cout << endl << endl;
				cout << setw(15) << " " << "Succsess! Your Balance is now " << balance << "!" << endl << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				encrypt(filename);

				misc.bankAccount = filename;
				misc.amount = amount;
				log('d'); // logs DEPOSIT


			}			// End Try Block
			catch(cantFind)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error: Account '" << filename << "' does not exist" << endl;
				cout << setw(15) << " " <<  "Press Enter to continue : ";
				waitforenter();
			}
			catch(invalidAmount)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error: " << amount << "$ is not a valid amount to deposit" << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}
			catch(fileStructureInvalid)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "File Structure Invalid." << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}

			break;

		case '0':
			break;
	}		// End Switch
	return;
}
