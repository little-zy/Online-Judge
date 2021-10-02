#include <stdio.h>
#include <stdlib.h>
typedef struct listnode {
    int data;
    struct listnode* next;
} List;
typedef List* L;
int main() {
    int n, i;
    scanf("%d", &n);
    L head, insert, tmp, a;
    head= (L)malloc(sizeof(List));
    scanf("%d", &head->data);
    head->next= insert= (L)malloc(sizeof(List));
    for (i= 1; i < n; i++) {
        scanf("%d", &insert->data);
        tmp= insert;
        insert->next= (L)malloc(sizeof(List));  //! 注意顺序
        insert= insert->next;
    }
    tmp->next= NULL;
    insert= (L)malloc(sizeof(List));
    scanf("%d", &insert->data);
    tmp= head;
    while (tmp != NULL && tmp->data < insert->data) {
        a= tmp;
        tmp= tmp->next;
    }
    a->next= insert;
    insert->next= tmp;
    tmp= head;
    while (tmp != NULL) {  //!
        printf("%d", tmp->data);
        tmp= tmp->next;
    }
    while (head != NULL) {
        tmp= head;
        head= head->next;
        free(tmp);
    }
}
