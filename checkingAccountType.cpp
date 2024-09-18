#include "checkingAccountType.h"



checkingAccountType::checkingAccountType(string filename)
{
	ifstream filein(filename);
	string temp;
	filein >> temp;
	filein >> accountNumber;
	filein >> name;
	filein >> balance;
}

checkingAccountType::checkingAccountType(string n, int acctNumber, double bal)
					 : bankAccountType(n, acctNumber, bal)
{
}
