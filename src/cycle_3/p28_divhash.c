#include <stdio.h>
#define MAX_SIZE 1000

int main() {
	int table_size, key, hash, choice = 1;
	int hash_table[MAX_SIZE] = {0};
	
	printf("Enter the hash table size: ");
	scanf("%d", &table_size);
	while (choice == 1) {
		printf("\nEnter the key value: ");
		scanf("%d", &key);
		hash = key % table_size;
		if (hash_table[hash] == 0) {
			hash_table[hash] = key;
			printf("Key %d is hashed to %d\n", key, hash);
		} else {
			printf("Hash collision occurred\n");
		}
		printf("\nHash another key? (1 Yes / 0 No): ");
		scanf("%d", &choice);
	}
	return 0;
}