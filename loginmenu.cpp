#include "header.h"

int loginMenu () {

	string username, passwordInput, password, lastName, firstName, roleString;
	int role = 1;
	int attempt = 0;
	bool leaving = false;

	// Login

	do {
		// Username
		cout << "Username: ";
		getline(cin, username);

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
				}

				// Stores file variables locally if present and in correct order
				if (getline(fileStream, username) &&
					 getline(fileStream, password) &&
					 getline(fileStream, lastName) &&
					 getline(fileStream, firstName) &&
					 getline(fileStream, roleString)) {

						// Stores local variables in struct
						user.username = username;
						user.password = password;
						user.lastName = lastName;
						user.firstName = firstName;
						role = stoi(roleString);
						user.role = role; // Convert roleString to integer
					} else {
						cerr << "File format is incorrect or incomplete." << endl;
					}

	    		fileStream.close();

				// Password Check
				attempt = 0;

				do {
					cout << "Password: ";
					passwordInput = hidePass(); // password obfuscation function

					if (passwordInput == password) {
						cout << "Welcome back, " << firstName << "! Press enter to continue..." << endl;
						leaving = true;
						waitforenter();
					}
					if (passwordInput != password) {
						attempt++;
						cout << "Incorrect password. Attempt " << attempt << "/3. Please try again." << endl;
					}
					if (attempt == 3) {
						cout << "Too many failed attempts. Press enter to exit..." << endl;
						role = 0;
						leaving = true;
						waitforenter();
					}
				} while (passwordInput != password && attempt < 3);
			}

			// If account does not exist,
			char acctChoice;
			if (!userFound) {
				cout << "Account not found or does not exist. Would you like to create one? (y/n)" << endl;
				cin >> acctChoice;

				// Account creation
				char usernameChoice;
				if (acctChoice == 'y') {
					cout << "You entered the username: " << username << " Is this correct? (y/n)" << endl;
					cin >> usernameChoice;
					if (usernameChoice == 'n') {
						cout << "\nPlease enter a new username: ";
						cin.ignore();
						getline (cin, username);
					}

					// Password
					cout << endl << "Please create a password: "; // Add password obfuscation to hide characters
					cin.ignore();
					password = hidePass(); // password obfuscation function

					attempt = 0;
					string passwordCheck;

					do {
						cout << endl << "Confirm password: ";
						passwordCheck = hidePass(); // password obfuscation function

						if (passwordCheck != password) {
							attempt++;
							cout << "Password does not match. Attempt " << attempt << "/3. Please try again." << endl;
						}
						if (attempt == 3) {
							cout << "Too many failed attempts. Press enter to exit..." << endl;
							leaving = true;
							waitforenter();
						}
					} while (passwordCheck != password && attempt < 3);

					// Name
					cout << endl << "Please enter Last Name: ";
					getline(cin, lastName);
					cout << endl << "Please enter First Name: ";
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
					attempt = 0;

					switch (role) {
						case 1: // Client
							break;
						case 2: // Clerk
							do {
								cout << "Enter PIN for Clerk security clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << "PIN accepted. Role set to Clerk. Press enter to continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << "Invalid PIN. Attempt " << attempt << "/3. Try again." << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << "Access denied. Role set to Client. Press enter to continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						case 3: // Manager
							do {
								cout << "Enter PIN for Manager security clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << "PIN accepted. Role set to Manager. Press enter to continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << "Invalid PIN. Attempt " << attempt << "/3. Try again." << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << "Access denied. Role set to Client. Press enter to continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						case 4: // Admin
							do {
								cout << "Enter PIN for Admin security clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << "PIN accepted. Role set to Admin. Press enter to continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << "Invalid PIN. Attempt " << attempt << "/3. Try again." << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << "Access denied. Role set to Client. Press enter to continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						default:
							cout << "Invalid choice. Role set to Client. Press enter to continue..." << endl;
							role = 1;
							leaving = true;
							waitforenter();
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

					leaving = true;

				} else if (acctChoice == 'n') {
					cout << "Press enter to exit..." << endl;
					leaving = true;
					waitforenter();
				}
			}								// End bracket for user account creation
	} while (!leaving);

	return role;
}
