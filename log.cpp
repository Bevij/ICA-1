#include "header.h"

void log(const char& log) {

	fs::path filePath = "./Data/Logs/Actions/";

	string out;               // out is the ENTIRE string to output
	time_t t = time(NULL);
	bool bankAccountRelevant = false;



	// every log has the log type, the time of log, and the username who took the action
	out += log;
	out += '\n';
	out += to_string(t);
	out += '\n';
	out += user.username;
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
			out += misc.bankAccount;
			out += '\n';
			out += misc.amount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 'w': // withdraws
		{
			filePath += "Withdraws";
			out += misc.bankAccount;
			out += '\n';
			out += misc.amount;
			out += '\n';
			bankAccountRelevant = true;
			break;
		}
		case 't': // Transfers
		{
			filePath += "Transfers";
			out += misc.bankAccount; // FROM 1
			out += '\n';
			out += misc.bankAccount2; // TO 2
			out += '\n';
			out += misc.amount;
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
		fs::path filePathAccounts = "./Data/Logs/Accounts" + misc.bankAccount;

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
		cout << setw(15) << " " << "│      .  Error Logs                          │" << endl;
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
				logView(filePath);
				break;
			}
			case '2':
			{
				leaving = true;
				break;
			}
			case '3':
			{
				leaving = true;
				break;
			}
			case '4':
			{
				leaving = true;
				break;
			}
			case '5':
			{
				leaving = true;
				break;
			}
		}// end main switch
	}// end while(!leaving)
}

void logOutConstruct(const fs::path& path, vector<string>& out)
{
	// will create vector of strings based off of which file it finds
	out[0] = "0th thing yay";
	out[1] = "1st thing yayyyy";
	out[2] = "2nd thing yayyyyyyyyy";
}



void logView(const fs::path& path) // calls something to make the strings in its vector, lists them
{
	vector<string> out;

	logOutConstruct(path, out);

	cout << out.size() << out[0] << out[1];

	waitforenter();
}


