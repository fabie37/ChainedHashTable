#include "hashtable.h"
#include <stdio.h>
#include <assert.h>

void add_key_test(HashTable *table);
void remove_key_test(HashTable *table);

int main() {

    HashTable *table = create_table();
    add_key_test(table);
    remove_key_test(table);
    delete_table(table);
}

void add_key_test(HashTable *table) {
    for (int i=0; i<100; i++) {
        add_key(table, i);
        printf("Is %d in table? %d\n", i, search_key(table, i));
        assert(i == search_key(table,i));
    }
}

void remove_key_test(HashTable *table) {
    add_key_test(table);
    for (int i=0; i<100; i++) {
        remove_key(table, i);
        printf("Is %d removed from table? %d\n", i, search_key(table, i));
        assert(-1 == search_key(table,i));
    }
}