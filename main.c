#include "dialog/dialog.h"
const char *msgs[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show"}; //список альтернатив для меню
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
const int MAX_SIZE = 10;

int main()
{
    int (*fun[])(Table *) = {NULL, d_add, d_find, d_delete, d_show};
    Table table = {0, MAX_SIZE, NULL, (KeySpace2 *)calloc(MAX_SIZE, sizeof(KeySpace2))};
    int rc;
    while(rc = dialog(msgs, NMsgs))
        if(!fun[rc](&table))
            break;
    printf("That's all. Bye!\n");
    delTable(&table);
    return 0;
}