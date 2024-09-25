#include "header.h"

class cantFind {};
class abortView {};

void viewMenu()
{
//	string tempstring;

	string filename;
	string tempfilename;
	int filetime;
	time_t t;

	char acctType;


	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "_______________________________________________" << endl;
	cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
	cout << setw(16) << "|" << setw(28) << "View Menu" << setw(18) << "|" << endl;
	cout << setw(15) << " " << "|_____________________________________________|" << endl;
	cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
	getline(cin, filename);


	try
	{

		ifstream filein(filename); // filein is now cin >> (stuff from filename)

		if(!filein)
			throw cantFind();

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
				cout << "File structure invalid, press enter to continue...";
				waitforenter();
				break;
		}// end switch

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


	return;
}

