#include "header.h"

void searchAccounts() {
	// Retrieve user information
	string username = ?; // username FROM INPUT AT LOGIN
	string roleStr = ?; // FROM USER FILE
	string name = ?; // FROM USER FILE (Last, First)

	// Specify directory
	fs::path dir = "./Data/Accounts/" + username + "/" + name;

	// Check if directory exists
	if (!fs::exists(dir) || !fs::is_directory(dir)) {
		cerr << "Directory does not exist or is not a directory." << endl;
			return 1;
	}

	// Converts role to integer for switch
	int roleInt = stoi(roleStr);

	switch (roleInt) {
		case 1: // Client
			cout << "You hold the following accounts: " << endl;

			// Iterates over all files in the directory and lists them (maybe replace with list function)
			for (const auto& entry : fs::directory_iterator(dir)) {
				cout << entry.path().filename() << endl; // REPLACE WITH LIST FUNCTION THAT OUTPUTS FILE CONTENTS AS WELL
			}
			cout << endl;

			// May conflict with file edit function

			/* do {
				// Input
				cout << "Select an account to manage: ";
				getline (cin, acctNameInput);
				cout << endl;
				// File path creation
				fs::path filePath = fs::path(directory) / acctNameInput;
				// Validation
				if (!fs::exists(filePath) && !fs::is_regular_file(filePath)) {
					cout << "Invalid account number. Account " << acctNameInput << " does not exist." << endl;
				} else {
					// OUTPUT FILE CONTENTS
				}
			} while (!fs::exists(filePath) && !fs::is_regular_file(filePath)) */
			break;
		case 2: case 3: case 4: // Clerk, Manager, Admin
			cout << "Please specify how you would like to search for an account." << endl;
			cout << "\t1. Account Holder Name" << endl;
			cout << "\t2. Account Number" << endl << endl;

			// User Input and Validation
			do {
				int searchMethod = 0;
				cin >> searchMethod;
				if (searchMethod != 1 && searchMethod != 2) {
					cout << "Invalid choice. Choose again: "
				}
			while (searchMethod != 1 && searchMethod != 2)

			// Search Methods
			switch (searchMethod) {
				case 1: // Account Holder Name
					// Name Input
					string lastName, firstName, fullName;

					cout << "Enter the last name of the account holder: ";
					getline (cin, lastName);
					cout << endl;
					cout << "Enter the first name of the account holder: ";
					getline (cin, firstName);
					cout << endl;

					fullName = lastName + ", " + firstName;

					// Search Criteria
					fs::path dirParent = "./Data/Accounts";
					fs::path dirSearch = fullName
					bool directoryFound = false;

					// Recursive Search through parent directory and unknown subdirectories (username) for search directory (account holder name)
					for (const auto& entry : fs::recursive_directory_iterator(dirParent)) {
						if (fs::is_directory(entry.path())) {
							if (entry.path().filename() == dirSearch) {
								directoryFound = true;
								cout << fullName << " holds the following accounts:" << endl;
								// Iterates over files in the found search directory and lists them
								for (const auto& entry : fs::directory_iterator(entry.path()/*maybe? if not make dirSearch*/) {
									cout << entry.path().filename() << endl;
								}
								break;
							}
						}
					}

					if (!directoryFound) {
						cout << "Directory not found or does not exist in parent directory or its subdirectories." << endl << endl;
					}
				case 2: // Account Number
					// Account Number Input
					sring acctNumSearch;

					cout << "Enter the account number: ";
					getline (cin, acctNumSearch);
					cout << endl;

					// Search Criteria
					bool accountFound = false;

					// Recursive Search
					for (const auto& entry : fs::recursive_directory_iterator(dirParent)) {
						if (fs::is_regular_file(entry.path())) {
							if (entry.path().filename() == acctNumSearch;) {
								cout << File found: " << entry.path() << endl; // Add list function for contents
								accountFound = true;
								break;
							}
						}
					}
					if (!accountFound) {
						cout << "File not found or does not exist in parent directory or its subdirectories." << endl << endl;
					}
		default:
			cout << "Unkown user role. Permission denied." << endl;
	}
}
