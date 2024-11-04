#include "header.h"

void log(const char& log) {

	fs::path filePath = "./Data/Logs/Actions/";

	string out;               // out is the ENTIRE string to output
	bool bankAccountRelevant = false;



	// every log has the log type, the time of log, and the username who took the action
	out += getTime();
	out += '\n';
	out += user.username;
	out += '\n';
	out += log;
	out += '\n';

	switch(log)
	{
		case 'L': // loginss
		{
			filePath += "Logins";
			break;
		}
		case 'l': // "logouts (in same file as logins)
		{
			filePath += "Logins";
			break;
		}
		case 'C': // user creations
		{
			filePath += "UserCreates";
			out += misc.userChanged;
			out += '\n';
			break;
		}
		case 'D': // user deletions
		{
			filePath += "UserDeletes";
			out += misc.userChanged;
			out += '\n';
			break;
		}
		case 'b': // bad password
		{
			filePath += "BadPasswords";
			break;
		}
		case 'e': // bank account edit (by admin or clerk)
		{
			filePath += "Edits";
			out += misc.bankAccount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 'v': // bank account view
		{
			filePath += "Views";
			out += misc.bankAccount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 'd': // deposits
		{
			filePath += "Deposits";
			out += misc.amount;
			out += '\n';
			out += misc.bankAccount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 'w': // withdraws
		{
			filePath += "Withdraws";
			out += misc.amount;
			out += '\n';
			out += misc.bankAccount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 't': // Transfers
		{
			filePath += "Transfers";
			out += misc.amount;
			out += '\n';
			out += misc.bankAccount; // FROM 1
			out += '\n';
			out += misc.bankAccount2; // TO 2
			out += '\n';
			bankAccountRelevant = true;

			fs::path filePathBankAccount2 = "./Data/Logs/Accounts/" + misc.bankAccount2;
			// as there are TWO bank accounts, an extra action is needed to print log to the second
			ofstream foutBankAccount2(filePathBankAccount2, ios::app);
			foutBankAccount2 << out;
			foutBankAccount2.flush();
			foutBankAccount2.close();

			break;
		}
		case 'o': // Overrides
		{
			filePath += "Overrides";
			out += misc.overriddenUser;
			out += '\n';
			out += misc.bankAccount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		default:
			cout << "Uhhhhhh thats not right....\nMight wanna check something...?\nin log.cpp file";
			waitforenter();
	};// end log switch




	ofstream foutAction(filePath, ios::app); // ios::app is APPEND, which is just write to EOF
	foutAction << out; // out is the entire thing to output to file
	foutAction.flush(); // flush makes it write
	foutAction.close(); // closing for fun teehee


	fs::path filePathUsers = "./Data/Logs/Users/" + user.username;

	ofstream foutUser(filePathUsers, ios::app);
	foutUser << out;
	foutUser.flush();
	foutUser.close();

	fs::path filePathMaster = "./Data/Logs/Master";

	ofstream foutMaster(filePathMaster, ios::app);
	foutMaster << out;
	foutMaster.flush();
	foutMaster.close();


	if(bankAccountRelevant)
	{
		fs::path filePathAccounts = "./Data/Logs/Accounts/" + misc.bankAccount;

		ofstream foutAccounts(filePathAccounts, ios::app);
		foutAccounts << out;
		foutAccounts.flush();
		foutAccounts.close();
	}



	misc.userChanged = "";
	misc.bankAccount = "";
	misc.bankAccount2 = "";
	misc.amount = "";
	misc.overriddenUser = "";
	return;
}



void logMenu()
{
	bool leaving = false;
	char choice;
	fs::path filePath;

	while(!leaving)
	{
		wipescreen();
		cout << "\n\n";
		cout << setw(15) << " " << "╔═════════════════════════════════════════════╗" << endl;
		cout << setw(15) << " " << "║                                             ║" << endl;
		cout << setw(15) << " " << "║                  Log Menu                   ║" << endl;
		cout << setw(15) << " " << "╚═════════════════════════════════════════════╝" << endl;
		cout << setw(15) << " " << "┌─────────────────────────────────────────────┐" << endl;
		cout << setw(15) << " " << "│     Logged in as : " << setw(25) << left << user.username.substr(0, 24) << "│" << endl;
		cout << setw(15) << " " << "├─────────────────────────────────────────────┤" << endl;
		cout << setw(15) << " " << "│                                             │" << endl;
		cout << setw(15) << " " << "│     1.  Master Log                          │" << endl;
		cout << setw(15) << " " << "│     2.  User Logs         (Directory)       │" << endl;
		cout << setw(15) << " " << "│      .  Bank Account Logs (Directory)       │" << endl;
		cout << setw(15) << " " << "│     4.  Action Logs       (Directory)       │" << endl;
//		cout << setw(15) << " " << "│      .  Error Logs                          │" << endl;
		cout << setw(15) << " " << "│     0.  Exit                                │" << endl;
		cout << setw(15) << " " << "└─────────────────────────────────────────────┘" << endl;
		cout << "\n\n\n" <<        "               ";

		getchar(choice);

		switch(choice)
		{
			case '0':
			{
				leaving = true;
				break;
			}
			case '1':
			{
				filePath = "./Data/Logs/Master"; // immediately call Master from here, later
				logView(filePath, "MASTER");
				break;
			}
			case '2':
			{
				filePath = "./Data/Logs/Users"; // NOT WORKING, NEED SEARCH FOR USERS AND STUFF
				logView(filePath, "USER");
				break;
			}
			case '3':
			{
				leaving = true;
				break;
			}
			case '4':
			{
				filePath = "./Data/Logs/Actions";
				logView(filePath, "ACTIONS");
				break;
			}
			case '5':
			{
				leaving = true;
				break;
			}
		}// end main switch
	}// end while(!leaving)


/**************************************TEMPORARY!!! FIX LATER!!!!!******************************************************************

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
*/


}


void logView(const fs::path& path, const string& logName) // calls logOutputConstructor to make the strings in its vector, lists them
{
	bool leaving = false;
	vector<string> out;
	int i;
	char input;
	bool nextPagePossible = false;
	bool previousPagePossible = false;

	logOutputConstruct(path, out); // gets entire vector of strings to output


	int numPages = (out.size() / 10);
	int pageCurrent = 0; // technically page + 1

	int extraSpaceToFill = (10 - (out.size() % 10));
	if(extraSpaceToFill == 10)
	{
		extraSpaceToFill = 0;
		numPages--;
	}
	for(extraSpaceToFill; extraSpaceToFill > 0; extraSpaceToFill--)
		out.push_back("");



	if(out.size() == 0)
	{
		leaving = true;
		cout << "No logs exist, exiting log view...";
		waitforenter();
	}

	while(!leaving)
	{
		i = pageCurrent * 10;

		nextPagePossible     = (pageCurrent < numPages);
		previousPagePossible = (pageCurrent > 0);

		wipescreen();
		cout << "\n\n" << left;
		cout << "┌───────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
		cout << "│     Logged in as : " << setw(75) << user.username    <<                                      "│" << endl;
		cout << "│     Viewing Log  : " << setw(75) << logName + " LOG" <<                                      "│" << endl;
		cout << "├───────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
		cout << "│ {  DATE  } { TIME }  {   USERNAME   } {                      ACTION                        }  │" << endl;
		cout << "├───────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "│ " << setw(94) << out[i++].substr(0, 92) <<                                                   "│" << endl;
		cout << "├───────────────────────────────────────────────────────────────────────────────────────────────┤" << endl;
		cout << "│     PAGE:" << setw(3) << right << pageCurrent+1 << '/' << left << setw(81) << numPages+1 <<  "│" << endl;
		if(nextPagePossible)
			cout << "│     {ENTER} to go to next page                                                                │" << endl;
		else
			cout << "│     {ENTER} to return to menu                                                                 │" << endl;
		if(previousPagePossible)
			cout << "│     ' p '   to go to previous page                                                            │" << endl;
		cout << "│     ' 0 '   to return to menu                                                                 │" << endl;
		cout << "└───────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;

		cin.get(input);
		if(input != '\n')
		{
			cin.ignore(10000, '\n');
			if(input == '0')
				leaving = true;
			else if(input == 'p' && previousPagePossible)
				pageCurrent -= 2;
		} else if(!nextPagePossible) // if enter was pressed and next page isnt possible, return to menu
			leaving = true;
		pageCurrent++;

	}// end main loop
}


class stopConstructing{};
void logOutputConstruct(const fs::path& path, vector<string>& out)
{
	ifstream fin(path);
	string sout;

	string tdate;
	string ttime;
	string username;
	char c;
	string temp; // 37

	try // exists only to exit right on EOF
	{
		bool leaving = false;
		while(!leaving)
		{
			fin >> tdate;
			if(!fin)
				throw stopConstructing();
			fin >> ttime;
			fin >> username;
			fin >> c;


			sout = tdate + ' ' + ttime + ": " + username;

			for(int i = sout.length(); i < 38; i++)
				sout += ' ';

			switch(c)
			{
				case 'L':
				{
					sout += "Logged in.";
					break;
				}
				case 'l':
				{
					sout += "Logged out.";
					break;
				}
				case 'C':
				{
					sout += "Created a user account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'D':
				{
					sout += "Deleted a user account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'b':
				{
					sout += "Had a BAD PASSWORD";
					break;
				}
				case 'e':
				{
					sout += "Edited bank account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'v':
				{
					sout += "Viewed bank account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'd': // reorder
				{
					sout += "Deposited $";
					fin >> temp;
					sout += temp;
					sout += " into bank account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'w': // reorder
				{
					sout += "Withdrew $";
					fin >> temp;
					sout += temp;
					sout += " from bank account : ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 't': // Transfers
				{
					sout += "Transferred $";
					fin >> temp;
					sout += temp;
					sout += " from bank account : ";
					fin >> temp;
					sout += temp;
					sout += "to ";
					fin >> temp;
					sout += temp;
					break;
				}
				case 'o': // Overrides
				{
					sout += "Overrode ";
					fin >> temp;
					sout += temp;
					sout += "'s edit of bank account : ";
					fin >> temp;
					sout += temp;
					break;
				}

				default:
				{
					sout += "Hmmmm thats not right, check the file";
				}
			};// end switch
		out.insert(out.begin(), sout);
		}// end main while loop



	}// end try
	catch(stopConstructing e)
	{
		"Stopped constucting";
	}

}
