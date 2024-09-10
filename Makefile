CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = mainmenu.o viewmenu.o createmenu.o editmenu.o removemenu.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o 

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

mainmenu.o: mainmenu.cpp createmenu.o viewmenu.o editmenu.o removemenu.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o mainmenu.cpp menu.h viewmenu.cpp editmenu.cpp removemenu.cpp

viewmenu.o: viewmenu.cpp menu.h

createmenu.o: createmenu.cpp menu.h

editmenu.o: editmenu.cpp menu.h

removemenu.o: removemenu.cpp menu.h

highInterestSavingsType.o: highInterestSavingsType.cpp highInterestSavingsType.h bankAccountType.o savingsAccountType.o

savingsAccountType.o: savingsAccountType.cpp savingsAccountType.h bankAccountType.o

certificateOfDepositType.o: certificateOfDepositType.cpp certificateOfDepositType.h bankAccountType.o

bankAccountType.o: bankAccountType.cpp bankAccountType.h

serviceChargeCheckingType.o: serviceChargeCheckingType.cpp serviceChargeCheckingType.h checkingAccountType.o

highInterestCheckingType.o: highInterestCheckingType.cpp highInterestCheckingType.h noServiceChargeCheckingType.o

noServiceChargeCheckingType.o: noServiceChargeCheckingType.cpp noServiceChargeCheckingType.h checkingAccountType.o

checkingAccountType.o: checkingAccountType.cpp checkingAccountType.h bankAccountType.o



clean:
	rm -f run *.o *~
