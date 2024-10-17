#include "header.h"


void serviceChargeCheckingType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 'y';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << numberOfChecksWritten;

	encrypt(filename);
}


void noServiceChargeCheckingType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 'n';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << interestRate;
	fout << endl << minimumBalance;

	encrypt(filename);
}


void highInterestCheckingType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 'C';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << interestRate;
	fout << endl << minimumBalance;

	encrypt(filename);
}


void certificateOfDepositType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 'd';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << interestRate;
	fout << endl << maturityMonths;

	encrypt(filename);
}


void savingsAccountType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 's';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << interestRate;

	encrypt(filename);
}


void highInterestSavingsType::update()
{
	string filename = to_string(accountNumber);
	string tempfilename = filename + ".temp";
	fs::remove(tempfilename);
	fs::remove(filename);
	ofstream fout(filename);

	fout << 'S';
	fout << endl << accountNumber;
	fout << endl << name;
	fout << endl << balance;
	fout << endl << interestRate;
	fout << endl << minimumBalance;

	encrypt(filename);
}

