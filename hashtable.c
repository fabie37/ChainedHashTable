
#include "hashtable.h"

typedef struct hashnode {
	struct hashnode *next;
	int key;
} HashNode;

typedef struct hashtable {
	HashNode *table[HASH_TABLE_SIZE];
} HashTable;

/*
 *
 * Hash Table Functions
 * 
*/

int search_key(HashTable *hashtable, int key) {
	int hash = hash_function(key);
	HashNode *node = hashtable->table[hash];
	if (node == NULL) {
		return -1;
	} else {
		while (node != NULL) {
			if (node->key == key) {return node->key;}
			node = node->next;
		}
	}
	return -1;
}


int add_key(HashTable *hashtable, int key) {
	int hash = hash_function(key);
	HashNode *x = hashtable->table[hash];

	if (x == NULL) {
		HashNode *node = create_hashnode(key);
		if (node == NULL) {return 0;}
		hashtable->table[hash] = node;
	} else {
		while (x->key != key && (x->next) != NULL) { x = x->next;}
		if (x->next == NULL && x->key != key) {		
			HashNode *node = create_hashnode(key);
			if (node == NULL) {return 0;}
			x->next = node;
		}
		else if (x->key == key) {return 1;}
	}
	return 1;
}

void remove_key(HashTable *hashtable, int key) {
	int hash = hash_function(key);
	HashNode *node = hashtable->table[hash];
	HashNode *prev = NULL;
	if (node == NULL) {return;}
	while (node != NULL) {
		if (node->key == key) {
			if (prev != NULL) {
				prev->next = delete_hashnode(node);
			} else {
				hashtable->table[hash] = delete_hashnode(node);
			}
			break;
		}
		prev = node;
		node = node->next;
	}
}

HashTable *create_table() {
	HashTable *new_table = (HashTable *) malloc(sizeof(HashTable));
	if (new_table != NULL) {
		for (int i=0; i<HASH_TABLE_SIZE; i++) {new_table->table[i] = NULL;}
	}
	return new_table;
}

void delete_table(HashTable *hashtable) {
	if (hashtable == NULL) { return; }
	for (int i=0; i<HASH_TABLE_SIZE;  i++) {
		HashNode *node = hashtable->table[i];
		while (node != NULL) {
			node = delete_hashnode(node);
		}
	}
	free(hashtable);
}

/*
 *
 * Hash Node Functions
 * 
*/

HashNode *create_hashnode(int key) {
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	if (node != NULL) {
		node->key = key;
		node->next = NULL;
	}
	return node;
}

HashNode *delete_hashnode(HashNode *node) {
	if (node == NULL) {return NULL;}
	HashNode *next = node->next;
	free(node);
	return next;
}

/*
 *
 * Hashing Functions 
 * 
*/ 

int hash_function(int x) {
	return x%HASH_TABLE_SIZE;
}