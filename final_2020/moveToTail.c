#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
}

void MoveToTail() {
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    struct node *ptr=head;
    struct node *maxNode;
    int max=-1;
    for(ptr;ptr!=NULL;ptr=ptr->next){
        if(ptr->val > max){
            maxNode=ptr;
            max=ptr->val;
        }
    }
    if(maxNode==tail) return;
    ptr=head;
    if(maxNode!=head && maxNode!=tail){
        for(ptr;ptr!=NULL;ptr=ptr->next){
            if(ptr->next==maxNode){
                ptr->next=maxNode->next;
                tail->next=maxNode;
                maxNode->next=NULL;
                tail=maxNode;
                break;
            }
        }
    }else if(maxNode==head){
        head=ptr->next;
        tail->next=maxNode;
        maxNode->next=NULL;
        tail=maxNode;
    }

}