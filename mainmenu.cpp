#include "header.h"


int main(){

	int menuSelection = 0;						// 0 will be the default menu / Admin menu until login is completed
														// If you want to test a different menu change this value to 1 for Manager and 2 for Client
	char choice;
	bool leaving = false;


	// Temporary Menu Selector

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " << "Enter 0 for Admin Menu..." << endl;
	cout << setw(15) << " " << "      1 for Clerk Menu..." << endl;
	cout << setw(15) << " " << "      2 for Manager Menu..." << endl;
	cout << setw(15) << " " << "      3 for Client Menu..." << endl << endl;
	cout << setw(15) << " " << "      Selection : ";

	cin >> menuSelection;


	do{
		cout << "\033c" << right << endl << endl;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl << right;
		cout << setw(18) << "║" << setw(48) << "║" << endl;
		cout << setw(18) << "║" << setw(33) << "Barnet &  Co. Banking" << setw(15) << "║" <<endl;

		switch(menuSelection)
		{
			case 0:

				cout << setw(18) << "║" << setw(28) << "Admin  Menu" << setw(20) << "║" << endl << right;
				break;

			case 1:

				cout << setw(18) << "║" << setw(28) << "Clerk  Menu" << setw(20) << "║" << endl;
				break;

			case 2:

				cout << setw(18) << "║" << setw(29) << "Manager  Menu" << setw(19) << "║" << endl;
				break;

			case 3:

				cout << setw(18) << "║" << setw(27) << "Client Menu" << setw(21) << "║" << endl;
				break;
		}

		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(18) << "│" << setw(46) << "|" << endl;

		switch(menuSelection)
		{
			case 0:							// Adim Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "5.  Manage Login" << setw(27) << "│" << endl;
				break;

			case 1:							// Clerk Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
				break;

			case 2:							// Manager Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "5.  Manage Login" << setw(27) << "│" << endl;
				break;

			case 3:							// Client Menu

	   		cout << setw(18) << "│" << setw(27) << "1.  Create New Account" << setw(21) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(16) << "3.  Deposit" << setw(32) << "│" << endl;
   			cout << setw(18) << "│" << setw(17) << "4.  Withdraw" << setw(31) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "5.  Transfer Money" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(22) << "6.  Close Account" << setw(26) << "│" << endl;
				break;
		}

   	cout << setw(18) << "│" << setw(13) << "0.  Exit" << setw(35) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl;


   	cout << endl << endl << endl << setw(15) << " ";
		getchar(choice);


		switch(menuSelection)				// Switch for the switch for the menus
		{
			case 0:								// Admin
			{
				switch(choice)
				{
   	   		case '1':

      	   		createMenu();
         			break;

	      		case '2':

          			viewMenu();
   	      		break;

	      		case '3':

	        			editMenu();
   	      		break;

      			case '4':

           			removeMenu();

						break;

					case '5':

						editLogin();
						break;

     	   		case '0':

        	  			leaving = true;

           			break;

        			default:

						cout << endl << endl << endl << endl << right;
           			//cout << setw(50) << "Error!" << endl << endl;
						cout << setw(15) << " " << "Error, Please enter a valid menu option [ 0 - 4 ]";

   					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
						waitforenter();
						break;
				}								// Bracket for Nested Switch Admin
			}									// Bracket for end Admin Case

			case 1:							// Clerk
			{
				switch(choice)
				{
					case '1':				// Create Account

						createMenu();
						break;

					case '2':				// View Accounts

						viewMenu();
						break;

					case '3':				// Edit Account (withdraw, Deposit, interest Rate)

						editMenu();
						break;

					case '4':				// Delete Account

						removeMenu();
						break;

     	   		case '0':				// Exit

        	  			leaving = true;

           			break;

        			default:

						cout << endl << endl << endl << endl << right;
           			//cout << setw(50) << "Error!" << endl << endl;
						cout << setw(15) << " " << "Error, Please enter a valid menu option [ 0 - 4 ]";

   					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
						waitforenter();
						break;

				}								// Bracket for Nested Switch Clerk

				break;
			}

			case 2:							// Manager
			{
				switch(choice)
				{
					case '1':				// Create Account

						createMenu();
						break;

					case '2':				// View Accounts

						viewMenu();
						break;

					case '3':				// Edit Account (withdraw, Deposit, interest Rate)

						editMenu();
						break;

					case '4':				// Delete Account

						removeMenu();
						break;

					case '5':				// Edit function for Managers to edit the usernames and passwords of all clerks and clients

						editLogin();
						break;

     	   		case '0':				// Exit

        	  			leaving = true;

           			break;

        			default:

						cout << endl << endl << endl << endl << right;
           			//cout << setw(50) << "Error!" << endl << endl;
						cout << setw(15) << " " << "Error, Please enter a valid menu option [ 0 - 4 ]";

   					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
						waitforenter();
						break;

				}								// Bracket for Nested Switch Manager

				break;
			}

			case 3:							// Client
			{
				switch(choice)
				{
					case '1':				// Create Account

						createMenu();
						break;

					case '2':				// View Accounts (Only the Clients, could be 1 account)

						viewMenu();
						break;

					case '3':				// Deposit

						deposit();
						break;

					case '4':				// Withdraw

						withdraw();
						break;

					case '5':				// Transfer

						transfer();
						break;

					case '6':				// Delete Account

						removeMenu();
						break;

     	   		case '0':				// Exit

        	  			leaving = true;

           			break;

        			default:

						cout << endl << endl << endl << endl << right;
           			//cout << setw(50) << "Error!" << endl << endl;
						cout << setw(15) << " " << "Error, Please enter a valid menu option [ 0 - 4 ]";

   					cout << endl << endl << setw(15) << " " << "Press enter to continue: ";
						waitforenter();
						break;
				}								// Bracket for Nested Switch Client
				break;
			}									// Bracket for end Client Case
		}										// Bracket for Original Switch
	} while(!leaving);

	return 0;
}
