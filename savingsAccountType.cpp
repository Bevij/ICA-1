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
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(31) << "SAVINGS ACCOUNT EDIT" << setw(15) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(12) << "Acct # " << accountNumber << setw(29) << "|" << endl;
		cout << setw(16) << "|" << setw(25) << "1.  Name          : " << setw(20) << left << name << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "2.  Balance       : " << setw(20) << left << balance << "|" << endl << right;
		cout << setw(16) << "|" << setw(25) << "3.  Interest Rate : " << setw(20) << left << interestRate << "|" << endl << right;
		cout << setw(16) << "|" << setw(13) << "0.  EXIT" << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl << endl << endl;

		cout << endl << setw(33) << "Number to change: ";
		cin.get(choice);

		switch(choice)
		{
			case '0':
				leaving = true;
				break;
			case '1':
				cout << endl << endl << setw(31) << "Enter new name: ";
				cin >> name;
				break;
			case '2':
				cout << endl << endl << setw(34) << "Enter new balance: ";
				cin >> balance;
				break;
			case '3':
				cout << endl << endl << setw(40) << "Enter new interest rate: ";
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
