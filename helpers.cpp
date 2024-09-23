#include "header.h"
#include "helpers.h"

// entire file consists of smaller helper functions, in order to make inputs more consistent





/******************************************************************************************************
 *    AGILE SPECIFIC FUNCTIONS
 ******************************************************************************************************/








/**********************************************************************************************************
 *   INPUT HELPERS / SOME FORMATTING
 **********************************************************************************************************/

void wipescreen() {
//	cout << "\033[H\033[J";
	cout << "\033c";
}

void getchar(char &input) {
	cin.get(input);

	while(input == '\n') { // note: this makes it REJECT if all it gets is a newline character
		cout << "Please enter a valid character: ";
		cin.get(input);
	}
	cin.ignore(10000, '\n');
	return;
}

void getyn(char &input) { // check for y/n input
	bool invalid;

	do {
		cin.get(input);
		input = tolower(input);
		invalid = (input != 'y' && input != 'n');
		if(invalid) {
			cout << "Invalid input! (y/n): ";
		}
		if(input != '\n') {
			cin.ignore(10000, '\n');
		}
	}while(invalid);
	return;
}

void getposint(int &input) { // only pos
	cin >> input;
	while(!cin || input < 0) {  // or while(cin.fail())
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a valid positive number: ";
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return;
}

void getsignedint(int &input) { // pos or neg
	cin >> input;
	while(!cin) {  // or while(cin.fail())
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a valid number: ";
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return;
}

void getposdouble(double &input) { // only pos
	cin >> input;
	while(!cin || input < 0) {  // or while(cin.fail())
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a valid positive number: ";
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return;
}

void getsigneddouble(double &input) { // pos or negative
	cin >> input;
	while(!cin) {  // or while(cin.fail())
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter a valid positive number: ";
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return;
}


string lowerstring(const string& str) { // returns lowercase version of string
	string lowerString = "";

	for(size_t i = 0; i < str.length(); i++)
		lowerString += tolower(str[1]);

	return lowerString;
}

string upperstring(const string& str) { // returns lowercase version of string
	string upperString = "";

	for(size_t i = 0; i < str.length(); i++)
		upperString += toupper(str[1]);

	return upperString;
}

void waitforenter() {
	char input;

	if(input != '\n')
		cin.ignore(10000, '\n');

	return;
}



/**********************************************************************************************************
 *   SORTERS AND STUFF (ALL ARRAY/VECTOR ONLY)
 **********************************************************************************************************/



/****************************************** NUMBERS!! *****************************************************/
void sortInt(int* list, const int& listLength) { // MUST BE AN ARRAY OF INTS (maybe a vector?)
	int i;
	int smallestIndex;
	int location;
	int tempInt;

	for(i = 0; i < (listLength - 1); i++) {
		smallestIndex = i;

		for(location = i + 1; location < listLength; location++) {
			if(list[location] < list[smallestIndex])
				smallestIndex = location;
		}

		tempInt = list[smallestIndex];
		list[smallestIndex] = list[i];
		list[i] = tempInt;
	}
	return;
}

int getSmallestInt(const int* list, const int& listLength) {
	int i;
	int smallestIndex = 0;

	for(i = 1; i < listLength - 1; i++)
		if(list[i] < list[smallestIndex])
			smallestIndex = i;

	return smallestIndex;
}

int getLargestInt(const int* list, const int& listLength) {
	int i;
	int largestIndex = 0;

	for(i = 1; i < listLength - 1; i++)
		if(list[i] > list[largestIndex])
			largestIndex = i;

	return largestIndex;
}


/****************************************** STRINGS!!! *****************************************************/
void sortString(string* list, const int& listLength) { // MUST BE AN ARRAY OF STRINGS (maybe a vector?)
	int i;
	int smallestIndex;
	int location;
	string tempString;

	for(i = 0; i < (listLength - 1); i++) {
		smallestIndex = i;

		for(location = i + 1; location < listLength; location++) {
			if(list[location] < list[smallestIndex])
				smallestIndex = location;
		}

		tempString = list[smallestIndex];
		list[smallestIndex] = list[i];
		list[i] = tempString;
	}
	return;
}
