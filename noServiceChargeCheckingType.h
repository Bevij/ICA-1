#ifndef noServiceChargeCheckingType_H
#define noServiceChargeCheckingType_H

#include "checkingAccountType.h"



class noServiceChargeCheckingType: public checkingAccountType
{
	public:
		noServiceChargeCheckingType(string filename);

		noServiceChargeCheckingType(string n, int acctNumber, double bal);
		noServiceChargeCheckingType(string n, int acctNumber, double bal,
										double minBalance, double intRate);

		double getMinimumBalance();
		void setMinimumBalance(double minBalance);
		bool verifyMinimumBalance(double amount);
		void writeCheck(double amount);
		void withdraw(double amount);
		virtual void createMonthlyStatement();
		virtual void print();

		void editMenu();

	protected:
		double minimumBalance;
		double interestRate;

	private:
		static const double MIN_BALANCE; // = 1000.00
		static const double INTEREST_RATE; // = 0.02
};

#endif
