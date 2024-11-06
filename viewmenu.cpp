#include "header.h"



void viewMenu()
{
//	string tempstring;

	string filename;
	string tempfilename;
	int filetime;
	time_t t;

	char acctType;


	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
	cout << setw(18) << "║" << setw(27) << "View Menu" << setw(21) << "║" << endl;
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

	cout << setw(15) << " " << right << "└─────────────────────────────────────────────┘" << endl;

	/*cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
	getline(cin, filename);*/

	listAccounts();


	try
	{

		ifstream fileintemp(filename); // filein is now cin >> (stuff from filename)

		if(!fileintemp)
			throw cantFind();
		fileintemp.close();

		decrypt(filename);
		ifstream filein(filename);
		encrypt(filename);

		tempfilename = filename + ".temp";
		if(fs::exists(tempfilename))
		{
			ifstream fileintemp(tempfilename);
			t = time(NULL);

			fileintemp >> filetime;

			int timesince = t - filetime;
			cout << "\nFile has been opened and edited without save.";
			cout << "\nFile opened " << timeString(t - filetime) << " ago.";
			cout << "\nView old version? (y/n): ";
			char yn;
			getyn(yn);
			if(yn == 'n')
				throw abortView();
		}// fi tempfilename deadlock check

		filein >> acctType; // first line will be string showing what account it is

		switch(acctType)
		{
			case 'y':
			{
				serviceChargeCheckingType service(filename);
				service.viewMenu();
				break;
			}
			case 'n':
			{
				noServiceChargeCheckingType noService(filename);
				noService.viewMenu();
				break;
			}
			case 'C':
			{
				highInterestCheckingType highChecking(filename);
				highChecking.viewMenu();
				break;
			}
			case 'd':
			{
				certificateOfDepositType deposit(filename);
				deposit.viewMenu();
				break;
			}
			case 's':
			{
				savingsAccountType savings(filename); // constructor with one string brings data in from file
				savings.viewMenu();
				break;
			}
			case 'S':
			{
				highInterestSavingsType highSavings(filename);
				highSavings.viewMenu();
				break;
			}
			default:
			{
				throw(fileStructureInvalid());
			}
		}// end switch

		misc.bankAccount = filename;
		log('v'); // log VIEW

	}//end try
	catch(cantFind e) // cant find file, file DNE
	{
		cout << "\nError: account '" << filename << "' does not exist!";
		cout << "\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(abortView e)
	{
		cout << "\nView aborted.";
		cout << "\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(fileStructureInvalid e)
	{
		cout << "\nFile structure invalid.";
		cout << "\nPress enter to return to main menu...";
		waitforenter();
	}


	return;
}

