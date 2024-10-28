#include "header.h"

int loginMenu () {

	string username, passwordInput, password, lastName, firstName, roleString;
	int role = 1;
	int attempt = 0;
	bool leaving = false;

	// Login

	do {
		cout << "\033c" << endl << endl;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(15) << " " << "║" << setw(48) << "║" << endl;
		cout << setw(15) << " " << "║" << setw(33) << "Barnett & Co. Banking" << setw(15) << "║" << endl;
		cout << setw(15) << " " << "║" << setw(28) << "Login  Menu" << setw(20) << "║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl << endl;


		// Username
		cout << setw(15) << " " << "Username :  ";
		getline(cin, username);
		user.username = username;

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
					cerr << setw(15) << " " << "ERROR, Could Not Open File." << endl;
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
						cerr << setw(15) << " " << "ERROR, File Format is Incorrect or Incomplete." << endl;
					}

	    		fileStream.close();

				// Password Check
				attempt = 0;

				do {
					cout << setw(15) << " " << "Password :  ";
					passwordInput = hidePass(); // password obfuscation function

					if (passwordInput == password) {
						cout << endl << setw(15) << " " << "Welcome Back, " << firstName << "!" << endl << endl;
						cout << setw(15) << " " << "Press Enter to Continue...";
						leaving = true;
						waitforenter();
					}
					if (passwordInput != password) {
						log('b'); // logs a BAD PASSWORD
						attempt++;
						cout << endl << endl << setw(15) << " " << "Incorrect Password. Attempt " << attempt << "/3." << "Please Try Again." << endl << endl;
					}
					if (attempt == 3) {
						cout << endl << setw(15) << " " << "Too Many Failed Attempts!" << endl;
						cout << setw(15) << " " << "Press Enter to Exit...";
						role = 0;
						leaving = true;
						waitforenter();
					}
				} while (passwordInput != password && attempt < 3);
			}

			// If account does not exist,
			char acctChoice;
			if (!userFound) {
				cout << endl << endl << endl;
				cout << setw(15) << " " << "Account Not Found or Does Not Exist." << endl;
				cout << setw(15) << " " << "Would You Like to Create An Account? (Y/N) : ";
				cin >> acctChoice;

				// Account creation
				char usernameChoice;
				if (acctChoice == 'y') {
					cout << "\033c" << endl << endl;
					cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
					cout << setw(15) << " " << "║" << setw(48) << "║" << endl;
					cout << setw(15) << " " << "║" << setw(33) << "Barnett & Co. Banking" << setw(15) << "║" << endl;
					cout << setw(15) << " " << "║" << setw(30) << "Account Creation" << setw(18) << "║" << endl;
					cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl << endl;

					cout << setw(15) << " " << "You Entered The Username    :  " << username << endl;
					cout << setw(15) << " " << "Is This Correct? (y/n)      :  ";
					cin.ignore();
					getyn(usernameChoice);
					if (usernameChoice == 'n') {
						cout << endl <<  setw(15) << " " << "Please Enter a New Username :  ";
						getline(cin, username);
					}

					// Password
					cout << endl << setw(15) << " " << "Please Create a Password    :  "; // Add password obfuscation to hide characters
					password = hidePass(); // password obfuscation function

					attempt = 0;
					string passwordCheck;

					do {
						cout << endl << setw(15) << " " << "Confirm Password            :  ";
						passwordCheck = hidePass(); // password obfuscation function

						if (passwordCheck != password) {
							attempt++;
							cout << endl << endl << setw(15) << " " << "Password Does Not Match. Attempt " << attempt << "/3. Please Try Again." << endl << endl;
						}
						if (attempt == 3) {
							cout << setw(15) << " " << "Too Many Failed Attempts!" << endl;
							cout << setw(15) << " " << "Press Enter to Exit...";
							leaving = true;
							waitforenter();
						}
					} while (passwordCheck != password && attempt < 3);

					cout << "\033c" << endl << endl;
					cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
					cout << setw(15) << " " << "║" << setw(48) << "║" << endl;
					cout << setw(15) << " " << "║" << setw(33) << "Barnett & Co. Banking" << setw(15) << "║" << endl;
					cout << setw(15) << " " << "║" << setw(30) << "Account Creation" << setw(18) << "║" << endl;
					cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl << endl;


					// Name
					cout << endl << endl << setw(15) << " " << "Please Enter Last Name  :  ";
					getline(cin, lastName);
					cout << endl << setw(15) << " " << "Please Enter First Name :  ";
					getline(cin, firstName);

					// Role assignment
					cout << endl << endl << endl << endl;
					cout << setw(15) << " " << "What Type of Account is This?" << endl << endl;
					cout << setw(15) << " " << "Please Enter The Number Value." << endl << endl << endl;
					cout << setw(15) << " " << "        1. Client" << endl;
					cout << setw(15) << " " << "        2. Clerk" << endl;
					cout << setw(15) << " " << "        3. Manager" << endl;
					cout << setw(15) << " " << "        4. Admin" << endl << endl << endl;

					cout << setw(15) << " " << "Choice : ";
					cin >> role;
					cout << endl;

					int pinMaster = 1234;
					int pinInput = 0;
					attempt = 0;

					switch (role) {
						case 1: // Client
							break;
						case 2: // Clerk
							do {
								cout << setw(15) << " " << "Enter PIN For Clerk Security Clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << setw(15) << " " << "PIN Accepted. Role Set to Clerk. Press Enter to Continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << setw(15) << " " << "Invalid PIN. Attempt " << attempt << "/3. Try Again." << endl << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << setw(15) << " " << "Access Denied. Role Set to Client. Press Enter to Continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						case 3: // Manager
							do {
								cout << setw(15) << " " << "Enter PIN For Manager Security Clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << setw(15) << " " << "PIN Accepted. Role Set to Manager. Press Enter to Continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << setw(15) << " " << "Invalid PIN. Attempt " << attempt << "/3. Try Again." << endl << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << setw(15) << " " << "Access Denied. Role Set to Client. Press Enter to Continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						case 4: // Admin
							do {
								cout << setw(15) << " " << "Enter PIN For Admin Security Clearance: ";
								cin >> pinInput;
								if (pinInput == pinMaster) {
									cout << "PIN Accepted. Role Set to Admin. Press Enter to Continue..." << endl;
									leaving = true;
									waitforenter();
									break;
								} else {
									attempt++;
									cout << setw(15) << " " << "Invalid PIN. Attempt " << attempt << "/3. Try Again." << endl << endl;
								}
								if (pinInput != pinMaster && attempt == 3) {
									cout << setw(15) << " " << "Access Denied. Role Set to Client. Press Enter to Continue..." << endl;
									role = 1;
									leaving = true;
									waitforenter();
									break;
								}
							} while (pinInput != pinMaster && attempt < 3);
							break;
						default:
							cout << setw(15) << " " << "Invalid Choice. Role Set to Client. Press Enter to Continue..." << endl;
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

					misc.userChanged = user.username; // sets for log
					log('C'); // logs user creations

				} else if (acctChoice == 'n') {
					cout << setw(15) << " " << "Press enter to exit...";
					leaving = true;
					waitforenter();
				}
			}								// End bracket for user account creation
	} while (!leaving);
	log('L'); // LOGIN LOG
	return role;
}
