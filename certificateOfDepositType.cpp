#include "certificateOfDepositType.h"



const double certificateOfDepositType::INTEREST_RATE = 0.05;
const int certificateOfDepositType::NUMBER_OF_MATURITY_MONTHS = 6;

certificateOfDepositType::certificateOfDepositType(string filename)
{
	decrypt(filename);
	ifstream filein(filename);
	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
	filein >> interestRate;
	filein >> maturityMonths;
	encrypt(filename);
}

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal)
{
	interestRate = INTEREST_RATE;
	maturityMonths = 0;
	cdMonth = 0;
}

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon)
							: bankAccountType(n, acctNumber, bal)
{
	interestRate = intRate;
	maturityMonths = maturityMon;
	cdMonth = 0;
}

double certificateOfDepositType::getInterestRate()
{
	return interestRate;
}

void certificateOfDepositType::setInterestRate(double rate)
{
	interestRate = rate;
}

double certificateOfDepositType::getCurrentCDMonth()
{
	return cdMonth;
}

void certificateOfDepositType::setCurrentCDMonth(int month)
{
	cdMonth = month;
}

double certificateOfDepositType::getMaturityMonths()
{
	return maturityMonths;
}

void certificateOfDepositType::setMaturityMonths(int month)
{
	maturityMonths = month;
}

void certificateOfDepositType::postInterest()
{
	balance = balance + balance * interestRate;
}

void certificateOfDepositType::withdraw(double amount)
{
	if(cdMonth > maturityMonths)
	{
		balance = balance - amount;

		cout << setw(15) << " " << "Sucsess! Your balance is now" << balance << "$!" << endl << endl;
	}
	else
	{
		cout << setw(15) << " " << "Error, Account has not been matured withdraw cancelled." << endl << endl;
	}

}

void certificateOfDepositType::withdraw()
{
	// Moved to other Withdraw
}

void certificateOfDepositType::createMonthlyStatement()
{
	postInterest();
	cdMonth++;
}

void certificateOfDepositType::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Certificate of Deposit: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance : $" << getBalance();
}

