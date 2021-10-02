#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[3];
    int number;
    struct Student* next;
};
int count;
struct Student* creat();
struct Student* reverseList(struct Student* head);
// struct Student* turnover(struct Student* head);
void prin(struct Student*);
int main()
{
    struct Student* ptr;
    ptr= creat();
    ptr= reverseList(ptr);
    // ptr=turnover(ptr);
    prin(ptr);
    free(ptr);
    return 0;
}
struct Student* creat()
{
    struct Student *pHead, *pnext;
    int p1= 1;
    count= 0;
    pHead= (struct Student*)malloc(sizeof(struct Student));
    pnext= pHead;
    // puts("name:");
    // scanf("%s",&p_next->name);
    // puts("xuehao:");
    // scanf("%d",&p_next->number);
    // p_next->pnext=(struct Student*)malloc(sizeof(struct Student));
    // p_next=p_next->pnext;
    // count++;
    do {
        scanf("%s", &pnext->name);
        puts("xuehao:");
        scanf("%d", &pnext->number);
        p1= pnext->number;
        pnext->next= (struct Student*)malloc(sizeof(struct Student));
        pnext= pnext->next;
        count++;
        // todo :while(p_next->number);
    } while (p1);  //!错在这：跳不出来---1：
    // free(p_next->pnext);//!算了---2
    // todo 再试试
    pnext->next= NULL;
    pnext= NULL;
    free(pnext);
    return pHead;
}
struct Student* reverseList(struct Student* head)
{
    /* struct Student*output=(struct Student*)malloc(sizeof(struct Student));
    struct Student*p=head;struct Student*q;struct Student*temp;
    output->next=NULL;
    while(p!=NULL){
        temp=output->next;
        q=p->next;
        output->next=p;
        p->next=temp;
        p=q;
    }
    return output->next; */
    int total= count - 2;
    struct Student *p= head, *q= head->next;
    /* while(p->next!=NULL){
        total++;
        p=p->next;
    }
    p=head; */
    // head=head->next;
    // head->next=p;
    // p->next=NULL;
    p->next= NULL;
    while (total--) {
        head= q;
        q= q->next;
        head->next= p;
        p= head;
        //!关键在于看清变化后指针所指对象，不能影响下文
    }
    return head;
}
/* struct Student* turnover(struct Student* head){
    if(head==NULL||head->next==NULL)
    return head;
    struct Student*New_head;
    head->next->next=head;
    head->next=NULL;
    New_head=turnover(head);
    return New_head;
} */
void prin(struct Student* ptr)
{
    struct Student* ptr0;
    ptr0= ptr;
    int i= 1;
    printf("----the List has %d members:----\n", count - 1);
    while (--count) {
        printf("the NO.%d member is:\n", i);
        i++;
        printf("the name is: %s\n", ptr0->name);
        printf("the number is: %d\n", ptr0->number);
        ptr0= ptr0->next;
        puts("");
    }
}