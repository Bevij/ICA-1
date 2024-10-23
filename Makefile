CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = mainmenu.cpp log.o update.o hidePass.o loginmenu.o viewmenu.o createmenu.o viewsubmenus.o editmenu.o helpers.o removemenu.o editsubmenus.o editLogin.o deposit.o withdraw.o transfer.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o 

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

log.o: log.cpp header.h

update.o: update.cpp header.h

hidePass.o: hidePass.cpp header.h

loginmenu.o: loginmenu.cpp header.h

// searchaccounts.o: searchAccounts.cpp header.h

viewmenu.o: viewmenu.cpp header.h

viewsubmenus.o: viewsubmenus.cpp header.h

createmenu.o: createmenu.cpp header.h

editmenu.o: editmenu.cpp header.h

editsubmenus.o: editsubmenus.cpp header.h

removemenu.o: removemenu.cpp header.h

randomnum.o: randomnum.cpp helpers.h

helpers.o: helpers.cpp helpers.h header.h

editLogin.o: editLogin.cpp header.h

deposit.o: deposit.cpp header.h

withdraw.o: withdraw.cpp header.h

transfer.o: transfer.cpp header.h




highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h savingsAccountType.o

savingsAccountType.o: savingsAccountType.cpp savingsAccountType.h bankAccountType.o


certificateOfDepositType.o: certificateOfDepositType.cpp certificateOfDepositType.h bankAccountType.o


highInterestCheckingType.o: highInterestCheckingType.cpp highInterestCheckingType.h noServiceChargeCheckingType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h checkingAccountType.o

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h checkingAccountType.o

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h bankAccountType.o


bankAccountType.o: bankAccountType.cpp bankAccountType.h header.h



clean:
	rm -f run *.o *~
