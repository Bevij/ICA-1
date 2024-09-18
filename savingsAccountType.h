#ifndef savingsAccountType_H
#define savingsAccountType_H

#include "bankAccountType.h"



class savingsAccountType: public bankAccountType
{
	public:
		savingsAccountType(string filename); // constructs off of a file

		savingsAccountType(string n, int acctNumber, double bal);

		savingsAccountType(string n, int acctNumber, double bal, double intRate);

		double getInterestRate();
		void setInterestRate(double rate);
		void postInterest();
		virtual void createMonthlyStatement();
		virtual void print();
		void editMenu(); // for use only by editmenu.cpp

	protected:
		double interestRate;

	private:
		static const double INTEREST_RATE; // = 0.03
};

#endif
