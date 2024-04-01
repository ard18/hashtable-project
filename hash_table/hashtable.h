#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct _hash_table hash_table;
typedef struct entry{
	char *key; 
	struct entry *next;
} entry;

typedef struct _hash_table{
	uint64_t size;
	entry **elements;
} hash_table;

int hash(char *name, int length);
hash_table *hash_table_create(uint64_t size);
void hash_table_print(hash_table *ht);
bool hash_table_insert(hash_table *ht, char *key);
char *hash_table_lookup(hash_table *ht, char *key);

#endif