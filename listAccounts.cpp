#include "header.h"

string listAccounts() {
	// Retrieve user information from struct
	string username = user.username;
	string lastName = user.lastName;
	string firstName = user.firstName;
	int role = user.role;
	string fullName = lastName + "/" + firstName;

	string foundFilePath = "";

	// Specify directory
	/*fs::path dir = "./Data/Accounts/" + fullName + "/" + username;*/
	fs::path dir = "./";

	// Check if directory exists
	if (!fs::exists(dir) || !fs::is_directory(dir)) {
		cerr << "Directory does not exist or is not a directory." << endl;
		// leaving = true;
	}

// *******ADD A DO WHILE LEAVING != TRUE LOOP FOR ERRORS******** //

	switch (role) {
		case 1: // Client
		{
			cout << "You hold the following accounts: " << endl;

			// Iterates over all files in the directory and lists them (maybe replace with list function)
			for (const auto& entry : fs::recursive_directory_iterator(dir)) {
				cout << entry.path().filename() << endl; // REPLACE WITH LIST FUNCTION THAT OUTPUTS FILE CONTENTS AS WELL
			}
			cout << endl;
			break;
		}
		case 2: case 3: case 4: // Clerk, Manager, Admin
		{
			int acctSearchMethod = 0;
			cout << "Please specify how you would like to search for an account." << endl;
			cout << "\t1. Account Holder Name" << endl;
			cout << "\t2. Account Number" << endl << endl;

			// User Input and Validation
			do {
				getposint (acctSearchMethod);
				if (acctSearchMethod != 1 && acctSearchMethod != 2) {
					cout << "Invalid choice. Choose again: ";
				}
			}
			while (acctSearchMethod != 1 && acctSearchMethod != 2);

			// Search Methods
			switch (acctSearchMethod) {
				case 1: // Account Holder Name
				{
					// Name Input
					cout << "Enter the last name of the account holder: ";
					getline (cin, lastName);
					cout << endl;
					cout << "Enter the first name of the account holder: ";
					getline (cin, firstName);
					cout << endl;

					fullName = lastName + "/" + firstName;

					// Search Criteria
					fs::path dirParent = "./Data/Accounts";
					fs::path dirSearch = fullName;
					bool directoryFound = false;

					// Recursive Search through parent directory and unknown subdirectories (username) for search directory (account holder name)
					for (const auto& entry : fs::recursive_directory_iterator(dirParent)) {
						if (fs::is_directory(entry.path())) {
							if (entry.path().filename() == dirSearch) {
								directoryFound = true;
								cout << fullName << " holds the following accounts:" << endl;
								// Iterates over files in the found search directory and lists them
								for (const auto& entry : fs::directory_iterator(entry.path())/*maybe? if not make dirSearch*/) {
									cout << entry.path().filename() << endl; // ****** EVENTUALLY MAKE A MENU TO SELECT WHICH FILE TO EDIT/VIEW
								}
								break;
							} // End nested if
						} // End if
					} // End for

					if (!directoryFound) {
						cout << "Directory not found or does not exist in parent directory or its subdirectories." << endl << endl;
						// ********* LEAVING=TRUE
					}
					break;
				} // End nested case 1
				case 2: // Account Number
				{
					// Account Number Input
					string acctNumSearch;

					cout << "Enter the account number: ";
					getline (cin, acctNumSearch);
					cout << endl;

					// Search Criteria
					bool accountFound = false;

					// Recursive Search
					for (const auto& entry : fs::recursive_directory_iterator(dir)) {
						if (fs::is_regular_file(entry.path())) {
							if (entry.path().filename() == acctNumSearch) {
								cout << "File found: " << entry.path() << endl; // Add list function for contents
								accountFound = true;
								foundFilePath = entry.path();
								break;
							} // End nested if
						} // End if
					} // End for
					if (!accountFound) {
						cout << "File not found or does not exist in parent directory or its subdirectories." << endl << endl;
						// add loop for input or leaving = true to exit
					}
					break;
				} // End nested case 2
				default:
				{
					cout << "Invalid search method. Please select again." << endl; // ****ADD LOOP TO KEEP PROMPTING UNTIL VALID CHOICE
					break;
				}
			} // End nested switch
			break;
		} // End case 2
		default:
		{
			cout << "Unkown user role. Permission denied." << endl;
			// LEAVING = TRUE
			break;
		}
	} // End switch
	return foundFilePath;
}
