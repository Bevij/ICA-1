#ifndef header_H
#define header_H

//    INITIALIZING AND INCLUSIONS OF ENTIRE PROGRAM

// EVERYTHING TO INCLUDE SHOULD BE ONLY IN THIS HEADER FILE, SO AS NOT TO REPEATEDLY INCLUDE THE SAME LIBRARY
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// note that these need to be in order of inheritance (ex: bankAccountType should be ABOVE checkingAccountType) (NEVERMIND)
#include "bankAccountType.h"

#include "checkingAccountType.h"
#include "serviceChargeCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "highInterestCheckingType.h"

#include "certificateOfDepositType.h"

#include "savingsAccountType.h"
#include "highInterestSavingsType.h"


//     END OF INITIALIZATIONS



//    GENERAL FUNCTION DECLARATION
void createMenu();
void viewMenu();
void editMenu();
void removeMenu();


//     CONST/GLOBAL VARIABLE DECLARATIONS
const int ARRAYSIZE = 20;

#endif
