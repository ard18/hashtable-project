#include "hashtable.h"

int hash(char *name, int length){
	int hash_val = 0;
	for(int i=0; i<length; i++)
	{
		hash_val += name[i];
		hash_val = (hash_val*name[i]) ;
	}
	return hash_val;
}

static int hash_table_index(hash_table *ht, char *key){
	int result = (hash(key, strlen(key))%ht->size);
	return result;
}

hash_table *hash_table_create(uint64_t size){
	hash_table *ht = malloc(sizeof(*ht));
	ht->size = size;
	ht->elements = calloc(sizeof(entry*), ht->size); 
	return ht;
}

void hash_table_print(hash_table *ht){
	printf("Start Table\n");
	for(int i = 0; i < ht->size; i++){
		if(ht->elements[i]==NULL){
			printf("%i\t---\n",i);
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

bool hash_table_insert(hash_table *ht, char *key){
	if(key == NULL || ht == NULL) return false;
	int index = hash_table_index(ht, key);

	if (hash_table_lookup(ht, key) != NULL) return false;

	entry *e = malloc(sizeof(*e));
	e->key = malloc(strlen(key)+1);
	strcpy(e->key, key);

	// insert entry
	e->next = ht->elements[index];
	ht->elements[index] = e;
	return true;
}

char *hash_table_lookup(hash_table *ht, char *key){
	if(key == NULL || ht == NULL) return false;
	int index = hash_table_index(ht, key);

	entry *tmp = ht->elements[index];
	while(tmp!=NULL && strcmp(tmp->key, key) != 0){
		tmp = tmp->next;
	}
	if(tmp==NULL) return NULL;
	return tmp->key;
}