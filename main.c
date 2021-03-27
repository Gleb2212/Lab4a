#include <stdio.h>
#include "table/table.h"
#include "dialog/dialog.h"

int main()
{
    struct Table table = {0, 8, NULL, NULL};
    int rc;
/*    while(rc = dialog(msgs, NMsgs))
        if(!fptr[rc](&table))
            break;*/
    printf("That's all. Bye!\n");
    delTable(&table);
    return 0;
}