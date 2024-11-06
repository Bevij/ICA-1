#include "header.h"

string searchAccountNum(const fs::path& acctNumSearch) {
	string acctPath;

	// Specify directory
	fs::path dir = "./Data/Accounts/";

	// Search Criteria
	bool accountFound = false;

	// Recursive Search
	for (const auto& entry : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(entry.path())) {
			if (entry.path() == acctPath;) {
				acctNum = entry.path().filename();
				accountFound = true;
				break;
			}
		}
	}
	if (!accountFound) {
		cout << "File not found or does not exist in parent directory or its subdirectories." << endl << endl;
	}
return acctNum;
}

fs::path searchAccounts(const string& acctPathSearch) {
	string acctNum;

	// Specify directory
	fs::path dir = acctPathSearch;

	// Search Criteria
	bool accountFound = false;

	// Recursive Search
	for (const auto& entry : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(entry.path())) {
			if (entry.path().filename() == acctPathSearch;) {
				acctPath = entry.path();
				accountFound = true;
				break;
			}
		}
	}
	if (!accountFound) {
		cout << "File not found or does not exist in parent directory or its subdirectories." << endl << endl;
	}
return acctPath;
}
