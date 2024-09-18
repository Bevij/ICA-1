#ifndef helpers_H
#define helpers_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


// INPUT AND FORMATTING
void   wipescreen();                   // wipes the screen
void   getchar(char&);						// any char
void   getyn(char&);							// 'y' or 'n'
void   getposint(int&);						// positive valid int
void   getsignedint(int&);					// any      valid int
void   getposdouble(double&);				// positive valid float
void   getsigneddouble(double&);			// any      valid float

string lowerstring(const string&);		// returns lowercase string
string upperstring(const string&);		// returns uppercase string

void waitforenter();

// SORTERS
void sortInt(int* list, const int&);						// takes list, sorts it
int  getSmallestInt(const int* list, const int&);		// takes list, returns smallest index
int  getLargestInt(const int* list, const int&);		// takes list, returns largest index


#endif
