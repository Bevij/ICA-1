#include "savingsAccountType.h"



const double savingsAccountType::INTEREST_RATE = 0.03;

savingsAccountType::savingsAccountType()
{
}

// constructor FROM FILE
savingsAccountType::savingsAccountType(string filename)
{
	decrypt(filename);
	ifstream filein(filename);
	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
	filein >> interestRate;
	encrypt(filename);
}

savingsAccountType::savingsAccountType(string n, int acctNumber, double bal)
					:bankAccountType(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
}

savingsAccountType::savingsAccountType(string n, int acctNumber, double bal, double intRate)
					:bankAccountType(n, acctNumber, bal)
{
	setInterestRate(intRate);
}

double savingsAccountType::getInterestRate()
{
	return interestRate;
}

void savingsAccountType::setInterestRate(double rate)
{
	interestRate = rate;
}

void savingsAccountType::postInterest()
{
	balance = balance + balance * interestRate;
}

void savingsAccountType::createMonthlyStatement()
{
	postInterest();
}

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings account: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}
