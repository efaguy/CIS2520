CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -c

program: bin/BinarySearchTreeAPI.o bin/rule.o bin/main.o
	$(CC) bin/BinarySearchTreeAPI.o bin/rule.o bin/main.o -o bin/program
	 
bin/BinarySearchTreeAPI.o: src/BinarySearchTreeAPI.c
	$(CC) $(CFLAGS) src/BinarySearchTreeAPI.c -o bin/BinarySearchTreeAPI.o
	
bin/rule.o: src/rule.c
	$(CC) $(CFLAGS) src/rule.c -o bin/rule.o
	
bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o 
	
test: bin/BinarySearchTreeAPI.o bin/rule.o bin/testmain.o
	$(CC) bin/BinarySearchTreeAPI.o bin/rule.o bin/testmain.o -o bin/test

bin/testmain.o: src/testmain.c
	$(CC) $(CFLAGS) src/testmain.c -o bin/testmain.o 
	
clean :
	rm bin/*.o bin/program bin/test

cls :
	clear

readme :
	more README.txt
