#include "header.h"


void editMenu()
{
	string tempstring;

	string acctNum;
	string filename; // eventually filename will be acctNum + lastName
	string tempfilename;

	char acctType;


		cout << "\033c" << endl;
		cout << "Enter account number: ";
		cin >> acctNum;
		filename = acctNum;


		ifstream filein(filename); // filein is now cin >> (stuff from filename)

		if(!filein)
		{
			cout << "Account does not exist, any key to continue...\n";
			cin  >> tempstring;
		}
		else
		{
			tempfilename = filename + ".temp";
			ofstream fileout(tempfilename); // fileout is cout << (to tempfilename file)
			// OUTPUT TIME TO FIRST LINE TO DO DEADLOCK!!!!!!!!!!!!!

			filein >> acctType; // first line will be string showing what account it is
			switch(acctType)
			{
				case 's': {
					savingsAccountType temp(filename); // constructor with one string brings data in from file
					temp.editMenu();
					fileout << "s\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getInterestRate();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}default:
					cout << "File structure invalid, any key to return to main menu...";
					cin >> tempstring;
					break;
			}


		}


	return;
}

