#include "header.h"

int loginMenu () {

	int role;
	string userName;
	string pin;
	string password;
	string passwordCheck;
	char acctChoice;
	char usernameChoice;
	string firstName;
	string lastName;
	loginInfo user;

	// Login
	cout << "Username: ";
	cin >> username;
	cout << endl;
	cout << "Password: ";
	cin >> password;
	cout << endl << endl;

	// Check if account exists, prompt user to create one if not
		fs::path dirUserSearch = "./Data/Users";
		fs::path filePath;
		bool userFound = false;
		// Account search
		for (const auto& entry : fs::directory_iterator(dirUserSearch)) {
			if (fs::is_regular_file(entry.path())) {
				if (entry.path().filename() == username) {
					filePath = entry.path();
					userFound = true;
					break;
				}
			}
		}

		// If account exists, input each line into local variables and struct
		if (userFound = true) {
			ifstream fileStream(filePath);
			if (!fileStream) {
				cerr << "Could not open file." << endl;
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
				firstName = linwe;
				user.firstName = firstName;
				roleString = line;
				role = stoi(roleString);
				user.role = role;
			}
			fileStream.close();
		}

		// If account does not exist,
		if (!userFound) {
			cout << "Account not found or does not exist. Would you like to create one? (y/n)" << endl;
		}
		cin >> acctChoice;

			// Account creation
			if (acctChoice == 'y') {
				cout << "You entered the username: " << username << " Is this correct? (y/n)" << endl;
				cin >> usernameChoice;
				if (usernameChoice == 'n') {
					cout << "\nPlease enter a new username: ";
					getline (cin, username);
					break;
				} else if (usernameChoice == 'y') {
					break;
				}
				cout << "\nPlease create a password: "; // Add password obfuscation to hide characters
				getline(cin, password);
				int attempt = 0;
				for (passwordCheck!=password && attempt<3) {
					cout << "\nConfirm password: ";
					getline(cin, passwordCheck);
					if (passwordCheck!=password) {
						attempt++
						cout << "Password does not match. Attempt " << attempt << "/3. Please try again." << endl;
					}
				}
				cout << "\nPlease enter Last Name: ";
				getline(cin, lastName);
				cout << "\nPlease enter First Name: ";
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

				switch (role) {
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
							role = 1;
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
							role = 1;
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
							role = 1;
							break;
						}
						break;
					default:
						cout << "Invalid choice. Role set to Client." << endl;
						break;
				}

				// User file creation
				ofstream userFile(username);
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
				break;
			}

	return role;
}
