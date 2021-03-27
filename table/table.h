#include <stdio.h>

typedef struct Item{
    char *info;
}Item;

typedef struct KeySpace1{
    int key;
    int par;
    struct Item *info;
    struct KeySpace1 *next;
}KeySpace1;

typedef struct KeySpace2{
    int key;
    int release;
    struct Item *info;
    struct KeySpace2 *next;
}KeySpace2;

typedef struct Table{
    int size;
    int max_size;
    struct KeySpace1 *ks1;
    struct KeySpace2 *ks2;
}Table;