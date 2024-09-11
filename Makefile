CFLAGS = -Wall -Werror -Wpedantic -std=c++20 -O0 -g
CC = g++

OBJECTS = mainmenu.o viewmenu.o createmenu.o editmenu.o removemenu.o bankAccountType.o savingsAccountType.o highInterestSavingsType.o certificateOfDepositType.o serviceChargeCheckingType.o checkingAccountType.o noServiceChargeCheckingType.o highInterestCheckingType.o 

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

mainmenu.o: mainmenu.cpp *.o



viewmenu.o: viewmenu.cpp *o

createmenu.o: createmenu.cpp *o

editmenu.o: editmenu.cpp *o

removemenu.o: removemenu.cpp *o


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
