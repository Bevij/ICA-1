#include "savingsAccountType.h"



const double savingsAccountType::INTEREST_RATE = 0.03;

// constructor FROM FILE
savingsAccountType::savingsAccountType(string filename)
{
	ifstream filein(filename);
	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
	filein >> interestRate;
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

void savingsAccountType::editMenu() // edits class, only called in editmenu.cpp
{
	bool leaving = false;
	char choice;

	while(!leaving)
	{
		cout << "\033c" << right;
		cout << "SAVINGS ACCOUNT EDIT\n\n";
		cout << setw(4) << "   " << "Acct # " << accountNumber << endl;
		cout << setw(4) << "1. " << setw(15) << "Name: " << name << endl;
		cout << setw(4) << "2. " << setw(15) << "Balance: " << balance << endl;
		cout << setw(4) << "3. " << setw(15) << "Interest Rate: " << interestRate << endl;
		cout << setw(4) << "0. " << "EXIT" << endl;
		cout << endl << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << "Enter new interest rate: ";
				cin >> interestRate;
				break;
		}
	}
	return; //once done editing, returns and lets editmenu.cpp replace old file
}

void savingsAccountType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Savings account: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}
