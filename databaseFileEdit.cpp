#include "header.h"

namespace fs = std::filesystem;

void viewAccountFile()
{
	// Request last name

	string accountHolderLastName = "";

	cout << endl << "Enter the LAST name of the account holder: ";
	getline (cin, accountHolderLastName);

	// Request First name

	string accountHolderFirstName = "";

	cout << endl << "Enter the FIRST name of the account holder : ";
	getline (cin, accountHolderFirstName);

	// Request account holder

	int accountNumber = 0;

	cout << endl << "Enter the account number: ";
	cin >> accountNumber;

	// Appends to one file name

	// Issue with accountNumber being an int
	string tempAccountNumber = "" + accountNumber; // Doesn't work
	string fileName = accountHolderLastName + ", " + accountHolderFirstName + " - " + tempAccountNumber + ".txt";

	// Specify directory

	fs::path dir = "accounts"; // Or any folder name

	// Ensure directory exists

	if (!fs::exists(dir))
	{
		 fs::create_directories(dir);
	}

	// Open the file

	fstream file(fileName, ios::app);

	// Close the file

	file.close();

	return;
}
