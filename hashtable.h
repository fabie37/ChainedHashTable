#include <stdio.h>
#include <stdlib.h>
#define HASH_TABLE_SIZE 10

typedef struct hashtable HashTable;
typedef struct hashnode HashNode;

// Hash Table Implementation

/*
 * search_key: searches for a key in the table
 * return: key success, -1 failure
 */
int search_key(HashTable *hashtable, int key);

/*
 * add_key: adds key to hashtable
 * return: 1 success, 0 failure 
 */
int add_key(HashTable *hashtable, int key);

/*
 * remove_key: removes key form hashtable
 * return: void
 */
void remove_key(HashTable *hashtable, int key);

/*
 * create_table: creates a new hashtable
 * return: pointer to new hashtable allocated in heap
 */
HashTable *create_table();

/*
 * delete_table: deletes a hashtable
 * return: void
 */
void delete_table(HashTable *hashtable);

/*
 * create_hashnode: creates a new node for linked list
 * return: pointer to allocated heap space
 */
HashNode *create_hashnode(int key);

/*
 * delete_hashnode: frees a node
 * return: the next node it was pointing to
 */
HashNode *delete_hashnode(HashNode *node);

/*
 * hash_function: given an input, give key
 * return: a key given input
 */
int hash_function(int x);