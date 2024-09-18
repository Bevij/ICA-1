#ifndef highInterestSavingsType_H
#define highInterestSavingsType_H

#include "savingsAccountType.h"



class highInterestSavingsType: public savingsAccountType
{
	public:
		highInterestSavingsType(string filename);

		highInterestSavingsType(string n, int acctNumber, double bal);
		highInterestSavingsType(string n, int acctN, double balance, double intRate, double minbalance);
		double getMinimumBalance();
		bool verifyMinimumBalance(double amount);
		virtual void withdraw(double amount);
		virtual void print();

		void editMenu();

	protected:

		double minimumBalance;

	private:

		static const double MINIMUM_BALANCE; // = 2500.00;
		static const double INTEREST_RATE;   // = 0.05;
};

#endif
