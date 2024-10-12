using namespace std;
#include "header.h"
int loginMenu(){

	int accountType; 
	string userName;
	string pin;
	string password;
	char choice;
	string firstName;
	string lastName;
	cout<<" Welcome to the Bank"<<endl;
	cout<<" Do you already have an acocunt?(y/n)"<<endl;
	cin>>choice;
	
	//for if account is created or not
	if(choice == 'y'){
		
		cout<<"Please Insert Login Information"<<endl;
        cout<<"Insert UserName";
		cin>>userName;
		cout<<endl<<"Insert Password:";
		cin>>password;
		
		
		
	}
    else if( choice =='n')
	{
		cout<<"Please Create UserName: ";
		cin>>userName;
		cout<<endl<<"Please Create Password: ";
		cin>>password;
		cout<<"Please Enter First Name: ";
		cin>>firstName;
		cout<<"Please Enter Last Name: ";
		cin>>lastName;
		cout<<endl<<"What Type of Account is this"<<endl;
		cout<<"1.Client."<<endl;
		cout<<"2.Clerk."<<endl;
		cout<<"3.Manager."<<endl;
		cout<<"0.Admin."<<endl;
		cin>>accountType;
		
			ofstream userFile(userName);
		userFile<<firstName<<endl;
		userFile<<lastName<<endl;
		userFile<<password<<endl;
		userFile<<accountType<<endl;
		
	}
	
	// 1=client menu 2=clerk menu 3=manager menu 0=admin menu
		return accountType;
	
	
}