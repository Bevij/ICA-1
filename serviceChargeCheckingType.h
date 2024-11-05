#ifndef serviceChargeCheckingType_H
#define serviceChargeCheckingType_H

#include "checkingAccountType.h"



class serviceChargeCheckingType: public checkingAccountType
{
	public:
		serviceChargeCheckingType(string filename);

		serviceChargeCheckingType(string n, int acctNumber, double bal);
		serviceChargeCheckingType(string n, int acctNumber, double bal,
								    double servChargeAmount, double servChargeCheck);

		void update();

		double getServiceChargeAccount();
		void setServiceChargeAccount(double amount);
		double getServiceChargeChecks();
		void setServiceChargeChecks(double amount);
		int getNumberOfChecksWritten();
		void setNumberOfChecksWritten(int num);
		void postServiceCharge();
		int writeCheck(double amount);
		virtual void createMonthlyStatement();
		virtual void print();

		void editMenu();
		void viewMenu();

	protected:
		double serviceChargeAmount;
		double serviceChargeCheck;
		int numberOfChecksWritten;

	private:
		static const double ACCOUNT_SERVICE_CHARGE; // = 10.00;
		static const int MAXIMUM_NUM_OF_CHECKS; // = 5;
		static const double SERVICE_CHARGE_EXCESS_NUM_OF_CHECKS; // = 5;
};

#endif
