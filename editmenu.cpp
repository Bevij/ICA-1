#include "header.h"


void editMenu()
{
	string tempstring;

	string acctNum;
	string filename; // eventually filename will be acctNum + lastName
	string tempfilename;

	char acctType;


		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(28) << "Edit Menu" << setw(18) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << endl << endl << endl << endl << setw(15) << " " << "Enter account number: ";
		cin >> acctNum;
		filename = acctNum;


		ifstream filein(filename); // filein is now cin >> (stuff from filename)

		if(!filein)
		{
			cout << endl << endl << endl << endl << setw(15) << " " << "Error, account does not exist";
			cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
			cin.ignore();
			cin.ignore();
		}
		else
		{
			tempfilename = filename + ".temp";
			ofstream fileout(tempfilename); // fileout is cout << (to tempfilename file)
			// OUTPUT TIME TO FIRST LINE TO DO DEADLOCK!!!!!!!!!!!!!

			filein >> acctType; // first line will be string showing what account it is
			switch(acctType)
			{
				case 'y':
				{
					serviceChargeCheckingType service(filename);
					service.editMenu();
					fileout << "y\n";
					fileout << service.getAccountNumber() << endl;
					fileout << service.getName() << endl;
					fileout << service.getBalance() << endl;
					fileout << service.getNumberOfChecksWritten();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'n':
				{
					noServiceChargeCheckingType noService(filename);
					noService.editMenu();
					fileout << "n\n";
					fileout << noService.getAccountNumber() << endl;
					fileout << noService.getName() << endl;
					fileout << noService.getBalance() << endl;
					fileout << noService.getInterestRate() << endl;
					fileout << noService.getMinimumBalance();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				case 'C':
				{
					highInterestCheckingType highChecking(filename);
					highChecking.editMenu();
					fileout << "C\n";
					fileout << highChecking.getAccountNumber() << endl;
					fileout << highChecking.getName() << endl;
					fileout << highChecking.getBalance() << endl;
					fileout << highChecking.getInterestRate() << endl;
					fileout << highChecking.getMinimumBalance();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'd':
				{
					certificateOfDepositType deposit(filename);
					deposit.editMenu();
					fileout << "d\n";
					fileout << deposit.getAccountNumber() << endl;
					fileout << deposit.getName() << endl;
					fileout << deposit.getBalance() << endl;
					fileout << deposit.getInterestRate() << endl;
					fileout << deposit.getMaturityMonths();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 's':
				{
					savingsAccountType savings(filename); // constructor with one string brings data in from file
					savings.editMenu();
					fileout << "s\n";
					fileout << savings.getAccountNumber() << endl;
					fileout << savings.getName() << endl;
					fileout << savings.getBalance() << endl;
					fileout << savings.getInterestRate();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'S':
				{
					highInterestSavingsType highSavings(filename);
					highSavings.editMenu();
					fileout << "S\n";
					fileout << highSavings.getAccountNumber() << endl;
					fileout << highSavings.getName() << endl;
					fileout << highSavings.getBalance() << endl;
					fileout << highSavings.getInterestRate() << endl;
					fileout << highSavings.getMinimumBalance();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				default:
					cout << endl << endl << endl << endl << setw(15) << " " << "File structure invalid";
					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
					cin.ignore();
					cin.ignore();
					break;
			}


		}


	return;
}

