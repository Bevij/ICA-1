#include "serviceChargeCheckingType.h"



const double serviceChargeCheckingType::ACCOUNT_SERVICE_CHARGE = 10.00;
const int serviceChargeCheckingType::MAXIMUM_NUM_OF_CHECKS = 5;
const double serviceChargeCheckingType::SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS = 5;

serviceChargeCheckingType::serviceChargeCheckingType(fs::path filePath)
{
//	decrypt(filename);
	ifstream filein(filePath);
//	encrypt(filename);

	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
	filein >> numberOfChecksWritten;

	serviceChargeAmount = ACCOUNT_SERVICE_CHARGE;
	serviceChargeCheck = SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS;
}

serviceChargeCheckingType::serviceChargeCheckingType(string n, int acctNumber, double bal)
							 : checkingAccountType(n, acctNumber, bal)
{
	serviceChargeAmount = ACCOUNT_SERVICE_CHARGE;
	numberOfChecksWritten = 0;
	serviceChargeCheck = 0;
}

serviceChargeCheckingType::serviceChargeCheckingType(string n, int acctNumber, double bal,
															double servChargeAmount, double servChargeCheck)
							 : checkingAccountType(n, acctNumber, bal)
{
	serviceChargeAmount = servChargeAmount;
	serviceChargeCheck = servChargeCheck;
	numberOfChecksWritten = 0;
}


double serviceChargeCheckingType::getServiceChargeAccount()
{
	return serviceChargeAmount;
}

void serviceChargeCheckingType::setServiceChargeAccount(double amount)
{
	serviceChargeAmount = amount;
}

double serviceChargeCheckingType::getServiceChargeChecks()
{
	return serviceChargeCheck;
}

void serviceChargeCheckingType::setServiceChargeChecks(double amount)
{
	serviceChargeCheck = amount;
}

int serviceChargeCheckingType::getNumberOfChecksWritten()
{
	return numberOfChecksWritten;
}

void serviceChargeCheckingType::setNumberOfChecksWritten(int num)
{
	numberOfChecksWritten = num;
}

void serviceChargeCheckingType::postServiceCharge()
{
	balance = balance - serviceChargeAmount;
}

int serviceChargeCheckingType::writeCheck(double amount)
{
	char choice = ' ';

	if(numberOfChecksWritten < MAXIMUM_NUM_OF_CHECKS)
	{
		balance = balance - amount;
		numberOfChecksWritten++;
	}
	else
	{
		cout << setw(15) << " " << "Error, you have already written your maximum amount of Checks!" << endl;
		cout << setw(15) << " " << "Do you Wish to Continue With An Additional $" << serviceChargeCheck << " fee? (Y/N) : ";
		cin >> choice;
		if(choice == 'Y')
		{
			balance = balance - amount - serviceChargeCheck;
			numberOfChecksWritten++;
		}
		else
		{
			cout << setw(15) << " " << "Cancelling Withdraw..." << endl;
			return 1;
		}
	}
	return 0;
}

void serviceChargeCheckingType::createMonthlyStatement()
{
	postServiceCharge();
}

void serviceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Service Charge Checking: " << getName();
	cout << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}
