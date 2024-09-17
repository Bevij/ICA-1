#include "header.h"

//             exact filename, string to find,       string to replace find with
void fileEdit(string filename, string strReplace,    string strNew) {

	fs::path p = fs::current_path(); // try to use later... ignore for now


	string tempfilename; // will be filename + ".temp"
	tempfilename = filename + ".temp";


	ifstream filein(filename); // filein is now basically cin, but in a file

	if(!filein) { // if fail to open file, display error message
		cout << "error opening file\n";
		cin >> tempfilename; //throwaway line
		return;
	}

	cout << "opened '" << filename << "'\n";


	ofstream fileout(tempfilename); // fileout is now like cout, but to a file
	cout << "created '" << tempfilename << "'\n";


	string strTemp;
	bool found = false;


	while(filein >> strTemp) // copies line by line everything form original file, replacing the first instance of replacemend line it finds
	{//if read line == string to replace AND hasnt already replaced someting beforehand
		if(strTemp == strReplace && !found) { // remove !found to replace every instance
			strTemp = strNew;
			found = true;
			cout << "replaced string in temp file\n";
		}
		fileout << strTemp << '\n'; //writes each line to new file
	}

	if(!found)
		cout << "error: could not find string to replace";

	// removes old file and replaces it
	fs::remove(filename);
	fs::rename(tempfilename, filename);

	return;
}
