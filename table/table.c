#include "table.h"

int hash(int key, int size) {
    return (key % size);
}

int add_item(Table *table, int key1, int key2, char *info) {
    Item *ptr = (Item *) calloc(1, sizeof(Item));
    ptr->info = info;
    ptr->key1 = key1;
    ptr->key2 = key2;
    //add in the first ks
    if (table->ks1 == NULL) {
        table->ks1 = (KeySpace1 *) calloc(1, sizeof(KeySpace1));
        table->ks1->info = ptr;
    } else {
        struct KeySpace1 *temp = table->ks1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (struct KeySpace1 *) calloc(1, sizeof(struct KeySpace1));
        temp->next->info = ptr;
    }
    int index = hash(key2, table->max_size);
    if (table->ks2[index] == NULL) {
        table->ks2[index] = (struct KeySpace2 *) calloc(1, sizeof(struct KeySpace2));
        table->ks2[index]->release = 1;
        table->ks2[index]->info = ptr;
    } else {
        struct KeySpace2 *temp = table->ks2[index];
        table->ks2[index] = (struct KeySpace2 *) calloc(1, sizeof(struct KeySpace2));
        table->ks2[index]->next = temp;
        table->ks2[index]->release = temp->release + 1;
        table->ks2[index]->info = ptr;
    }
    table->size++;
}

int find(Table *table, int key, int ks) {
    return -1; //index если нашел, -1 если не нашел
}