#include "header.h"



void transfer()
{
	// This is Transfer, this is only for clients unless changed and will transfer money between 2 accounts
	// This function will ask for 2 accounts, 1 to transfer from and 1 to transfer to, and an amount to transfer

	string filename;
	string filename2;
	double amount = 0;
	double balance = 0;
	char choice = ' ';
	char acctType = ' ';
	char acctType2 = ' ';
	bool invalid = true;
	int checkWritten = 0;

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(18) << "║" << setw(28) << "Transfer  Menu" << setw(15) << "║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌────────────────────────────────────────┐" << endl;
	cout << setw(18) << "│" << setw(17) << "1.  Transfer" << setw(26) << "│" << endl;
	cout << setw(18) << "│" << setw(13) << "0.  Exit" << setw(30) << "│" << endl;
	cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl;
	cout << setw(15) << " " << "Selection : ";

	// Input Validation for selection

	do {

		getchar(choice);

		invalid = (!(choice == '1' || choice == '0'));
		if(invalid)
		{
			cout << endl << endl << setw(15) << " " << "Invalid Choice, Enter Either 1 or 0 to Continue : " << endl;
		}
	}while(invalid);

	switch(choice)
	{
		case '1':

			cout << "\033c" << endl << endl;

			cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
			cout << setw(18) << "║" << setw(43) << "║" << endl;
			cout << setw(18) << "║" << setw(28) << "Transfer  Menu" << setw(15) << "║" << endl;
			cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl << endl;

			cout << setw(15) << " " << "Enter The Account Number You Want to Transfer From : ";

			getline(cin, filename);

			cout << endl << endl;
			cout << setw(15) << " " << "Enter The Account Number You Want to Transfer to   : ";

			getline(cin, filename2);

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

				decrypt(filename);
				ifstream filein(filename);
				encrypt(filename);

				decrypt(filename2);
				ifstream filein2(filename2);
				encrypt(filename2);


				cout << endl << endl << endl;
				cout << setw(15) << " " << "Enter The Amount of Money to Transfer              : ";
				getposdouble(amount);


				filein >> acctType;
				filein2 >> acctType2;

				switch(acctType)
				{
					case 'y':
					{
						serviceChargeCheckingType service(filename);
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

						if(checkWritten == 0)
						{
							cout << setw(15) << " " << "Sucsess! Your balance is now " << service.getBalance() << "$!" << endl << endl;
						}
						cout << setw(15) << " " << "Press Enter to continue : ";
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

				misc.bankAccount = filename;
				misc.amount = amount;
				log('w'); // logs WITHDRAWS


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

			break;

		case '0':
			break;
	}		// End Switch

	return;
}
