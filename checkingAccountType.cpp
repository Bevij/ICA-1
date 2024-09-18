#include "checkingAccountType.h"


checkingAccountType::checkingAccountType()
{
}

checkingAccountType::checkingAccountType(string n, int acctNumber, double bal)
					 : bankAccountType(n, acctNumber, bal)
{
}
