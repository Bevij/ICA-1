#include "header.h"


int main(){

	int num;
	char choice;
	bool inputValidate;
	inputValidate = true;

	do{
		cout << "\033c" << endl << endl;
		cout<<"Main Menu"<<endl;
	   cout<<"1. Create" <<endl;
   	cout<<"2. View"<<endl;
   	cout<<"3. Edit"<<endl;
   	cout<<"4. Remove"<<endl;
   	cout<<"5. Exit"<<endl;
		cout << "6. Random Num Test" << endl;
		cout << "7. Create file Test" << endl;
		cout << "8. Delete file Test" << endl;
		cout << "9. Edit file Test" << endl;
   	cout<<"Enter Number: "<<endl;
   	cin>>choice;

		switch(choice)
		{
   	   case '1':
      	   createMenu();
         	break;
	      case '2':
   	    	/* if(->accountNumb ==0)
      	   cout<<"No accounts to view. Please create an account";
        		else */
          	viewMenu();
   	      break;
	      case '3':
				/* if(->accountNumb ==0)
         	cout<<"No accounts to edit. Please create an account";
	     		else*/
	        	editMenu();
   	      break;
      	case '4':
				/*   if(->accountNumb ==0)
         	cout<<"No accounts to remove.";
	     		else */
           	removeMenu();
           	break;
     	   case '5':
        	  	inputValidate = false;
           	break;
			case '6':
				//Temp testing of random function
				num = randomNum();
				cout << endl << endl << "Here is a random number : " << num << endl << endl;
				cout << endl << "Press enter to continue : ";
				cin.ignore();
				cin.ignore();

				break;

			case '7':

				createAccountFile();

				break;

			case '8':

				deleteAccountFile();

				break;

			case '9':

				viewAccountFile();

				break;
        	default:
           	cout<<"Not a valid option please input correct number: "<<endl;
           	cin>> choice;
				break;
		}
	} while(choice != '5');

	return 0;
}
