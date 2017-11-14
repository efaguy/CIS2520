CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -c

program: bin/car.o bin/LinkedListAPI.o bin/main.o
	$(CC) bin/car.o bin/LinkedListAPI.o bin/main.o -o bin/program
	 
bin/car.o: src/car.c
	$(CC) $(CFLAGS) src/car.c -o bin/car.o

bin/LinkedListAPI.o: src/LinkedListAPI.c
	$(CC) $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o

bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o 
	
test: bin/car.o bin/LinkedListAPI.o bin/testmain.o
	$(CC) bin/car.o bin/LinkedListAPI.o bin/testmain.o -o bin/test

bin/testmain.o: src/testmain.c
	$(CC) $(CFLAGS) src/testmain.c -o bin/testmain.o 
	
clean :
	rm bin/*.o bin/program bin/test

cls :
	clear

readme :
	more README.txt
