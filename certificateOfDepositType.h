#ifndef certificateOfDepositType_H
#define certificateOfDepositType_H

#include "bankAccountType.h"



class certificateOfDepositType: public bankAccountType
{
	public:
		certificateOfDepositType(fs::path);

		certificateOfDepositType(string n, int acctNumber, double bal);
		certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon);

		void update();

		double getInterestRate();

		void setInterestRate(double rate);
		double getCurrentCDMonth();
		void setCurrentCDMonth(int month);
		double getMaturityMonths();
		void setMaturityMonths(int month);
		void postInterest();
		void withdraw(double amount);
		void withdraw();
		void createMonthlyStatement();

		void editMenu();
		void viewMenu();

		void print();

	private:

		static const double INTEREST_RATE; // = 0.05;
		static const int NUMBER_OF_MATURITY_MONTHS; // =6;

		double interestRate;
		int maturityMonths;

		int cdMonth;
};

#endif
