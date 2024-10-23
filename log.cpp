#include "header.h"

void log(const char& log) {

	fs::path filePath = "./Data/Logs/Actions/";

	string out;               // out is the ENTIRE string to output
	time_t t = time(NULL);



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
			break;
		}
		case 'v': // bank account view
		{
			filePath += "Views";
			out += misc.bankAccount;
			out += '\n';
			break;
		}
		case 'd': // deposits
		{
			filePath += "Deposits";
			out += misc.bankAccount;
			out += '\n';
			out += misc.amount;
			out += '\n';
			break;
		}
		case 'w': // withdraws
		{
			filePath += "Withdraws";
			out += misc.bankAccount;
			out += '\n';
			out += misc.amount;
			out += '\n';
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
			break;
		}
		case 'o': // Overrides
		{
			filePath += "Overrides";
			out += misc.overriddenUser;
			out += '\n';
			out += misc.bankAccount;
			out += '\n';
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






	misc.userChanged = "";
	misc.bankAccount = "";
	misc.bankAccount2 = "";
	misc.amount = "";
	misc.overriddenUser = "";
	return;
}
