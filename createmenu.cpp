#include "menu.h"
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
void createmenu(){
	char choice;

   bool exit = true;
	cout << "\033[2J\033[1;1H" << endl;
	cout << "What Type of Account would you like to make." << endl;
	cout << "1.Bank Account" << endl << "------------" << endl;
	cout << "2.Savings Account" << endl;
	cout << "3.High Interest Savings" << endl << "------------" << endl;
	cout << "4.Checking Account" << endl;
	cout << "5.High Interest Checking" << endl;
	cout << "6.No Service Charge Checking" << endl << "------------" << endl;
	cout << "7.Certificate of Deposit" << endl << "------------" << endl;
	cout << "8.Exit" << endl;
	cout << "Please enter a choice" << endl;
	cin >> choice;
	while(exit == true)
	{
		switch(choice)
		{
			case '1':
				cout<<"Creating Bank Account"<<endl;
			break;
			case '2':
				cout<<"Creating Savings Account"<<endl;
			break;
			case '3':
			   cout<<"Creating High Interest Savings Account"<<endl;
			break;
			case'4':
				cout<<"Creating Checking Account"<<endl;
			break;
			case'5':
				cout<<"Creating High Interest Savings Account"<<endl;
			break;
			case'6':
				cout<<" No service Charge Checking"<<endl;
			break;
			case'7':
				cout<<" Certificate of Deposit"<<endl;
			break;
			case'8':
				cout<<"Exit"<<endl;
				exit = false;
			break;
			default:
				cout << "option not available please select a valid option" << endl;
				cin >> choice;
		}
	}

   return;
}
