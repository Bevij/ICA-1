#include "header.h"


/*
there is a security feature in this file, as it can remove any file typed in, including cpp
files and stuff. we will need restrictions later
*/


void removeMenu(){

	string filename;
	string temp;

	cout << "What account would you like to delete? ";

	getline(cin, filename);

	fs::remove(filename);

	cout << "\n'" << filename << "' successfully removed\n";
	cout << "Press enter to continue.....";

	waitforenter();

	return;
}

