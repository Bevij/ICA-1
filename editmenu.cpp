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
				case 's':
				{
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
				}
				/*case 'c':
				{
					checkingAccountType temp(filename);
					temp.editMenu();
					fileout << "c\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'S':
				{
					highInterestSavingsType temp(filename);
					temp.editMenu();
					fileout << "S\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getInterestRate();
					fileout << temp.getMinimumBalance();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'C':
				{
					highInterestCheckingType temp(filename);
					temp.editMenu();
					fileout << "C\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getMinimumBalance();
					fileout << temp.getInterestRate();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'n':
				{
					noServiceChargeCheckingType temp(filename);
					temp.editMenu();
					fileout << "n\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getMinimumBalance();
					fileout << temp.getInterestRate();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'y':
				{
					serviceChargeCheckingType temp(filename);
					temp.editMenu();
					fileout << "n\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getServiceChargeAcount();
					fileout << temp.getServiceChargeChecks();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}
				case 'd':
				{
					certificateOfDepositType temp(filename);
					temp.editMenu();
					fileout << "d\n";
					fileout << temp.getAccountNumber() << endl;
					fileout << temp.getName() << endl;
					fileout << temp.getBalance() << endl;
					fileout << temp.getInterestRate();
					fileout << temp.getMaturityMonths();
					fs::remove(filename);
					fs::rename(tempfilename, filename);
					break;
				}*/
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

