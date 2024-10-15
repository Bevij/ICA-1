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

using namespace std;
namespace fs = filesystem;


#include "helpers.h" // generally input helper functions

// inclusion of all classes, for use in general menu and other CPP files
#include "bankAccountType.h"

#include "checkingAccountType.h"
#include "serviceChargeCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "highInterestCheckingType.h"

#include "certificateOfDepositType.h"

exe#include "savingsAccountType.h"
#include "highInterestSavingsType.h"




//    GENERAL FUNCTION DECLARATION
void loginMenu();
void createMenu();
void viewMenu();
void editMenu();
void removeMenu();
void createAccountFile();
void deleteAccountFile();
void viewAccountFile();
void deposit();
void withdraw();
void editLogin();
void transfer();
string randomNum();



struct loginInfo
{
	char role;
	string username;
	string fname;
	string lname;
	vector<string> accounts; // list of all accounts for user
};
extern loginInfo user;


//     CONST/GLOBAL VARIABLE DECLARATIONS
const int ARRAYSIZE = 30;
const int FILENAMESIZE = 70;

#endif

