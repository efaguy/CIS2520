Name: Eric Faguy 0968958
Description: Takes a file by command line argument and add all the words to a hash table, allows the user to add and remove words from the table, print out all the words in the table, and check a file based on the table.
Hash function: The hash function take the string as the key and converts each letter to its respective number(i.e. A = 1, B = 2, etc) then adds the frist letter, substracts the second, multiplies the third and then divides the fourth(if its not zero) then repeats this sequence until all letter have been used, it then modulo this number by the table size to get ihe index.
Collision resolutin strategy: For collision the program goes to the the index then if the current node has data goes to the next node until in finds an empty node then places the data there. 
Running make program will compile into a executable called program in the bin directory.
Running make test will compile the test main into a executable called test in the bin directroy.
