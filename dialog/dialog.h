#include <stdio.h>
#include "../table/table.h"

const char *errmsgs[] = {"Ok", "Duplicate key", "Table overflow"};
const char *msgs[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show"}; //список альтернатив для меню
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
int dialog(const char *msgs[], int); //функция реализующая меню
int getInt(int *); //получение числа из входного потока
int d_add(struct Table *); //вызывает функцию вставки элемента в таблицу
int d_find(struct Table *); //вызывает функцию поиска в таблице
int d_delete(struct Table *); //вызывает функцию удаления из таблицы
int d_show(struct Table *); //вызывает функцию вывода содержимого таблицы
int (*fptr[])(struct Table *) = {NULL, d_add, d_find, d_delete, d_show};
char *getStr(); //ввод строки
void delTable(struct Table *table);