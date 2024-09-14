#include "header.h"

namespace fs = std::filesystem;

void createAccountFile() {

	// Prompt the user to enter a name

	string accountHolderLastName;
	string accountHolderFirstName;

	cout << "Enter the LAST name of the account holder: ";
	getline (cin, accountHolderLastName);
	cout << "Enter the FIRST name of the account holder: ";
	getline (cin, accountHolderFirstName);

	// Reference the account number generator

	int randNum = randomNum();
	const string accountNumber = "" + randNum;

	// Construct the filename

	// Issue with accountNumber being an int
	string fileName = accountHolderLastName + ", " + accountHolderFirstName + " - " + accountNumber + ".txt";

	// Specify directory

	fs::path dir = "accounts"; // Or any folder name

	// Ensure directory exits

	if (!fs::exists(dir))
	{
		 fs::create_directories(dir);
	}

	// Create and open the file

	ofstream outFile(fileName);

	// Populate file with variables from A0.3 & Prompt user for inputs (account type, bal, interest rate, etc)
	// Check if the file was created successfully

	if (!outFile)
	{
		cout << "Error creating file: " << fileName << endl;
		return;
	}

	// Close file

	//file.close();

	return;
}

