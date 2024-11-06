#ifndef header_H
#define header_H




//    INITIALIZING AND INCLUSIONS OF ENTIRE PROGRAM

// EVERYTHING TO INCLUDE SHOULD BE ONLY IN THIS HEADER FILE, SO AS NOT TO REPEATEDLY INCLUDE THE SAME LIBRARY
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>												// includes time in seconds from 1970, time_t = time(NULL);
#include <cstdlib>
#include <filesystem>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <sstream>
// password hiding libraries
#include <termios.h>
#include <unistd.h>


using namespace std;
namespace fs = filesystem;



struct loginInfo // info of user
{
	string username;
	string password;
	string lastName;
	string firstName;
	int role;
	// vector<string> accounts; // list of all accounts for user
};
extern loginInfo user;


struct miscInfo
{
	// all listed things for logging, just strings to pass as arguments
	string userChanged;
	string bankAccount;
	string bankAccount2;
	int amount;
	string overriddenUser;
};
extern miscInfo misc;






#include "helpers.h" // generally input helper functions

// inclusion of all classes, for use in general menu and other CPP files
#include "bankAccountType.h"

#include "checkingAccountType.h"
#include "serviceChargeCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "highInterestCheckingType.h"

#include "certificateOfDepositType.h"

#include "savingsAccountType.h"
#include "highInterestSavingsType.h"




//    GENERAL FUNCTION DECLARATION
string hidePass();
int loginMenu();
void createMenu();
void viewMenu();
void editMenu();
void removeMenu();
void createAccountFile();
void deleteAccountFile();
void viewAccountFile();
double deposit(char acctType, string filename, double amount);
void depositMenu();
void withdraw();
void editLogin();
void transfer();
string randomNum();
void log(const char&);
void logMenu();
void logView(const fs::path&, const string&);
void logOutputConstruct(const fs::path&, vector<string>&);
void getSubPath(fs::path&);
void getActionPath(fs::path&);




//     CONST/GLOBAL VARIABLE DECLARATIONS
const int ARRAYSIZE = 30;
const int FILENAMESIZE = 70;
const int OVERRIDE_TIME = 120;

//     GLOBAL EMPTY CLASSES FOR TRY/THROW/CATCH BLOCKS
class cantFind {};
class deadlock {};
class abortOverride {};
class abortView {};
class invalidAmount {};
class fileStructureInvalid {};

#endif

