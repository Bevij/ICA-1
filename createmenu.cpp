#include "menu.h"
using namespace std;

createmenu(bankAccountType accountList[ARRAYSIZE], int accountCount){
	char choice;
	cout<<""\033[2J\033[1;1H"<<endl;
	cout<<"What Type of Account would you like to make."<<endl;
	cout<<"1.Bank Account"<<endl<<"------------"<<endl;
	cout<<"2.Savings Account"<<endl;
	cout<<"3.High Interest Savings"<<endl<<"------------"<<endl;
	cout<<"4.Checking Account"<<endl;
	cout<<"5.High Interest Checking"<<endl;
	cout<<"6.No Service Charge Checking"<<endl<<"------------"<<endl;
	cout<<"7.Certificate of Deposit"<<endl<<"------------"<<endl;
	cout<<"8.Exit"<<endl;
	cout<<"Please enter a choice"<<endl;
	cin>> choice;
	
	switch(choice){
		case '1': cout<<"Creating Bank Account"<<endl;
		          cin>>choice;
		break;
		case '2':
		     cout<<"Creating Savings Account"<<endl;
			  cin>>choice;
		break;
		case '3':
		   cout<<"Creating High Interest Savings Account"<<endl;
		    cin>>choice;
		break;
		case'4':
		  cout<<"Creating Checking Account"<<endl;
		    cin>>choice;
		break;
		case'5':
		break;
		case'6':
		break;
		case'7':
		break;
		case'8':
		break;
		default:
		
		
	