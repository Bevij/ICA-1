#include "header.h"

double deposit(char acctType, string filename, double amount)
{
	double balance = 0.0;

	fs::path filePath = searchbynum(filename);

	switch(acctType)
	{
		case 'y':
		{
			serviceChargeCheckingType service(filePath);	// Create new class with file
			fs::remove(filePath);

			service.deposit(amount);							// Update balance of Account

			ofstream fileouty(filename);
			fileouty << "y" << endl;
			fileouty << service.getAccountNumber() << endl;
			fileouty << service.getName() << endl;
			fileouty << service.getBalance() << endl;
			fileouty << service.getNumberOfChecksWritten() << endl;

			balance = service.getBalance();

			break;
		}
		case 'n':
		{
			noServiceChargeCheckingType noService(filePath);	// Create new class with file
			fs::remove(filePath);

			noService.deposit(amount);									// Update balance of Account

			ofstream fileoutn(filename);								// Uploads data to new file
			fileoutn << "n" << endl;
			fileoutn << noService.getAccountNumber() << endl;
			fileoutn << noService.getName() << endl;
			fileoutn << noService.getBalance() << endl;
			fileoutn << noService.getInterestRate() << endl;
			fileoutn << noService.getMinimumBalance() << endl;

			balance = noService.getBalance();

			break;
		}
		case 'C':
		{
			highInterestCheckingType highChecking(filePath);	// Create new class with file
			fs::remove(filePath);

			highChecking.deposit(amount);									// Update balance of Account

			ofstream fileoutC(filename);								// Uploads data to new file
			fileoutC << "C" << endl;
			fileoutC << highChecking.getAccountNumber() << endl;
			fileoutC << highChecking.getName() << endl;
			fileoutC << highChecking.getBalance() << endl;
			fileoutC << highChecking.getInterestRate() << endl;
			fileoutC << highChecking.getMinimumBalance() << endl;

			balance = highChecking.getBalance();

			break;
		}
		case 'd':
		{
			certificateOfDepositType deposit(filePath);	// Create new class with file
			fs::remove(filePath);

			deposit.deposit(amount);									// Update balance of Account

			ofstream fileoutd(filename);								// Uploads data to new file
			fileoutd << "d" << endl;
			fileoutd << deposit.getAccountNumber() << endl;
			fileoutd << deposit.getName() << endl;
			fileoutd << deposit.getBalance() << endl;
			fileoutd << deposit.getInterestRate() << endl;
			fileoutd << deposit.getMaturityMonths() << endl;

			balance = deposit.getBalance();

			break;
		}
		case 's':
		{
			savingsAccountType savings(filePath);	// Create new class with file
			fs::remove(filePath);

			savings.deposit(amount);									// Update balance of Account

			ofstream fileouts(filename);								// Uploads data to new file
			fileouts << "s" << endl;
			fileouts << savings.getAccountNumber() << endl;
			fileouts << savings.getName() << endl;
			fileouts << savings.getBalance() << endl;
			fileouts << savings.getInterestRate() << endl;

			balance = savings.getBalance();

			break;
		}
		case 'S':
		{
			highInterestSavingsType highSavings(filePath);	// Create new class with file
			fs::remove(filePath);

			highSavings.deposit(amount);									// Update balance of Account

			ofstream fileoutS(filename);								// Uploads data to new file
			fileoutS << "S" << endl;
			fileoutS << highSavings.getAccountNumber() << endl;
			fileoutS << highSavings.getName() << endl;
			fileoutS << highSavings.getBalance() << endl;
			fileoutS << highSavings.getInterestRate() << endl;
			fileoutS << highSavings.getMinimumBalance() << endl;

			balance = highSavings.getBalance();

			break;
		}
		default:
		{
			throw(fileStructureInvalid());
		}
	}			// End Nested Swtich


	return balance;
}

