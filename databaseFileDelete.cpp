#include "header.h"

namespace fs = filesystem;


void deleteAccountFile()
{
	// Request last name

	string accountHolderLastName;

	cout << endl << "Enter the LAST name of the account holder: ";
	getline (cin, accountHolderLastName);

	// Request first name

	string accountHolderFirstName;

	cout << endl << "Enter the FIRST name of the account holder: ";
	getline (cin, accountHolderFirstName);

	// Request account number

	int accountNumber = 0;

	cout << endl << "Enter the account number: ";
	cin >> accountNumber;

	// Appends to one file name

	string tempAccountNumber = "" + accountNumber;
	string fileName = accountHolderLastName + ", " + accountHolderFirstName + " - " + tempAccountNumber + ".txt";

	// Specify directory

	fs::path dir = "accounts"; // Or any folder name

	// Ensure directory exists

	if (!fs::exists(dir))
	{
		fs::create_directories(dir);
	}

	// Define the file path

	fs::path filePath = dir/fileName;

	// Check if the file exits before attempting to delete it

	if (fs::exists(filePath))
	{
		// Confirm choice

		int confirm = 0;

		cout << "Are you sure you want to delete this account?" << endl;
		cout << "\t1. Yes" << endl;
		cout << "\t2. No" << endl;

		switch (confirm)
		{
			case 1:

				// Delete the file

				fs::remove(filePath);
				cout << "File deleted successfully!" << endl;

				break;

			case 2:

				// Cancel deletion

				cout << "Cancelled" << endl;

				break;

			default:

				cout << "Invalid choice" << endl;

				break;
		}
	}
	else
	{
		cout << "File does not exist!" << endl;
	}

	return;
}
