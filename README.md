# hashtable-project
This is a C project undertaken at the undergraduate level. 
 
Header File:	hashtable.h
Functions File: hashtable.c
Main File:		hashmain.c

In this project, we implement hash tables in C.
Hash table is a data structure where we store key-value pairs.
It is useful when we want to quicken the process of searching, inserting and deleting elements.
Here we only implement searching and inserting of words or strings.

The insertion and search of a word occurs based on the hash value computed by the hash function.
The hash function is the soul of the hash table. 
It determines the index of the table where the word needs to inserted or searched for.
Here, we use a simple hash function.
Let's see an example to understand the hash function:

Take the word "ABC". The hash value is calculated like so: 

Let h = 0. We traverse through the word, where at each iteration we add the ascii value of the letter 
and then multiply the sum with the ascii value. 

So, in the first iteration, h becomes: h => 0+65 (ascii of A) => 65*65.

Second iteration, h becomes: h => 65*65 + 66 (ascii of B) => 65*65*66 + 66*66.

Third iteration, h becomes: h => 65*65*66 + 66*66 + 67 (ascii of C) => 65*65*66*67 + 66*66*67 + 67*67.

Finally our hash value for "ABC" is h = 18979291, and assuming our table size is 50,
our index in the hash table is = 18979291 % 50 = 41. 

Often, the hash function gives the same hash value for different words. This situation is called a collision.
To handle these collisions, several methods have been developed, out of which the external chaining method
is used here. This involves using linked lists as the elements of the hash table. 
Whenever a collision occurs, the new word is linked to the original linked list via a new linked list 
node at that index.  

We have 2 text files: Sample.txt and 40k_words.txt
Sample.txt contains 17 words and 40k_words.txt contains 40,000 randomly generated words.

We take 2 cases:
Case 1: small # words, i.e., we use the Sample.txt and our table size is 50
Case 2: large # words, i.e., we use the 40k_words.txt and our table size is 30000.
We compare and contrast the time taken by a hash table and a linear search algorithm
to search for a word entered by the user.

When executing the executable file, this should be the format of the command:
./<your_executable_filename> Sample.txt 40k_words.txt
