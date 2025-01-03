#ifndef highInterestCheckingType_H
#define highInterestCheckingType_H

#include "noServiceChargeCheckingType.h"



class highInterestCheckingType: public noServiceChargeCheckingType
{
	public:
		highInterestCheckingType(fs::path);

		highInterestCheckingType(string n, int acctNumber, double bal);
		highInterestCheckingType(string n, int acctNumber, double bal,
									double minBal, double intRate);

		double getInterestRate();
		void setInterestRate(double intRate);
		void postInterest();
		void createMonthlyStatement();
		virtual void print();
		void update();

		void editMenu();
		void viewMenu();

	private:
		static const double INTEREST_RATE; // = 0.05;
		static const double MIN_BALANCE; // 5000.00;

};

#endif
