#include "header.h"


void maturityMonths()
{

	string filename;
	char choice = ' ';
	char acctType = ' ';
	bool exit = true;

	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "╔════════════════════════════════════════╗" << endl;
	cout << setw(18) << "║" << setw(43) << "║" << endl;
	cout << setw(15) << " " << "║             Maturity  Months           ║" << endl;
	cout << setw(15) << " " << "╚════════════════════════════════════════╝" << endl << endl;

	cout << setw(15) << " " << "Enter The Account Number to Mature : ";
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

		filein >> acctType;

		switch(acctType)
		{
			case 'y':
			{
				cout << endl << endl;

				cout << setw(15) << " " << "Error, Not a Certificate of Deposit Account" << endl << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				break;
			}
			case 'n':
			{
				cout << endl << endl;

				cout << setw(15) << " " << "Error, Not a Certificate of Deposit Account" << endl << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				break;
			}
			case 'C':
			{
				cout << endl << endl;

				cout << setw(15) << " " << "Error, Not a Certificate of Deposit Account" << endl << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				break;
			}
			case 'd':
			{
				certificateOfDepositType deposit(filename);
				fs::remove(filename);


				do
				{
						cout << "\033c" << endl << endl;
						cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
						cout << setw(18) << "║" << setw(48) << "║" << endl;
						cout << setw(15) << " " << "║                Maturity Months              ║" << endl;
						cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl << endl << left;
						cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
						cout << setw(15) << " " << "│       Name           : " << setw(21) << deposit.getName() << "│" << endl;
						cout << setw(15) << " " << "│       Account Number : " << setw(21) << deposit.getAccountNumber() << "│" << endl << right;
						deposit.createMonthlyStatement();

						cout << endl << endl;
						cout << setw(15) << " " << "Do You Want To Mature for Another Month? (Y/N) : ";
						cin >> choice;

						if(choice == 'Y' || choice == 'y')
						{
							exit = false;
						}
						else
						{
							exit = true;
						}

				}while(!exit);

				ofstream fileoutd(filename);
				fileoutd << "d" << endl;
				fileoutd << deposit.getAccountNumber() << endl;
				fileoutd << deposit.getName() << endl;
				fileoutd << deposit.getBalance() << endl;
				fileoutd << deposit.getInterestRate() << endl;
				fileoutd << deposit.getMaturityMonths() << endl;

				break;
			}
			case 's':
			{
				cout << endl << endl;

				cout << setw(15) << " " << "Error, Not a Certificate of Deposit Account" << endl << endl;
				cout << setw(15) << " " << "Press Enter to continue : ";
				waitforenter();
				break;
			}
			case 'S':
			{
				cout << endl << endl;

				cout << setw(15) << " " << "Error, Not a Certificate of Deposit Account" << endl << endl;
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

		//misc.bankAccount = filename;
	//	misc.amount = amount;
		//log('w'); // logs WITHDRAWS


	}			// End Try Block
	catch(cantFind)
	{
		cout << endl << endl;
		cout << setw(15) << " " << "Error : Account '" << filename << "' does not exist!" << endl;
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
