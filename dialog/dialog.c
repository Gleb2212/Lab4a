#include "dialog.h"

const char *errmsgs[] = {"Ok", "Duplicate key", "Table overflow"};

char *getStr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do {
        n = scanf("%80[^\n]", buf); // n = scanf_s ("%80[^\n]", buf, 81);
        if (n < 0) {

            free(ptr);
            ptr = NULL;
            continue;

        }

        if (n == 0)

            scanf("%*c");

        else {

            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);

        }
    } while (n > 0);
    return ptr;
}

int getInt(int *a)
{
    int n;
    do{
        n = scanf_s("%d", a, sizeof(int));
        if (n < 0)
            return 0;
        if (n == 0){
            printf("%s\n", "Error! Repeat input");
            scanf_s("%*c", 0);
        }
    } while (n == 0);
    return 1;
}

int dialog(const char *msgs[], int N)
{
    char *errmsg = "";
    int rc;
    int i, n;
    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        for(i = 0; i < N; ++i)
            puts(msgs[i]);
        puts("Make your choice: --> ");
        n = getInt(&rc);
        if(n == 0)
            rc = 0;
    } while(rc < 0 || rc >= N);
    return rc;
}



int d_add(Table *table)
{
    int key1,key2, rc, n;
    char *info = NULL;
    printf("Enter key for 1st key space: -->");
    n = getInt(&key1);
    if(n == 0)
        return 0;
    printf("Enter key for 2d key space: -->");
    n = getInt(&key2);
    if(n == 0)
        return 0;
    printf("Enter info:\n");
    info = getStr();
    if (info == NULL)
        return 0;
    rc = add_item(table, key1, key2, &info);
    free(info);
    printf("%s: %d\n", errmsgs[rc], key1);
    return 1;
}

void delTable(Table *table){
    if(table->size > 0){
        while(table->ks1->next != NULL){
            struct KeySpace1 *ptr = table->ks1;
            table->ks1 = table->ks1->next;
            free(ptr->info->info);
            free(ptr->info);
            free(ptr);
        }
    }
    free(table->ks2);
}

int d_find( Table *table ){

    return 0;
}

int d_delete( Table *table ){

    return 0;
}

int d_show( Table *table ){

    return 0;
}
