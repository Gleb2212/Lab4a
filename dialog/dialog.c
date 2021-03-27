#include "dialog.h"
#include "../table/table.h"
#include <malloc.h>
#include <string.h>

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



int d_add(struct Table *ptab)
{
    int k, rc, n;
    char *info = NULL;
    printf("Enter key: -->");
    n = getInt(&k);
    if(n == 0)
        return 0;
    printf("Enter info:\n");
    info = getStr();
    if (info == NULL)
        return 0;
    //TODO
    free(info);
    printf("%s: %d\n", errmsgs[rc], k);
    return 1;
}

void delTable(struct Table *table){

}