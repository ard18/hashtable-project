/*
211217
Arrnav Dutta
functions file for the hashtable project
*/
#include "hashtable.h"

// function definitions
// ----------------------------------------------------------------------------------------------------------------
int hash(char *name, int length){							// compute hash value for the word given the word size
	int hash_val = 0;
	for(int i=0; i<length; i++)
	{
		hash_val += name[i];
		hash_val = (hash_val*name[i]) ;

	}
	return hash_val;
}
// ----------------------------------------------------------------------------------------------------------------
static int hash_table_index(hash_table *ht, char *key){		// compute hashtable index based on hash value
	int result = (hash(key, strlen(key))%ht->size);
	return result;
}
// ----------------------------------------------------------------------------------------------------------------
hash_table *hash_table_create(uint64_t size){				// create a hashtable given the table size
	hash_table *ht = malloc(sizeof(*ht));
	if(ht==NULL){
		printf("Space not allocated for hashtable!");
		return NULL;
	}
	ht->size = size;
	ht->elements = calloc(sizeof(entry*), ht->size); 
	if(ht->elements==NULL){
		printf("Space not allocated for hashtable elements!");
		return NULL;
	}
	return ht;
}
// ----------------------------------------------------------------------------------------------------------------
void hash_table_print(hash_table *ht){						// display all the elements of the hashtable
	printf("Start Table\n");
	for(int i = 0; i < ht->size; i++){
		if(ht->elements[i]==NULL){
			//printf("%i\t---\n",i); 						// for displaying the empty nodes/elements. Uncomment at your own risk
		} else{
			printf("%i\t",i);
			entry *tmp = ht->elements[i];
			while(tmp!=NULL){
				printf("\"%s\" ", tmp->key);
				tmp = tmp->next;
			}
			printf("\n"); 
		}
	}
	printf("End Table\n"); 
}
// ----------------------------------------------------------------------------------------------------------------
bool hash_table_insert(hash_table *ht, char *key){ 			// insert a word into the hashtable
	if(key == NULL || ht == NULL) return false;
	int index = hash_table_index(ht, key);					// compute the index of the word

	if (hash_table_lookup(ht, key) != NULL) return false; 	// don't enter words already in the hashtable

	entry *e = malloc(sizeof(*e));							// new element node
	if(e==NULL){
		printf("Space not allocated for element of hashtable!");
		return 0;
	}
	e->key = malloc(strlen(key)+1);							// value of element node
	if(e->key==NULL){
		printf("Space not allocated for value of element in hashtable!");
		return 0;
	}
	strcpy(e->key, key);

	// insert entry
	e->next = ht->elements[index];							// linking the new node to the original linked list
	ht->elements[index] = e;
	return true;
}
// ----------------------------------------------------------------------------------------------------------------
char *hash_table_lookup(hash_table *ht, char *key){			// look for a word in the hashtable
	if(key == NULL || ht == NULL) return false;	
	int index = hash_table_index(ht, key);

	entry *tmp = ht->elements[index];
	while(tmp!=NULL && strcmp(tmp->key, key) != 0){			// in case of collision,
		tmp = tmp->next;									// search through all the nodes in the linked list element
	}
	if(tmp==NULL) return NULL;
	return tmp->key;
}
// ----------------------------------------------------------------------------------------------------------------
char *linearSearch(hash_table *ht, char *key) {				// look for a word in the hashtable using linear search
    entry *tmp;
    for (int i = 0; i < ht->size; i++) {
    	tmp = ht->elements[i];
    	while(tmp!=NULL && strcmp(tmp->key, key)!=0){
    		tmp=tmp->next;
    	}
    	if(tmp!=NULL){
    		return tmp->key;
    	}
    }
    return NULL;

}
// ----------------------------------------------------------------------------------------------------------------