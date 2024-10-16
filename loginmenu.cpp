#include "header.h"

int loginMenu () {

	string username;
	string password;
	string lastName;
	string firstName;
	int role;

	loginInfo user;

	// Login
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	cout << endl << endl;

	// Check if account exists, prompt user to create one if not
		fs::path dirUserSearch = "./Data/Users";
		fs::path filePath;
		bool userFound = false;
		// Account search
		for (const auto& entry : fs::directory_iterator(dirUserSearch)) {
			if (fs::is_regular_file(entry.path())) {
				if (entry.path().filename() == username) { // .stem() searches for file without extension instead of .filename()
					filePath = entry.path();
					userFound = true;
					break;
				}
			}
		}

		// If account exists, input each line into local variables and struct
		if (userFound) {
			ifstream fileStream(filePath);

			if (!fileStream) {
				cerr << "Could not open file." << endl;
				return 1;
			}

			string line;
			string roleString;
			while (getline(fileStream, line)) {
				username = line;
				user.username = username;
				password = line;
				user.password = password;
				lastName = line;
				user.lastName = lastName;
				firstName = line;
				user.firstName = firstName;
				roleString = line;
				// Converts string role to int
				stringstream container(roleString);
				container >> role;
				user.role = role;
			}
			fileStream.close();
			cout << user.username << endl;
			cout << user.password << endl;
			cout << user.lastName << endl;
			cout << user.firstName << endl;
			cout << user.role << endl;
		}

		// If account does not exist,
		char acctChoice;
		if (!userFound) {
			cout << "Account not found or does not exist. Would you like to create one? (y/n)" << endl;
		}
		cin >> acctChoice;

			// Account creation
			char usernameChoice;
			if (acctChoice == 'y') {
				cout << "You entered the username: " << username << " Is this correct? (y/n)" << endl;
				cin >> usernameChoice;
				if (usernameChoice == 'n') {
					cout << "\nPlease enter a new username: ";
					getline (cin, username);
				}

				// Password
				cout << "\nPlease create a password: "; // Add password obfuscation to hide characters
				cin.ignore();
				getline(cin, password);

				int attempt = 0;
				string passwordCheck;

				do {
					cout << "\nConfirm password: ";
					cin.ignore();
					getline(cin, passwordCheck);
					if (passwordCheck != password) {
						attempt++;
						cout << "Password does not match. Attempt " << attempt << "/3. Please try again." << endl;
					}
				} while (passwordCheck != password && attempt < 3);

				// Name
				cout << "\nPlease enter Last Name: ";
				cin.ignore();
				getline(cin, lastName);
				cout << "\nPlease enter First Name: ";
				cin.ignore();
				getline(cin, firstName);

				// Role assignment
				cout << "What type of account is this? Please enter the number value." << endl;
				cout << "1. Client." << endl;
				cout << "2. Clerk." << endl;
				cout << "3. Manager." << endl;
				cout << "4. Admin." << endl;
				cin >> role;

				int pinMaster = 1234;
				int pinInput = 0;
				int pinAttemptCounter = 0;

				switch (role) {
					case 1: // Client
						break;
					case 2: // Clerk
						do {
							cout << "Enter PIN for Clerk security clearance: ";
							cin >> pinInput;
							if (pinInput == pinMaster) {
								cout << "PIN accepted. Role set to Clerk." << endl;
								break;
							} else {
								pinAttemptCounter++;
								cout << "Invalid PIN. Attempt " << pinAttemptCounter << "/3. Try again." << endl;
							}
							if (pinInput != pinMaster && pinAttemptCounter == 3) {
								cout << "Access denied. Role set to Client." << endl;
								role = 1;
								break;
							}
						} while (pinInput != pinMaster && pinAttemptCounter < 3);
						break;
					case 3: // Manager
						do {
							cout << "Enter PIN for Manager security clearance: ";
							cin >> pinInput;
							if (pinInput == pinMaster) {
								cout << "PIN accepted. Role set to Manager." << endl;
								break;
							} else {
								pinAttemptCounter++;
								cout << "Invalid PIN. Attempt " << pinAttemptCounter << "/3. Try again." << endl;
							}
							if (pinInput != pinMaster && pinAttemptCounter == 3) {
								cout << "Access denied. Role set to Client." << endl;
								role = 1;
								break;
							}
						} while (pinInput != pinMaster && pinAttemptCounter < 3);
						break;
					case 4: // Admin
						do {
							cout << "Enter PIN for Admin security clearance: ";
							cin >> pinInput;
							if (pinInput == pinMaster) {
								cout << "PIN accepted. Role set to Admin." << endl;
								break;
							} else {
								pinAttemptCounter++;
								cout << "Invalid PIN. Attempt " << pinAttemptCounter << "/3. Try again." << endl;
							}
							if (pinInput != pinMaster && pinAttemptCounter == 3) {
								cout << "Access denied. Role set to Client." << endl;
								role = 1;
								break;
							}
						} while (pinInput != pinMaster && pinAttemptCounter < 3);
						break;
					default:
						cout << "Invalid choice. Role set to Client." << endl;
						break;
				}

				// User file creation
				string newFilePath = "./Data/Users/" + username;
				fs::path newUserPath = newFilePath;
				ofstream userFile(newUserPath);
				userFile << username << endl;
				user.username = username;
				userFile << password << endl;
				user.password = password;
				userFile << lastName << endl;
				user.lastName = lastName;
				userFile << firstName << endl;
				user.firstName = firstName;
				userFile << role << endl;
				user.role = role;

			} else if (acctChoice == 'n') {
				cout << "Exiting..." << endl;
				waitforenter();
			}

	return role;
}
