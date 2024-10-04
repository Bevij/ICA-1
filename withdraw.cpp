#include "header.h"


class cantFind{};
class invalidAmount{};

void withdraw()
{

	string filename;
	double amount = 0;
	char choice = ' ';
	char acctType = ' ';
	bool invalid = true;

	// This is the Withdraw Function, this will only be seen by clients and will prompt them to enter a account they want to withdraw from and the amount
	// In order for Clerks, Managers, and Admins to do this they will use Edit Account unless you want them to use this

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(18) << "║" << setw(28) << "Withdraw  Menu" << setw(15) << "║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌────────────────────────────────────────┐" << endl;
	cout << setw(18) << "│" << setw(17) << "1.  Withdraw" << setw(26) << "│" << endl;
	cout << setw(18) << "│" << setw(13) << "0.  Exit" << setw(30) << "│" << endl;
	cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl;
	cout << setw(15) << " " << "Selection : ";

	// Input Validation for selection

	do {

		getchar(choice);

		invalid = (!(choice == '1' || choice == '0'));
		if(invalid)
		{
			cout << endl << endl << setw(15) << " " << "Invalid choice, Enter either 1 or 0 to continue : " << endl;
		}
	}while(invalid);

	switch(choice)
	{
		case '1':

			cout << "\033c" << endl << endl;

			cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
			cout << setw(18) << "║" << setw(43) << "║" << endl;
			cout << setw(18) << "║" << setw(28) << "Withdraw  Menu" << setw(15) << "║" << endl;
			cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl << endl;

			cout << setw(15) << " " << "Enter the account number you want to withdraw from : ";

			getline(cin, filename);

			try
			{
				ifstream filein(filename);
				if(!filein)
				{
					throw cantFind();
				}

				cout << endl << endl << endl;
				cout << setw(15) << " " << "Enter the amount of money to withdraw              : ";
				getposdouble(amount);

				filein >> acctType;

				switch(acctType)
				{
					case 'y':
					{
						serviceChargeCheckingType service(filename);
						fs::remove(filename);

						service.withdraw(amount);

						ofstream fileouty(filename);
						fileouty << "y" << endl;
						fileouty << service.getAccountNumber() << endl;
						fileouty << service.getName() << endl;
						fileouty << service.getBalance() << endl;
						fileouty << service.getNumberOfChecksWritten() << endl;

						cout << endl << endl;

						cout << setw(15) << " " << "Sucsess! Your balance is now " << service.getBalance() << "$!" << endl << endl;
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

						cout << setw(15) << " " << "Sucsess! Your balance is now " << highChecking.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					case 'd':
					{
						certificateOfDepositType deposit(filename);
						fs::remove(filename);

						deposit.withdraw(amount);

						ofstream fileoutd(filename);
						fileoutd << "d" << endl;
						fileoutd << deposit.getAccountNumber() << endl;
						fileoutd << deposit.getName() << endl;
						fileoutd << deposit.getBalance() << endl;
						fileoutd << deposit.getInterestRate() << endl;
						fileoutd << deposit.getMaturityMonths() << endl;

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

						cout << setw(15) << " " << "Sucsess! Your balance is now " << highSavings.getBalance() << "$!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to continue : ";
						waitforenter();
						break;
					}
					default:
					{
						cout << endl << endl;
						cout << setw(15) << " " << "File Structure Invalid, Press Enter to Continue : ";
						waitforenter();
					}
				}		// End Nested Switch
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

			break;

		case '0':
			break;
	}		// End Switch

	return;
}
