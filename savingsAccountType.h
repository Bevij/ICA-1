#ifndef savingsAccountType_H
#define savingsAccountType_H

#include "bankAccountType.h"



class savingsAccountType: public bankAccountType
{
	public:
		savingsAccountType();
		savingsAccountType(string filename); // constructs off of a file

		savingsAccountType(string n, int acctNumber, double bal);

		savingsAccountType(string n, int acctNumber, double bal, double intRate);

		void update();

		double getInterestRate();
		void setInterestRate(double rate);
		void postInterest();
		virtual void createMonthlyStatement();
		virtual void print();

		void editMenu();
		void viewMenu();

	protected:
		double interestRate;

	private:
		static const double INTEREST_RATE; // = 0.03
};

#endif
