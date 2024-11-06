#include "header.h"

void editLogin()
{
	string username, passwordInput, password, lastName, firstName, roleString;
	char choice,role;
	bool leaving = false;
	bool flag = false;
	cout << "\033c" << right;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "      User Edit 						      ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : ";
		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
			}
		}		// End Switch
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;
		cout<<"What user would you like to Edit?"<<endl;
		cin>> username;
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

	    		
		
			}
		
		do{
			cout << "\033c" << right;
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(18) << "║" << setw(19) << " " << setw(29) << "║" << endl;
		cout << setw(18) << "║" << "      USER LOGIN EDIT     ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24)<< "│" << right << endl;
		cout << setw(15) << " " << "│     User Role    : ";
		// Switch for role selection

		switch(user.role)
		{
			case 1:
			{
				cout << setw(25) << "Client" << "│" << endl;
			}
			case 2:
			{
				cout << setw(25) << "Clerk" << "│" << endl;
			}
			case 3:
			{
				cout << setw(25) << "Manager" << "│" << endl;
			}
			case 4:
			{
				cout << setw(25) << "Admin" << "│" << endl;
			}
			default:
			{
				cout << setw(25) << "ERROR" << "│" << endl;
			}
		}		// End Switch
		
		cout << setw(18) << "│" << setw(19) << " "                    << setw(29) << "│" << endl;	
		cout << setw(18) << "│" << setw(25) << "1.  User Name          : " << setw(20) << left << user.username << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "2.  Password      : " << setw(20) << left << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "3.  Last Name : " << setw(20) << left << user.lastName << "│" << endl << right;
		cout << setw(18) << "│" << setw(25) << "4.  First Name    : " << setw(20) << left << user.firstName << "│" << endl << right;
		cout << setw(18) << "│" << setw(22) << "5.  Role :"    << setw(26) << left<< user.role<<"│" << endl;
		cout << setw(18) << "│" << setw(22) << "0.  SAVE & EXIT"    << setw(26) << left<<"│" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl << endl << endl;
		cin>>choice;
		cin.ignore();
		switch(choice){
			case'1':
				{cout<<"What would you like to change the User Name to"<<endl;
				getline(cin,username);
				break;}
			case'2':
				{cout<<"What would you like to change the Password to"<<endl;
				password= hidePass();
				break;}
			case'3':{
				cout<<"What would you like to change the Last Name to"<<endl;
				getline(cin,lastName);
				break;}
			case'4':{
				cout<<"What would you like to change the First Name to"<<endl;
				getline(cin,firstName);
				break;}
			case'5':{
			
					cout << setw(15) << " " << "What would you like to change the role to?" << endl << endl;
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
					int attempt = 0;

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
			break;}
			case'0':{
			flag=true;
			break;}
			default:
			cout<<" Error Invalid Choice Please insert Correct Option"<<endl;
		}
		fs::path dirUserSearch = "./Data/Users";
			fs::path filePath;
		ofstream userFile(user.username);
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
		}while(flag!=true);
					

		
	return;}
