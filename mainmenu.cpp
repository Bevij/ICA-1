#include "header.h"


int main(){

	char choice;
	bool leaving = false;


	do{
		cout << "\033c" << right << endl << endl;
		cout << setw(15) << " " << "_______________________________________________" << endl;
		cout << setw(16) << "|" << setw(19) << " " << setw(27) << "|" << endl;
		cout << setw(16) << "|" << setw(34) << "'Insert Bank Name here'" << setw(12) << "|" <<endl;
		cout << setw(16) << "|" << setw(28) << "Main Menu" << setw(18) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;
		cout << setw(16) << "|" << setw(20) << " " << setw(26) << "|" << endl;
	   cout << setw(16) << "|" << setw(23) << "1.  Create Account" << setw(23) << "|" << endl;
   	cout << setw(16) << "|" << setw(21) << "2.  View Account" << setw(25) << "|" << endl;
   	cout << setw(16) << "|" << setw(21) << "3.  Edit Account" << setw(25) << "|" << endl;
   	cout << setw(16) << "|" << setw(23) << "4.  Remove Account" << setw(23) << "|" << endl;
   	cout << setw(16) << "|" << setw(13) << "0.  Exit" << setw(33) << "|" << endl;
		cout << setw(15) << " " << "|_____________________________________________|" << endl;


   	cout << endl << endl << endl << setw(15) << " " << "Selection: ";
   	getchar(choice);
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
     	   case '0':
        	  	leaving = true;
           	break;

        	default:

				cout << endl << endl << endl << endl << right;
           	//cout << setw(50) << "Error!" << endl << endl;
				cout << setw(64) << "Error, Please enter a valid menu option [ 4 - 4 ]";

   			cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
				waitforenter();
				break;
		}
	} while(!leaving);

	return 0;
}
