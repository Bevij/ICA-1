#include "header.h"
#include "helpers.h"

// entire file consists of smaller helper functions, in order to make inputs more consistent





/******************************************************************************************************
 *    AGILE SPECIFIC FUNCTIONS
 ******************************************************************************************************/

string randomNum() {
	int cycles = 0;
	int randNum = 0;
	time_t seconds = time(NULL);
	string filename;

	bool leaving = false;

	do
	{
		srand((unsigned) seconds * (cycles + 27)); // setting seed
		randNum = (10000 + rand() % 90000);			 // seting range and gets rand number
		filename = to_string(randNum);           	 // puts into string

		ifstream filein(filename);

		if(!filein) // checks if file exists, if it doesn't, this is a valid account to make
			leaving = true;

		cycles++;
	}while(!leaving);

	return filename;
}






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





/**********************************************************************************************************
 *   OTHER !!!! (just stuff ig)
 **********************************************************************************************************/

string timeString(int t) { // t in seconds, returns string for representation of t
	int years;
	int months;
	int days;
	int hours;
	int minutes;
	int seconds;

	string out = "";
	bool list;
	int temp = 0;
	bool prev;


	years = t / 31536000;
	t     = t % 31536000;
	months = t / 2592000;
	t      = t % 2592000;
	days = t / 86400;
	t    = t % 86400;
	hours = t / 3600;
	t     = t % 3600;
	minutes = t / 60;
	t       = t % 60;
	seconds = t;

	if(years)
		temp++;
	if(months)
		temp++;
	if(days)
		temp++;
	if(hours)
		temp++;
	if(minutes)
		temp++;
	if(seconds)
		temp++;
	if(temp > 2)
		list = true;


	if(years)
	{
		out += to_string(years) + " year";
		if(years != 1)
			out += 's';
		if(list && (months || days || hours || minutes || seconds))
			out += ',';
		out += ' ';
		prev = true;
	}

	if(months)
	{
		if((prev) && !(days || hours || minutes || seconds)) // if its the last thing, and something came before it
			out += "and ";
		out += to_string(months) + " month";
		if(months != 1) // if plural
			out += 's';
		if(list && (days || hours || minutes || seconds)) // if its a list (needing commas) and theres more items after this one
			out += ',';
		out += ' ';
		prev = true;
	}

	if(days)
	{
		if((prev) && !(hours || minutes || seconds))
			out += "and ";
		out += to_string(days) + " day";
		if(days != 1)
			out += 's';
		if(list && (hours || minutes || seconds))
			out += ',';
		out += ' ';
		prev = true;
	}

	if(hours) // NEED TO ADD CHECK FOR HIGHER STUFF BEFORE OUTPUTTING AND
	{
		if((prev) && !(minutes || seconds))
			out += "and ";
		out += to_string(hours) + " hour";
		if(hours != 1)
			out += 's';
		if(list && (minutes || seconds))
			out += ',';
		out += ' ';
		prev = true;
	}


	if(minutes)
	{
		if((prev) && !(seconds))
			out += "and ";
		out += to_string(minutes) + " minute";
		if(minutes != 1)
			out += 's';
		if(list && seconds)
			out += ',';
		out += ' ';
		prev = true;
	}

	if(seconds)
	{
		if(prev)
			out += "and ";
		out += to_string(seconds) + " second";
		if(seconds != 1)
			out += 's';
	}

	if(temp = 0)
		out = "0 seconds";

	return out;
}
