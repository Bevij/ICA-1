#include "header.h"

fs::path searchbynum(const string& acctNumSearch) {
	fs::path acctPath;

	// Specify directory
	fs::path dir = "./Data/Accounts/";

	// Recursive Search
	for (const auto& entry : fs::recursive_directory_iterator(dir)) {
		if (fs::is_regular_file(entry.path())) {
			if (entry.path().filename() == acctNumSearch) {
				acctPath = entry.path();
				//acctPath += acctNumSearch;
				break;
			}
		}
	}
return acctPath;
}



string searchbypath(const fs::path& acctPathSearch)
{
	return acctPathSearch.filename();
}
