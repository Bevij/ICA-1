#include "header.h"

namespace fs = std::filesystem;

void viewAccountFile()
{
	// Request last name

	char accountHolderLastName[ARRAYSIZE] = {};

	cout << endl << "Enter the LAST name of the account holder: ";
	cin >> accountHolderLastName;

	// Request First name

	char accountHolderFirstName[ARRAYSIZE] = {};

	cout << endl << "Enter the FIRST name of the account holder : ";
	cin >> accountHolderFirstName;

	// Request account holder

	char accountNumber[ARRAYSIZE] = {};

	cout << endl << "Enter the account number: ";
	cin >> accountNumber;

	// Appends to one file name

	// Issue with accountNumber being an int
	char fileName[FILENAMESIZE] = {};
	strcat(fileName, accountHolderLastName);
	strcat(fileName, "-");
	strcat(fileName, accountHolderFirstName);
	strcat(fileName, "-");
	strcat(fileName, accountNumber);
	strcat(fileName, ".txt");

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
