CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -c

program: bin/patient.o bin/LinkedListAPI.o bin/PriorityQueue.o bin/main.o
	$(CC) bin/patient.o bin/LinkedListAPI.o bin/PriorityQueue.o bin/main.o -o bin/program
	 
bin/patient.o: src/patient.c
	$(CC) $(CFLAGS) src/patient.c -o bin/patient.o

bin/LinkedListAPI.o: src/LinkedListAPI.c
	$(CC) $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o
	
bin/PriorityQueue.o: src/PriorityQueue.c
	$(CC) $(CFLAGS) src/PriorityQueue.c -o bin/PriorityQueue.o

bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o 
	
test: bin/patient.o bin/LinkedListAPI.o bin/PriorityQueue.o bin/testmain.o
	$(CC) bin/patient.o bin/LinkedListAPI.o	bin/PriorityQueue.o bin/testmain.o -o bin/test

bin/testmain.o: src/testmain.c
	$(CC) $(CFLAGS) src/testmain.c -o bin/testmain.o 
	
clean :
	rm bin/*.o bin/program bin/test

cls :
	clear

readme :
	more README.txt
