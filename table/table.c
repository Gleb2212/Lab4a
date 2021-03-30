#include "table.h"

int hash(int key, int size) {
    return (key % size);
}

int add_item(Table *table, int key1, int key2, char *info) {
    Item *ptr = (Item *) calloc(1, sizeof(Item));
    ptr->info = info;
    ptr->key1 = key1;
    ptr->key2 = key2;
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

bool find(Table *table, int key, int ks) {
    struct KeySpace1 *ptr1 = table->ks1;
    if (ks == 1) {
        while (ptr1 != NULL) {
            if (key == ptr1->info->key1)
                return true;
            ptr1 = ptr1->next;
        }
    } else if (ks == 2) {
        for (int i = 0; i < table->max_size; i++) {
            struct KeySpace2 *ptr;
            if (table->ks2[i] != NULL) {
                ptr = table->ks2[i];
                while (ptr != NULL) {
                    if (key == ptr->info->key2)
                        return true;
                    ptr = ptr->next;
                }
            }
        }
    }
    return false;
}
