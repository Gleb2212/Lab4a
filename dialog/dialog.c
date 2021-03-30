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
        if (n > 0) {

            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);

        } else
            scanf("%*c");
    } while (n > 0);
    return ptr;
}

int getInt(int *a) {
    int n;
    do {
        n = scanf_s("%d", a, sizeof(int));
        if (n < 0)
            return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    scanf("%*c");
    return 1;
}

int dialog(const char *msgs[], int N) {
    char *errmsg = "";
    int rc;
    int i, n;
    do {
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        for (i = 0; i < N; ++i)
            puts(msgs[i]);
        printf("Make your choice: --> ");
        n = getInt(&rc);
        if (n == 0)
            rc = 0;
    } while (rc < 0 || rc >= N);
    return rc;
}

int d_add(Table *table) {
    int key1, key2, n;
    char *info = NULL;
    printf("Enter key for 1st key space: -->");
    n = getInt(&key1);
    if (n == 0)
        return 1;
    do {
        printf("Enter key for 2d key space: -->");
        n = getInt(&key2);
        if (n == 0)
            return 0;
    } while (key1 == key2);
    printf("Enter info: ");
    info = getStr();
    if (info == NULL)
        return 1;
    //TODO find
    add_item(table, key1, key2, info);
    return 1;
}

void delTable(Table *table) {
    if (table->size > 0) {
        while (table->ks1->next != NULL) {
            struct KeySpace1 *ptr = table->ks1;
            table->ks1 = table->ks1->next;
            free(ptr->info->info);
            free(ptr->info);
            free(ptr);
        }
    }
    //TODO пройтись по всему пространству и удалить все KeySpace2, которые мы выделяли

    free(table->ks2);
}

int d_find(Table *table) {
//какой ключ и в каком пространстве?
//TODO
    return 1;
}

int d_delete(Table *table) {
//какой ключ и в каком пространстве?
//TODO
    return 1;
}

int d_show_ks1(Table *table) {
    struct KeySpace1 *ptr = table->ks1;
    int i = 0;
    while (ptr != NULL) {
        printf("Index = [%d]\n\tKey 1 =  %d\n\tKey 2 = %d\n\tinfo = %s\n\t\n", i, ptr->info->key1, ptr->info->key2,
               ptr->info->info);
        ptr = ptr->next;
        i++;
    }
    return 1;
}

int d_show_ks2(Table *table) {
    KeySpace2 *ptr;
    for (int i = 0; i < table->max_size; i++) {
        if (table->ks2[i] != NULL) {
            printf("Index =[%d]\n", i);
            ptr = table->ks2[i];
            while (ptr != NULL) {
                printf("\tRelease = %d\n\tKey 1 =  %d\n\tKey 2 = %d\n\tinfo = %s\n\t\n", ptr->release, ptr->info->key1,
                       ptr->info->key2, ptr->info->info);
                ptr = ptr->next;
                i++;
            }
        }
    }
    return 1;
}
