#include <stdio.h>
#include <malloc.h>
#include "../table/table.h"
#include <string.h>


int dialog(const char *msgs[], int); //функция реализующая меню
int getInt(int *); //получение числа из входного потока
int d_add( Table *); //вызывает функцию вставки элемента в таблицу
int d_find( Table *); //вызывает функцию поиска в таблице
int d_delete( Table *); //вызывает функцию удаления из таблицы
int d_show_ks1(Table *); //вызывает функцию вывода содержимого таблицы
int d_show_ks2(Table *); //вызывает функцию вывода содержимого таблицы
char *getStr(); //ввод строки
void delTable( Table *);
