#ifndef checkingAccountType_H
#define checkingAccountType_H

#include "bankAccountType.h"



class dummy
{
	public:
		dummy();
};

class checkingAccountType: public bankAccountType
{
	public:
		checkingAccountType(string filename);

		checkingAccountType(string n, int acctNumber, double bal);
		virtual void writeCheck(double amount) = 0;
		void editMenu();
};

#endif
