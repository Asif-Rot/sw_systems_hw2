# makefile

all: mains maind myBanks myBankd

myBanks: libmyBank.a

libmyBank.a: myBank.o myBank.h
	ar -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	gcc -Wall -fPIC -c myBank.c

myBankd: libmyBank.so

libmyBank.so: myBank.o myBank.h
	gcc -shared -o libmyBank.so myBank.o

mains: main.o libmyBank.a 
	gcc -Wall -o mains main.o libmyBank.a   

main.o: main.c
	gcc -Wall -c main.c

maind: main.o libmyBank.so
	gcc -Wall -o maind main.o ./libmyBank.so

.PHONY: clean all myBanks myBankd

clean:
	rm -f *.o *.a *.so mains maind