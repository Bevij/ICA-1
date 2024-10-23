#include "header.h"

void log(const char& log) {
	fs::path filePath = "./Data/Logs/Actions/";

	string out;
	time_t timeee = time(NULL);


	switch(log)
	{
		case 'L': // loginss
		{
			filePath += "Logins";
			break;
		}
		case 'l': // "logouts
		{
			filePath += "Logouts";
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
		case 'p': // bad password
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



	ofstream foutAction(filePath, ios::app); // app is APPEND, which is just write to EOF
	foutAction << log << endl;
	foutAction << timeee << endl;
	foutAction << user.username << endl;
	foutAction << out;
	foutAction.flush();
	foutAction.close();


	fs::path filePathUsers = "./Data/Logs/Users/" + user.username;

	ofstream foutUser(filePathUsers, ios::app);
	foutUser << log << endl;
	foutUser << timeee << endl;
	foutUser << user.username << endl;
	foutUser << out;
	foutUser.flush();
	foutUser.close();

	fs::path filePathMaster = "./Data/Logs/Master";

	ofstream foutMaster(filePathMaster, ios::app);
	foutMaster << log << endl;
	foutMaster << timeee << endl;
	foutMaster << user.username << endl;
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
