/*
211217
Arrnav Dutta
main file for the hashtable project
*/
#include "hashtable.h"

#define MAX_LINE_LEN 4096 // maximum length of a line in the file

// main function
int main(int argc, char* argv[]){

	int c = 1;
	int flag;
	while(c) {

		printf("Enter your choice: 1 for small table(size 50), 2 for Large Table(size 30000), 3 for exit: ");
		scanf("%d",&flag);
		if(flag==1)
		{
			uint64_t tablesize = 50; 										// Let's take the case where our table size is 50 (small table size)
			hash_table *table1 = hash_table_create(tablesize);				// create a hashtable

			FILE *ptr = fopen(argv[1], "r"); 								// open the text file
			if(ptr==NULL) {
				printf("File couldn't be opened!! Specify the file name in the command line.\n");
				exit(-1);
			}

			char buffer[MAX_LINE_LEN]; 										// variable that stores words from the file
			int numwords = 0; 												// variable for # of words
			while(!feof(ptr) && fgets(buffer, MAX_LINE_LEN, ptr) != NULL){ 	// insert the words in the file into the hashtable
				buffer[strcspn(buffer,"\n\r")] = 0; 						// remove the ending newline or carriage return character if present.
				char *newentry = malloc(strlen(buffer)+1); 					// store contents of buffer and put this into the hashtable
				if(newentry==NULL) {
					printf("Space couldn't be allocated!!");
					exit(-1);
				}
				strcpy(newentry, buffer);
				hash_table_insert(table1, newentry); 						// insert word into hashtable
				numwords++;
			}
			fclose(ptr);

			printf("Small Table:\n\n");
			hash_table_print(table1); 										// display contents of the hashtable
			printf("This is a small Table\n\n");

			char searchword[MAX_LINE_LEN]; 									// variable for storing word to be searched
			printf("Enter word to be searched:");
			scanf("%s",searchword);
			printf("%s\n", searchword);
			searchword[strcspn(searchword,"\n\r")] = 0; 					// removing newline or carriage return if present

			// Let's measure the time
			clock_t start, end;
		    double cpu_time_used1, cpu_time_used2;

		    // hashtable lookup
		    start = clock(); 												// start the clock
		 	char *result = hash_table_lookup(table1, searchword); 			// search for the word using hashtable
		    if(result){
		        printf("Word found in hash = %s\n", result);
		    } else {
		        printf("Word not found in hash!!\n");
		    }
		    end = clock(); 													// end the clock
		    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC; 	// time taken for execution
		    printf("Hash Table Lookup Time: %f seconds\n\n", cpu_time_used1);

		    // linear search lookup
		    start = clock(); // start the clock
		    char *result2 = linearSearch(table1, searchword); 				// search for the word using linear search
		    if(result2){
		        printf("Word found in linearSearch = %s\n", result);
		    } else {
		        printf("Word not found in linearSearch!!\n");
		    }
		    end = clock(); 													// end the clock
		    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC; 	// time taken for execution
		    printf("linearSearch Lookup Time: %f seconds\n\n", cpu_time_used2);

		    double diff = ((cpu_time_used2-cpu_time_used1)/cpu_time_used2); // percentage difference in time to search 
		    printf("Percentage change in time to search = %lf\n\n",diff*100);
		    if(diff>0)
		    	printf("Hashtable outperformed Linear Search with a lower search time.\n\n");
		    else
		    	printf("Linear Search outperformed Hashtable with a lower search time.\n\n");
		}

		else if(flag==2)
		{
		    uint64_t tablesize = 30000; 											// Let's take the case where our table size is 30000 (large table size)
			hash_table *table2 = hash_table_create(tablesize); 			// create a hashtable

			FILE* ptr = fopen(argv[2], "r"); 									// open the text file
			if(ptr==NULL) {
				printf("File couldn't be opened!! Specify the file name in the command line.\n");
				exit(-1);
			}

			char buffer[MAX_LINE_LEN]; 								// variable that stores words from the file
			int numwords = 0; 												// variable for # of words
			while(!feof(ptr) && fgets(buffer, MAX_LINE_LEN, ptr) != NULL){ 	// insert the words in the file into the hashtable
				buffer[strcspn(buffer,"\n\r")] = 0; 						// remove the ending newline or carriage return character if present.
				char *newentry = malloc(strlen(buffer)+1);					// store contents of buffer and put this into the hashtable
				if(newentry==NULL) {
					printf("Space couldn't be allocated!!");
					exit(-1);
				}
				strcpy(newentry, buffer);
				hash_table_insert(table2, newentry); 						// insert word into hashtable
				numwords++;	
			}
			fclose(ptr);

			printf("Large Table:\n");
			hash_table_print(table2); 										// display contents of the hashtable
			printf("This is a very Large Table\n\n");

			char searchword[MAX_LINE_LEN]; 								// variable for storing word to be searched
			printf("Enter word to be searched:");
			scanf("%s",searchword);
			printf("%s\n", searchword);
			searchword[strcspn(searchword,"\n\r")] = 0; 					// removing newline or carriage return if present

			// Let's measure the time
			clock_t start, end;
		    double cpu_time_used1, cpu_time_used2;

		    // hashtable lookup
		    start = clock(); // start the clock
		 	char* result = hash_table_lookup(table2, searchword); 				// search for the word using hashtable
		    if(result){
		        printf("Word found in hash = %s\n", result);
		    } else {
		        printf("Word not found in hash!!\n");
		    }
		    end = clock(); // end the clock
		    cpu_time_used1 = ((double) (end - start)) / CLOCKS_PER_SEC; 	// time taken for execution
		    printf("Hash Table Lookup Time: %f seconds\n\n", cpu_time_used1);

		    // linear search lookup
		    start = clock(); // start the clock
		    char* result2 = linearSearch(table2, searchword); 					// search for the word using linear search
		    if(result2){
		        printf("Word found in linearSearch = %s\n", result);
		    } else {
		        printf("Word not found in linearSearch!!\n");
		    }
		    end = clock(); // end the clock
		    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC; 	// time taken for execution
		    printf("linearSearch Lookup Time: %f seconds\n\n", cpu_time_used2);

		    double diff = ((cpu_time_used2-cpu_time_used1)/cpu_time_used2);		// percentage difference in time to search
		    printf("Percentage change in time to search = %lf\n\n",diff*100);

		    if(diff>0)
	    		printf("Hashtable outperformed Linear Search with a lower search time.\n\n");
	    	else
	    		printf("Linear Search outperformed Hashtable with a lower search time.\n\n");
		}

		else{
			break;
		}
	}
}