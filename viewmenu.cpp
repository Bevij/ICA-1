#include "header.h"


void viewMenu()
{
	string tempstring;


	string filename;

	char acctType;


		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(28) << "View Menu" << setw(18) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
		getline(cin, filename);


		ifstream filein(filename); // filein is now cin >> (stuff from filename)

		if(!filein)
		{
			cout << endl << endl << endl << endl << setw(15) << " " << "Error, account does not exist";
			cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
			waitforenter();
		}
		else
		{
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
					cout << endl << endl << endl << endl << setw(15) << " " << "File structure invalid";
					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
					waitforenter();
					break;
			}

		}


	return;
}

