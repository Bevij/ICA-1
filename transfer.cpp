#include "header.h"



void transfer()
{
	// This is Transfer, this is only for clients unless changed and will transfer money between 2 accounts
	// This function will ask for 2 accounts, 1 to transfer from and 1 to transfer to, and an amount to transfer

	double amount = 0;
	double balance = 0;
	char choice = '1';
	char acctType = ' ';
	char acctType2 = ' ';
	bool invalid = true;
	int checkWritten = 0;
	string filename;
	string filename2;
	string num1;
	string num2;
	string temp;

	cout << "\033c" << endl << endl;

/*	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(18) << "║" << setw(28) << "Transfer  Menu" << setw(15) << "║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌────────────────────────────────────────┐" << endl;
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
	cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl;

	// Input Validation for selection*/


			cout << "\033c" << endl << endl;

			cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
			cout << setw(18) << "║" << setw(43) << "║" << endl;
			cout << setw(18) << "║" << setw(28) << "Transfer  Menu" << setw(15) << "║" << endl;
			cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
			cout << setw(15) << " " << "┌────────────────────────────────────────┐" << endl;
			cout << setw(15) << " " << "│     Logged in as : " << setw(20) << left << user.username.substr(0, 24)<< "│" << right << endl;
			cout << setw(15) << " " << "│     User Role    : " << left;

			// Switch for role selection

			switch(user.role)
			{
				case 1:
				{
					cout << setw(20) << "Client" << "│" << endl;
					break;
				}
				case 2:
				{
					cout << setw(20) << "Clerk" << "│" << endl;
					break;
				}
				case 3:
				{
					cout << setw(20) << "Manager" << "│" << endl;
					break;
				}
				case 4:
				{
					cout << setw(20) << "Admin" << "│" << endl;
					break;
				}
				default:
				{
					cout << setw(20) << "ERROR" << "│" << endl;
					break;
				}
			}		// End Switch

			cout << setw(15) << " " << right << "└────────────────────────────────────────┘" << endl << endl;

			cout << setw(15) << " " << "Enter The First Account Number To Transfer From : ";
			getline(cin, num1);
			cout << endl << endl;

			cout << setw(15) << " " << "Enter The Second Account Number To Transfer To  : ";
			getline(cin, num2);


			temp = searchbynum(num1);
			filename = temp.substr(0, temp.length());
			temp = searchbynum(num2);
			filename2 = temp.substr(0, temp.length());

			try
			{
				ifstream fileintemp(filename);
				if(!fileintemp)
				{
					throw cantFind();
				}
				fileintemp.close();

				ifstream fileintemp2(filename2);
				if(!fileintemp2)
				{
					throw cantFind();
				}
				fileintemp2.close();

				//decrypt(filename);
				ifstream filein(filename);
				//encrypt(filename);

				//decrypt(filename2);
				ifstream filein2(filename2);
				//encrypt(filename2);


				cout << endl << endl << endl;
				cout << setw(15) << " " << "Enter The Amount of Money to Transfer              : ";
				getposdouble(amount);


				filein >> acctType;
				filein2 >> acctType2;

				switch(acctType)
				{
					case 'y':
					{
						cout << endl << endl;
						serviceChargeCheckingType service(".");
						fs::remove(filename);

						checkWritten = service.writeCheck(amount);

						ofstream fileouty(filename);
						fileouty << "y" << endl;
						fileouty << service.getAccountNumber() << endl;
						fileouty << service.getName() << endl;
						fileouty << service.getBalance() << endl;
						fileouty << service.getNumberOfChecksWritten() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << service.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						waitforenter();
						break;
					}
					case 'n':
					{
						noServiceChargeCheckingType noService(filename);
						fs::remove(filename);

						noService.withdraw(amount);

						ofstream fileoutn(filename);
						fileoutn << "n" << endl;
						fileoutn << noService.getAccountNumber() << endl;
						fileoutn << noService.getName() << endl;
						fileoutn << noService.getBalance() << endl;
						fileoutn << noService.getInterestRate() << endl;
						fileoutn << noService.getMinimumBalance() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << noService.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					case 'C':
					{
						highInterestCheckingType highChecking(filename);
						fs::remove(filename);

						highChecking.withdraw(amount);

						ofstream fileoutC(filename);
						fileoutC << "C" << endl;
						fileoutC << highChecking.getAccountNumber() << endl;
						fileoutC << highChecking.getName() << endl;
						fileoutC << highChecking.getBalance() << endl;
						fileoutC << highChecking.getInterestRate() << endl;
						fileoutC << highChecking.getMinimumBalance() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << highChecking.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					case 'd':
					{
						certificateOfDepositType certificate(filename);
						fs::remove(filename);

						certificate.withdraw(amount);

						ofstream fileoutd(filename);
						fileoutd << "d" << endl;
						fileoutd << certificate.getAccountNumber() << endl;
						fileoutd << certificate.getName() << endl;
						fileoutd << certificate.getBalance() << endl;
						fileoutd << certificate.getInterestRate() << endl;
						fileoutd << certificate.getMaturityMonths() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << certificate.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();

						break;
					}
					case 's':
					{
						savingsAccountType savings(filename);
						fs::remove(filename);

						savings.withdraw(amount);

						ofstream fileouts(filename);
						fileouts << "s" << endl;
						fileouts << savings.getAccountNumber() << endl;
						fileouts << savings.getName() << endl;
						fileouts << savings.getBalance() << endl;
						fileouts << savings.getInterestRate() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << savings.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					case 'S':
					{
						highInterestSavingsType highSavings(filename);
						fs::remove(filename);

						highSavings.withdraw(amount);

						ofstream fileoutS(filename);
						fileoutS << "S" << endl;
						fileoutS << highSavings.getAccountNumber() << endl;
						fileoutS << highSavings.getName() << endl;
						fileoutS << highSavings.getBalance() << endl;
						fileoutS << highSavings.getInterestRate() << endl;
						fileoutS << highSavings.getMinimumBalance() << endl;

						cout << endl << endl;

						balance = deposit(acctType2, filename2, amount);

						cout << setw(15) << " " << "Sucsess! Your balance is now " << highSavings.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					default:
					{
						throw(fileStructureInvalid());
					}
				}		// End Nested Switch
				encrypt(filename);
				encrypt(filename2);

				misc.bankAccount = filename;
				misc.bankAccount2 = filename2;
				misc.amount = amount;
				log('t'); // logs WITHDRAWS


			}			// End Try Block
			catch(cantFind)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error : Account '" << filename << "' does not exist!" << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}
			catch(invalidAmount)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error " << amount << " is not a valid amount to withdraw" << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}
			catch(fileStructureInvalid)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "File structure invalid." << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}

	return;
}
