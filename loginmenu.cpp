#include "header.h"

int loginMenu () {

	int accountType;
	string userName;
	string pin;
	string password;
	char acctChoice;
	char usernameChoice;
	string firstName;
	string lastName;
	string fullName;

	// Login
	cout << "Username: ";
	cin >> username;
	cout << endl;
	cout << "Password: ";
	cin >> password;
	cout << endl << endl;

	// Check if account exists, prompt user to create one if not
		fs::path dirUserSearch = "./Data/Users";
		bool userFound = false;
		// Account search
		for (const auto& entry : fs::directory_iterator(dirUserSearch)) {
			if (fs::is_regular_file(entry.path())) {
				if (entry.path().filename() == username) {
					userFound = true;
					break;
				}
			}
		}
		if (!userFound) {
			cout << "Account not found or does not exist. Would you like to create one? (y/n)" << endl;
		}
		cin >> acctChoice;

			// Account creation
			if (acctChoice == 'y') {
				cout << "You entered the username: " << username << " Is this correct? (y/n)" << endl;
				cin >> usernameChoice;
				cout << endl;
				if (usernameChoice == 'n') {
					cout << "Please enter a new username: ";
					cin >> username;
					cout << endl;
					break;
				} else if (usernameChoice == 'y') {
					break;
				}
				cout << "Please create a password: "; // Add password obfuscation to hide characters
				cin >> password;
				cout << endl;
				cout << "Please enter Last Name: "
				cin >> lastName;
				cout << endl;
				fullName = lastName + ", " + firstName;
				// Role assignment
				cout << "What type of account is this?" << endl;
				cout << "1. Client." << endl;
				cout << "2. Clerk." << endl;
				cout << "3. Manager." << endl;
				cout << "4. Admin." << endl;
				cin >> accountType;

				int pinMaster = 1234;
				int pinInput = 0;

				switch (accountType) {
					case 1:
						break;
					case 2:
						cout << "Enter PIN for Clerk security clearance: ";
						cin >> pinInput;
						if (pinInput == pinMaster) {
							cout << "PIN accepted. Role set to Clerk." << endl;
							break;
						} else {
							cout << "Invalid PIN. Role set to Client." << endl;
							accountType = 1;
							break;
						}
						break;
					case 3:
						cout << "Enter PIN for Manager security clearance: ";
						cin >> pinInput;
						if (pinInput == pinMaster) {
							cout << "PIN accepted. Role set to Manager." << endl;
							break;
						} else {
							cout << "Invalid PIN. Role set to Client." << endl;
							accountType = 1;
							break;
						}
						break;
					case 4:
						cout << "Enter PIN for Admin security clearance: ";
						cin >> pinInput;
						if (pinInput == pinMaster) {
							cout << "PIN accepted. Role set to Admin." << endl;
							break;
						} else {
							cout << "Invalid PIN. Role set to Client." << endl;
							accountType = 1;
							break;
						}
						break;
					default:
						cout << "Invalid choice. Role set to Client." << endl;
						break;
				}

				// User file creation
				ofstream userFile(username);
				userFile << password << endl;
				userFile << fullName << endl;
				userFile << accountType << endl;

			} else if (acctChoice == 'n') {
				cout << "Exiting..." << endl;
				break;
			}
	return accountType; // Either have a function embedded that reads accountType from file for this, or take out entirely
}
