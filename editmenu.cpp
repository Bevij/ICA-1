#include "header.h"



class cantFind {};
class deadlock {};
class rejectedOverride {};

void editMenu()
{
	const int OVERRIDE_TIME = 4000; // the time required (in seconds) until a file.temp can be overridden by someone else
	time_t t;
	int filetime; // the time in a .temp file, checked for potential deadlock

	string tempstring;

	string filename; // eventually filename will be acctNum + lastName
	string tempfilename;

	char acctType;


	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "_______________________________________________" << endl;
	cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
	cout << setw(16) << "|" << setw(28) << "Edit Menu" << setw(18) << "|" << endl;
	cout << setw(15) << " " << "|_____________________________________________|" << endl;
	cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
	getline(cin, filename);


	ifstream filein(filename); // filein is now cin >> (stuff from file)
	try
	{

		if(!filein)
			throw cantFind();

		tempfilename = filename + ".temp";
		if(fs::exists(tempfilename))
		{
			ifstream fileintemp(tempfilename);
			t = time(NULL);

			fileintemp >> filetime;

			if(t >= filetime + OVERRIDE_TIME)
			{
				cout << "\nFile has been opened and edited without save. Override? (y/n): ";
				char yn;
				getyn(yn);
				if(yn == 'n')
					throw rejectedOverride();
/*				else
				{
					cout << "Overriding '" << filename << "' file editing\n";
					cout << "WARNING: May cause unwanted discards to changes made on file!\n";
					cout << "Press enter to continue...";
					waitforenter();
				}*/
			}
			else
				throw deadlock();
		}// fi tempfilename deadlock check


		ofstream fileouttemp(tempfilename); // both creates file.temp AND sets fileout to output to it
		time_t t = time(NULL);
		fileouttemp << t; // assigns time opened to file.temp
		fileouttemp.flush(); // tells it to actually, yknow, WRITE THE LINE AND SAVE IT


		filein >> acctType; // first line will be string showing what account it is

		switch(acctType)
		{
			case 'y':
			{
				serviceChargeCheckingType service(filename);
				service.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileouty(filename); // remakes file and outputs to it
				fileouty << "y\n";
				fileouty << service.getAccountNumber() << endl;
				fileouty << service.getName() << endl;
				fileouty << service.getBalance() << endl;
				fileouty << service.getNumberOfChecksWritten();
				break;
			}
			case 'n':
			{
				noServiceChargeCheckingType noService(filename);
				noService.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileoutn(filename); // remakes file and outputs to it
				fileoutn << "n\n";
				fileoutn << noService.getAccountNumber() << endl;
				fileoutn << noService.getName() << endl;
				fileoutn << noService.getBalance() << endl;
				fileoutn << noService.getInterestRate() << endl;
				fileoutn << noService.getMinimumBalance();
				break;
			}
			case 'C':
			{
				highInterestCheckingType highChecking(filename);
				highChecking.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileoutC(filename); // remakes file and outputs to it
				fileoutC << "C\n";
				fileoutC << highChecking.getAccountNumber() << endl;
				fileoutC << highChecking.getName() << endl;
				fileoutC << highChecking.getBalance() << endl;
				fileoutC << highChecking.getInterestRate() << endl;
				fileoutC << highChecking.getMinimumBalance();
				break;
			}
			case 'd':
			{
				certificateOfDepositType deposit(filename);
				deposit.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileoutd(filename); // remakes file and outputs to it
				fileoutd << "d\n";
				fileoutd << deposit.getAccountNumber() << endl;
				fileoutd << deposit.getName() << endl;
				fileoutd << deposit.getBalance() << endl;
				fileoutd << deposit.getInterestRate() << endl;
				fileoutd << deposit.getMaturityMonths();
				break;
			}
			case 's':
			{
				savingsAccountType savings(filename); // constructor with one string brings data in from file
				savings.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileouts(filename); // remakes file and outputs to it
				fileouts << "s\n";
				fileouts << savings.getAccountNumber() << endl;
				fileouts << savings.getName() << endl;
				fileouts << savings.getBalance() << endl;
				fileouts << savings.getInterestRate();
				break;
			}
			case 'S':
			{
				highInterestSavingsType highSavings(filename);
				highSavings.editMenu();
				fs::remove(tempfilename);
				fs::remove(filename); //removes file
				ofstream fileoutS(filename); // remakes file and outputs to it
				fileoutS << "S\n";
				fileoutS << highSavings.getAccountNumber() << endl;
				fileoutS << highSavings.getName() << endl;
				fileoutS << highSavings.getBalance() << endl;
				fileoutS << highSavings.getInterestRate() << endl;
				fileoutS << highSavings.getMinimumBalance();
				break;
			}
			default:
			{
				cout << "File structure invalid, press enter to continue...";
				waitforenter();
				break;
			}
		}//switch end

	}//try end
	catch(cantFind e) // cant find file, file DNE
	{
		cout << "\nError: accout '" << filename << "' does not exist!\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(deadlock e) // file.temp exists, not editable yet
	{
		cout << "\nAccess denied! '" << tempfilename << "' exists! Deadlock!!\n";
		cout << "Please wait " << timeString(filetime + OVERRIDE_TIME - t) << " before attempting override.\nPress enter to return to main menu...";
		waitforenter();
	}
	catch(rejectedOverride e) // file.temp exists, was editable, user chose NOT to edit file
	{
		cout << "\nOverride rejected.\nPress enter to return to main menu...";
		waitforenter();
	}


	return;
}

