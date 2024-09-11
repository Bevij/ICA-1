#include "header.h"



void removeMenu(){

	string user; 		//string for account
	char yesNo;			//lazy char for yes no question.
	bool flag;			//flag for while loop

   cout<<"Please insert account last name or account Number: "<<endl;
   cin>>user;

   //search function here.
   while(flag == true)
	{
   	cout<<"Is this the account you would like to delete?(Y/N)"<<endl;
   	cin>>yesNo;


		//if else if else statement for if yes no or invalid option
   	if(yesNo == 'Y')
		{

			cout<<"Account Deleted"<<endl;
	    	cin>>user;
			flag = false;
   	}
		else if (yesNo == 'N')
		{
			//empty cause it will just flip you back up top
		}
   	else
		{
	   	cout<<"Please enter valid option: ";
	   	cin>>yesNo;
		}
	}

	return;
}
