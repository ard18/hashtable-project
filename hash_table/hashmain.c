#include "hashtable.h"

#define MAX_LINE 4096

char *linearSearch(hash_table *ht, char *key) {
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

int main(){
	printf("%d",1);
	char *filename = "40k_words.txt";

	uint64_t tablesize = 40000;
	hash_table *table = hash_table_create(tablesize);

	FILE *ptr = fopen(filename, "r");
	if(ptr==NULL) {printf("File couldn't be opened!!"); exit(-1);}
	char buffer[MAX_LINE];
	int numwords = 0;
	while(!feof(ptr) && fgets(buffer, MAX_LINE, ptr) != NULL){
		buffer[strcspn(buffer,"\n\r")] = 0;
		char *newentry = malloc(strlen(buffer)+1);
		strcpy(newentry, buffer);
		hash_table_insert(table, newentry);
		numwords++;
	}
	fclose(ptr);

	hash_table_print(table);

	char searchword[MAX_LINE];
	printf("Enter word to be searched:");
	scanf("%s",searchword);
	printf("%s\n", searchword);
	searchword[strcspn(searchword,"\n\r")] = 0;

	// Let's measure the time
	clock_t start, end;
    double cpu_time_used1, cpu_time_used2;

    start = clock();
 	char *result = hash_table_lookup(table, searchword);
    if(result){
        printf("Word found in hash = %s\n", result);
    } else {
        printf("Word not found in hash!!\n");
    }
    end = clock();
    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Hash Table Lookup Time: %f seconds\n", cpu_time_used1);

    start = clock();
    char *result2 = linearSearch(table, searchword);
    if(result2){
        printf("Word found in linearSearch = %s\n", result);
    } else {
        printf("Word not found in linearSearch!!\n");
    }
    end = clock();
    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("linearSearch Lookup Time: %f seconds\n", cpu_time_used2);

    double diff = ((cpu_time_used2-cpu_time_used1)/cpu_time_used2);
    printf("Speed-up in time to search = %lf\n",diff*100);
}