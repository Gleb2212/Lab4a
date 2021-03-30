#include <malloc.h>
#include <stdbool.h>

typedef struct Item{
    char *info;
    int key1;
    int key2;
}Item;

typedef struct KeySpace1{
    struct Item *info;
    struct KeySpace1 *next;
}KeySpace1;

typedef struct KeySpace2{
    int release;
    struct Item *info;
    struct KeySpace2 *next;
}KeySpace2;

typedef struct Table{
    int size;
    int max_size;
    struct KeySpace1 *ks1;
    struct KeySpace2 **ks2;
}Table;

int hash(int, int);

int add_item(Table *table, int key1, int key2, char *);

int find(Table *table, int key, int ks);