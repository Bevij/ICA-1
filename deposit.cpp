#include "header.h"


void deposit()
{

	// This is the deposit function, this will promt the client to choose what account to deposit in and the amount
	// In order for Managers, Clients, and Admins to do this they will use Edit menu unless you think they should use this menu

	cout << "\033c" << endl << endl;

	cout << setw(15) << " " <<  "You have entered the Deposit Menu!" << endl << endl << endl;
	cout << setw(15) << " " << "Not much in this menu either..." << endl << endl;							// Yet

	cout << setw(15) << " " << "Press Enter to countinue : ";
	cin.ignore();
	cin.ignore();

	return;
}
