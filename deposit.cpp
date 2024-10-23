#include "header.h"



void deposit()
{

	string filename;
	double amount;
	char choice = ' ';
	char acctType;
	int filetime;
	time_t t;

	// This is the deposit function, this will promt the client to choose what account to deposit in and the amount
	// In order for Managers, Clients, and Admins to do this they will use Edit menu unless you think they should use this menu

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(18) << "║" << setw(26) << "Deposit Menu" << setw(17) << "║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl;
	cout << setw(15) << " " << "┌────────────────────────────────────────┐" << endl;
	cout << setw(18) << "│" << setw(16) << "1.  Deposit" << setw(27) << "│" << endl;
	cout << setw(18) << "│" << setw(13) << "0.  Exit" << setw(30) << "│" << endl;
	cout << setw(15) << " " << "└────────────────────────────────────────┘" << endl << endl;
	cout << setw(15) << " " << "Selection : "; // will show listing of accounts later!

	bool invalid = true;
	do { // input validity for 0 or 1, eventually for all possible accounts
		getchar(choice);
		invalid = (!(choice == '1' || choice == '0'));
		if(invalid)
		{
			cout << setw(15) << " " << "Invlalid choice! (1 or 0): ";
		}
	}while(invalid);

	switch(choice)
	{
		case '1':

			cout << "\033c" << endl << endl;

			cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
			cout << setw(18) << "║" << setw(43) << "║" << endl;
			cout << setw(18) << "║" << setw(26) << "Deposit Menu" << setw(17) << "║" << endl;
			cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl << endl;

			cout << setw(15) << " " << "Enter the account number to Deposit to : ";
			getline(cin, filename);

			try
			{
				ifstream fileintemp(filename);
				if(!fileintemp)
				{
					throw cantFind();
				}
				fileintemp.close();

				decrypt(filename);
				ifstream filein(filename);
				encrypt(filename);

				string tempfilename = filename + ".temp";
				if(fs::exists(tempfilename))
				{
					ifstream fileintemp(tempfilename);
					t = time(NULL);

					fileintemp >> filetime;

					if(t >= filetime + OVERRIDE_TIME)
					{
						cout << "\nFile has been opened and edited without save. \nWARNING: Override may cause unwanted discards to changes made on file!\nOverride? : ";
						char yn;
						getyn(yn);
						if(yn = 'n')
							throw abortOverride();
					}
					else
						throw deadlock();
				}// fi temptfilename deadlock check

				lock(filename);

				cout << endl << endl << endl;
				cout << setw(15) << " " << "Enter the amount of money to Deposit   : ";
				getposdouble(amount);

				filein >> acctType;

				switch(acctType)
				{
					case 'y':
					{
						serviceChargeCheckingType service(filename);	// Create new class with file
						fs::remove(filename);

						service.deposit(amount);							// Update balance of Account

						ofstream fileouty(filename);
						fileouty << "y" << endl;
						fileouty << service.getAccountNumber() << endl;
						fileouty << service.getName() << endl;
						fileouty << service.getBalance() << endl;
						fileouty << service.getNumberOfChecksWritten() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << service.getBalance() << "$!" << endl << endl;
						break;
					}
					case 'n':
					{
						noServiceChargeCheckingType noService(filename);	// Create new class with file
						fs::remove(filename);

						noService.deposit(amount);									// Update balance of Account

						ofstream fileoutn(filename);								// Uploads data to new file
						fileoutn << "n" << endl;
						fileoutn << noService.getAccountNumber() << endl;
						fileoutn << noService.getName() << endl;
						fileoutn << noService.getBalance() << endl;
						fileoutn << noService.getInterestRate() << endl;
						fileoutn << noService.getMinimumBalance() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << noService.getBalance() << "$!" << endl << endl;
						break;
					}
					case 'C':
					{
						highInterestCheckingType highChecking(filename);	// Create new class with file
						fs::remove(filename);

						highChecking.deposit(amount);									// Update balance of Account

						ofstream fileoutC(filename);								// Uploads data to new file
						fileoutC << "C" << endl;
						fileoutC << highChecking.getAccountNumber() << endl;
						fileoutC << highChecking.getName() << endl;
						fileoutC << highChecking.getBalance() << endl;
						fileoutC << highChecking.getInterestRate() << endl;
						fileoutC << highChecking.getMinimumBalance() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << highChecking.getBalance() << "$!" << endl << endl;
						break;
					}
					case 'd':
					{
						certificateOfDepositType deposit(filename);	// Create new class with file
						fs::remove(filename);

						deposit.deposit(amount);									// Update balance of Account

						ofstream fileoutd(filename);								// Uploads data to new file
						fileoutd << "d" << endl;
						fileoutd << deposit.getAccountNumber() << endl;
						fileoutd << deposit.getName() << endl;
						fileoutd << deposit.getBalance() << endl;
						fileoutd << deposit.getInterestRate() << endl;
						fileoutd << deposit.getMaturityMonths() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << deposit.getBalance() << "$!" << endl << endl;
						break;
					}
					case 's':
					{
						savingsAccountType savings(filename);	// Create new class with file
						fs::remove(filename);

						savings.deposit(amount);									// Update balance of Account

						ofstream fileouts(filename);								// Uploads data to new file
						fileouts << "s" << endl;
						fileouts << savings.getAccountNumber() << endl;
						fileouts << savings.getName() << endl;
						fileouts << savings.getBalance() << endl;
						fileouts << savings.getInterestRate() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << savings.getBalance() << "$!" << endl << endl;
						break;
					}
					case 'S':
					{
						highInterestSavingsType highSavings(filename);	// Create new class with file
						fs::remove(filename);

						highSavings.deposit(amount);									// Update balance of Account

						ofstream fileoutS(filename);								// Uploads data to new file
						fileoutS << "S" << endl;
						fileoutS << highSavings.getAccountNumber() << endl;
						fileoutS << highSavings.getName() << endl;
						fileoutS << highSavings.getBalance() << endl;
						fileoutS << highSavings.getInterestRate() << endl;
						fileoutS << highSavings.getMinimumBalance() << endl;
						cout << endl << endl;
						cout << setw(15) << " " << "Success! Your balance is now " << highSavings.getBalance() << "$!" << endl << endl;
						break;
					}
					default:
					{
						throw(fileStructureInvalid());
					}
				}			// End Nested Swtich
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				encrypt(filename);

				misc.bankAccount = filename;
				misc.amount = amount;
				log('d'); // logs DEPOSIT


			}			// End Try Block
			catch(cantFind)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error: Account '" << filename << "' does not exist" << endl;
				cout << setw(15) << " " <<  "Press Enter to continue : ";
				waitforenter();
			}
			catch(invalidAmount)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "Error: " << amount << "$ is not a valid amount to deposit" << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}
			catch(fileStructureInvalid)
			{
				cout << endl << endl;
				cout << setw(15) << " " << "File Structure Invalid." << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
			}

			break;

		case '0':
			break;
	}		// End Switch
	return;
}
