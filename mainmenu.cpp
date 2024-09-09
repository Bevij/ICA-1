using namespace std;
#include "menu.h";
#include <iostream>
#include <iomanip>
#include <vector>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
int main(){
 bankAccountType accountList [ARRAYSIZE];
 char choice;
 bool inputValidate;
 inputValidate = true;
 
  cout<<"Main Menu"<<endl;
  cout<<"1. Create" <<endl;
  cout<<"2. View"<<endl;
  cout<<"3. Edit"<<endl;
  cout<<"4. Remove"<<endl;
  cout<<"5. Exit"<<endl;
  cout<<"Enter Number: <<endl;
  cin>>choice;
   	
	while(inputValidate == true)
	 switch(choice){
        case '1':
            createmenu(accountList,);
            break;
        case '2':
         if(accountList->accountNumb ==0)
         cout<<"No accounts to view. Please create an account";
        else 
          viewMenu(accountList);
          break;
        case '3':
		    if(accountList->accountNumb ==0)
         cout<<"No accounts to edit. Please create an account";
	     else
            editMenu(accountList);
            break;
        case '4':
		   if(accountList->accountNumb ==0)
         cout<<"No accounts to remove.";
	     else
            removeMenu(accountList);
            break;
        case '5':           
           inputValidate = false
           break;
        default:
           cout<<"Not a valid option please input correct number: "<<endl;
           cin>> choice;
	}
	
	
	return 0;
	
}