#include "header.h"



void withdraw()
{
	// This is the Withdraw Function, this will only be seen by clients and will prompt them to enter a account they want to withdraw from and the amount
	// In order for Clerks, Managers, and Admins to do this they will use Edit Account unless you want them to use this

	cout << "\033c" << endl << endl;
	cout << setw(15) << " " << "Welcome  to  Withdraw!" << endl << endl;
	cout << setw(20) << " " << "Population" << endl << endl;
	cout << setw(21) << " " << "21 Lines" << endl << endl << endl;							// For now

	cout << setw(15) << " " << "Press Enter to countinue : ";
	cin.ignore();
	cin.ignore();

	return;
}
