#ifndef menuType_H
#define menuType_H
#include "bankAccountType.h"
using namespace std;

const int ARRAYSIZE= 20;
void createMenu(bankAccountType accountList[ARRAYSIZE], int accountCount);
void viewMenu(bankAccountType accountList[ARRAYSIZE], int accountCount);
void editMenu(bankAccountType accountList[ARRAYSIZE], int accountCount);
void removeMenu(bankAccountType accountList[ARRAYSIZE], int accountCount);


#endif