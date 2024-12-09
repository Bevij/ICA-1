#include "header.h"

loginInfo user;
miscInfo misc;

int main(){
//	loginInfo user; // holds all the data for user, check header.h
						 // to access members of it, its only user.variablename
						 // user.fname = "Steve";

	// Login
	loginMenu();

	int menuSelection = user.role;
	char choice;
	bool leaving = false;

	cout << "Menu " << menuSelection << " selected from user role." << endl;

	do{
		cout << "\033c" << right << endl << endl;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl << right;
		cout << setw(18) << "║" << setw(48) << "║" << endl;
		cout << setw(18) << "║" << setw(33) << "Barnett &  Co. Banking" << setw(15) << "║" <<endl;

		switch(menuSelection)
		{
			case 0:

				cout << setw(18) << "║" << setw(27) << "Exiting..." << setw(21) << "║" << endl;
				leaving = true;
				break;

			case 1:

				cout << setw(18) << "║" << setw(27) << "Client  Menu" << setw(21) << "║" << endl;
				break;

			case 2:

				cout << setw(18) << "║" << setw(28) << "Clerk  Menu" << setw(20) << "║" << endl;
				break;

			case 3:

				cout << setw(18) << "║" << setw(29) << "Manager  Menu" << setw(19) << "║" << endl;
				break;

			case 4:

				cout << setw(18) << "║" << setw(28) << "Admin Menu" << setw(20) << "║" << endl;
				break;

			default:
				cout << "Invalid menu selection." << endl;
				break;
		}

		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "├─────────────────────────────────────────────┤" << endl;
		cout << setw(18) << "│" << setw(48) << "│" << endl;

		switch(menuSelection)
		{
			case 1:							// Client Menu

	   		cout << setw(18) << "│" << setw(27) << "1.  Create New Account" << setw(21) << "│" << endl;
   			cout << setw(18) << "│" << setw(16) << "2.  Deposit" << setw(32) << "│" << endl;
   			cout << setw(18) << "│" << setw(17) << "3.  Withdraw" << setw(31) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Transfer Money" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(22) << "5.  Close Account" << setw(26) << "│" << endl;
				break;

			case 2:							// Clerk Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
				break;

			case 3:							// Manager Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "5.  Manage Login" << setw(27) << "│" << endl;
				break;

			case 4:							// Admin Menu

	   		cout << setw(18) << "│" << setw(23) << "1.  Create Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "2.  View Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "3.  Edit Account" << setw(27) << "│" << endl;
   			cout << setw(18) << "│" << setw(23) << "4.  Remove Account" << setw(25) << "│" << endl;
   			cout << setw(18) << "│" << setw(21) << "5.  Manage Login" << setw(27) << "│" << endl;
				cout << setw(18) << "│" << setw(21) << "6.  Encrypt File" << setw(27) << "│" << endl;
				cout << setw(18) << "│" << setw(21) << "7.  Decrypt File" << setw(27) << "│" << endl;
				cout << setw(18) << "│" << setw(21) << "8.  View Logs   " << setw(27) << "│" << endl;
				cout << setw(18) << "│" << setw(39) << "9.  Increase Maturity for Accounts" << setw(9) << "│" << endl;
				break;
		}

   	cout << setw(18) << "│" << setw(16) << "0.  Log Out" << setw(32) << "│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl;

// CLIENT ACCOUNT LISTED HERE
		if (menuSelection == 1) {
			cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
			cout << setw(15) << " " << "│     You hold the following accounts : " << setw(18) << left << "│" << right << endl;
			cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl;
			cout << endl;

			listAccounts();
		}


   	cout << endl << endl << endl << setw(15) << " ";
		getchar(choice);


		switch(menuSelection)				// Switch for the switch for the menus
		{
			case 1:							// Client
			{
				switch(choice)
				{
					case '1':				// Create Account

						createMenu();
						break;

					case '2':				// Deposit

						depositMenu();
						break;

					case '3':				// Withdraw

						withdraw();
						break;

					case '4':				// Transfer

						transfer();
						break;

					case '5':				// Delete Account

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

			case 2:							// Clerk
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

			case 3:							// Manager
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

			case 4:								// Admin
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

					case '6':
					{
						cout << setw(15) << " " << "Encrypt which file? : ";
						string tempstring1;
						getline(cin, tempstring1);
						encrypt(tempstring1);
						break;
					}
					case '7':
					{
						cout << setw(15) << " " << "Decrypt which file? : ";
						string tempstring2;
						getline(cin, tempstring2);
						encrypt(tempstring2);
						break;
					}
					case '8':
					{
						logMenu();
						break;
					}
					case '9':
					{
						maturityMonths();
						break;
					}

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
		}										// Bracket for Original Switch
	} while(!leaving);

	cout << endl << endl;
	cout << setw(15) << " " << "Logging out of " << user.username << ". . ." << endl;
	log('l');

	return 0;
}
