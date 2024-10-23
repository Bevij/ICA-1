#include "header.h"


void editMenu()
{
	time_t t;
	int filetime; // the time in a .temp file, checked for potential deadlock

//	string tempstring;

	string filename; // eventually filename will be acctNum + lastName
	string tempfilename;

	char acctType;


	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
	cout << setw(18) << "║" << setw(27) << "Edit Menu" << setw(21) << "║" << endl;
	cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
	cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << right << "│" << endl;
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

	cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl;
	cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
	getline(cin, filename);


	try
	{
		ifstream fileintest(filename); // filein is now cin >> (stuff from file)

		if(!fileintest)
			throw cantFind();
		fileintest.close();


		decrypt(filename);
		ifstream filein(filename); // store and makes readable the decrypted file for editmenu.cpp
		encrypt(filename);

		tempfilename = filename + ".temp";
		if(fs::exists(tempfilename))
		{
			ifstream fileintemp(tempfilename);
			t = time(NULL);

			fileintemp >> filetime;

			if(t >= filetime + OVERRIDE_TIME)
			{
				cout << "\nFile has been opened and edited without save.\nWARNING: Override may cause unwanted discards to changes made on fil1!\nOverride? (y/n): ";
				char yn;
				getyn(yn);
				if(yn == 'n')
					throw abortOverride();
			}
			else
				throw deadlock();
		}// fi tempfilename deadlock check


		lock(filename);

		filein >> acctType; // first line will be string showing what account it is

		switch(acctType)
		{
			case 'y':
			{
				serviceChargeCheckingType service(filename); // makes a temporary class to hold data, constructs from data in file
				service.editMenu(); // calls editMenu from class
				service.update(); // updates the file with new data
				break;
			}
			case 'n':
			{
				noServiceChargeCheckingType noService(filename);
				noService.editMenu();
				noService.update();
				break;
			}
			case 'C':
			{
				highInterestCheckingType highChecking(filename);
				highChecking.editMenu();
				highChecking.update();
				break;
			}
			case 'd':
			{
				certificateOfDepositType deposit(filename);
				deposit.editMenu();
				deposit.update();
				break;
			}
			case 's':
			{
				savingsAccountType savings(filename);
				savings.editMenu();
				savings.update();
				break;
			}
			case 'S':
			{
				highInterestSavingsType highSavings(filename);
				highSavings.editMenu();
				highSavings.update();
				break;
			}
			default:
			{
				throw(fileStructureInvalid());
			}
		}//switch end

		misc.bankAccount = filename;
		log('e'); // logs EDIT

	}//try end
	catch(cantFind e) // cant find file, file DNE
	{
		cout << "\nError: account '" << filename << "' does not exist!";
		cout << "\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(deadlock e) // file.temp exists, not editable yet
	{
		cout << "\nAccess denied! '" << tempfilename << "' exists! Deadlock!!";
		cout << "\nPlease wait " << timeString(filetime + OVERRIDE_TIME - t) << " before attempting override.";
		cout << "\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(abortOverride e) // file.temp exists, was editable, user chose NOT to edit file
	{
		cout << "\nOverride aborted.";
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

