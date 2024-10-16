#include "noServiceChargeCheckingType.h"


const double noServiceChargeCheckingType::MIN_BALANCE = 1000.00;
const double noServiceChargeCheckingType::INTEREST_RATE = 0.02;

noServiceChargeCheckingType::noServiceChargeCheckingType()
{
}

noServiceChargeCheckingType::noServiceChargeCheckingType(string filename)
{
	decrypt(filename);
	ifstream filein(filename);
	encrypt(filename);

	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
	filein >> interestRate;
	filein >> minimumBalance;
}


noServiceChargeCheckingType::noServiceChargeCheckingType(string n, int acctNumber, double bal)
								: checkingAccountType(n, acctNumber, bal)
{
	minimumBalance = MIN_BALANCE;
	interestRate = INTEREST_RATE;
}

noServiceChargeCheckingType::noServiceChargeCheckingType(string n, int acctNumber, double bal, double minBalance, double intRate)
								: checkingAccountType(n, acctNumber, bal)
{
	minimumBalance = minBalance;
	interestRate = intRate;
}

double noServiceChargeCheckingType::getMinimumBalance()
{
	return minimumBalance;
}

void noServiceChargeCheckingType::setMinimumBalance(double minBalance)
{
	minimumBalance = minBalance;
}

double noServiceChargeCheckingType::getInterestRate()
{
	return interestRate;
}

void noServiceChargeCheckingType::setInterestRate(double intRate)
{
	interestRate = intRate;
}



bool noServiceChargeCheckingType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void noServiceChargeCheckingType::writeCheck(double amount)
{
	if(verifyMinimumBalance(amount))
	{
		balance = balance - amount;
	}
}

void noServiceChargeCheckingType::withdraw(double amount)
{
	if(verifyMinimumBalance(amount))
	{
		balance = balance - amount;
	}
}

void noServiceChargeCheckingType::createMonthlyStatement()
{
}

void noServiceChargeCheckingType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "No Service Charge Check. " << getName() << "\t ACCT# ";
	cout << getAccountNumber() << "\tBalance: $" << getBalance();
}
