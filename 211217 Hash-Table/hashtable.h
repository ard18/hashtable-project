/*
211217
Arrnav Dutta
header file for the hashtable project
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// we use external chaining in this hashtable to handle collisions
// Basically, elements of the hashtable will be linked lists (single)
// so, one element can contain more than one values
// Here value is a word or string

// struct variable for the elements of the hashtable
typedef struct entry{
	char *key; 			// value of the element
	struct entry *next; // pointer to next value of element of table
} entry;

// struct variable for the hashtable itself
typedef struct _hash_table{
	uint64_t size; 		// we take the size as a uint64_t variable to store large number sizes like 30,000 or 40,000
	entry **elements; 	// double pointer to point to the elements
} hash_table;

// function declarations
int hash(char *name, int length);					// calculate the hash value of a given input given the input size
hash_table *hash_table_create(uint64_t size);		// create a hashtable of given size
void hash_table_print(hash_table *ht);				// display (print) all the elements of the hashtable
bool hash_table_insert(hash_table *ht, char *key);	// insert a value into the hashtable
char *hash_table_lookup(hash_table *ht, char *key);	// search for a value in the hashtable
char *linearSearch(hash_table *ht, char *key);		// perform linear search on the hashtable for a given value

#endif