#include "highInterestSavingsType.h"



const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.05;

highInterestSavingsType::highInterestSavingsType(string filename)
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

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal)
						  : savingsAccountType(n, acctNumber, bal, INTEREST_RATE)
{
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctN, double balance, double intRate, double minBalance)
						  : savingsAccountType(n, acctN, balance, intRate)
{
	minimumBalance = minBalance;
}

double highInterestSavingsType::getMinimumBalance()
{
	return minimumBalance;
}

bool highInterestSavingsType::verifyMinimumBalance(double amount)
{
	return (balance - amount >= minimumBalance);
}

void highInterestSavingsType::withdraw(double amount)
{
	if (verifyMinimumBalance(amount))
	{
		balance = balance - amount;
	}
}

void highInterestSavingsType::print()
{
	cout << fixed << showpoint<< setprecision(2);
	cout << "High Interest Savings: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}
