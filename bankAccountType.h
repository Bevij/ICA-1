#ifndef bankAccountType_H
#define bankAccountType_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include "helpers.h"

using namespace std;
namespace fs = filesystem;

class bankAccountType
{
	public:

		// Constructor

		bankAccountType(string n = "", int acctNumber = 0, double bal = 0);

		// Getters

		int getAccountNumber();
		double getBalance();
		string getName();

		// Setters

		void setName(string n);

		// Functions

		virtual void withdraw(double amount);
		void deposit(double amount);
		virtual void createMonthlyStatement() = 0;
		virtual void print();

	protected:

		int accountNumber;
		string name;
		double balance;
};


#endif
