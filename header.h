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

using namespace std;

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
void createMenu();
void viewMenu();
void editMenu();
void removeMenu();
int randomNum();


//     CONST/GLOBAL VARIABLE DECLARATIONS
const int ARRAYSIZE = 20;

#endif
