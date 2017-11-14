Name: Eric Faguy 0968958
Description: Takes a file by command line argument and add all the words to a hash table, allows the user to add and remove words from the table, print out all the words in the table, and check a file based on the table.
Hash function: The hash function take the string as the key, adds each letters ASCI number to the key Num, it then modulo this number by the table size to get the index.
Collision resolutin strategy: For collision I chose to use seperate chaining, so the program goes to the the index then if the current node already has data in it goes to the next node until in finds an empty node then places the data there. 
Running make program will compile into a executable called program in the bin directory.
Running make test will compile the test main into a executable called test in the bin directroy.
