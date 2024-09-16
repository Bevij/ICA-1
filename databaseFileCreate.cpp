#include "header.h"

namespace fs = std::filesystem;

void createAccountFile() {

	// Prompt the user to enter a name

	char accountHolderLastName[ARRAYSIZE] = {};
	char accountHolderFirstName[ARRAYSIZE] = {};

	cout << "Enter the LAST name of the account holder: ";
	cin >> accountHolderLastName;
	cout << "Enter the FIRST name of the account holder: ";
	cin >> accountHolderFirstName;

	// Reference the account number generator

	int randNum = randomNum();
	char accountNumber[ARRAYSIZE] = {};
	sprintf(accountNumber, "%d", randNum);

	// Construct the filename

	//const char[

	// Issue with accountNumber being an int
	char fileName[FILENAMESIZE] = {};
	// = accountHolderLastName + ", " + accountHolderFirstName + " - " + accountNumber + ".txt";
	strcat(fileName, accountHolderLastName);
	strcat(fileName, ", ");
	strcat(fileName, accountHolderFirstName);
	strcat(fileName, " - ");
	strcat(fileName, accountNumber);
	strcat(fileName, ".txt");

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

