#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Card{
    int data;
    struct Card *next;
}Card;
Card *cardarray=NULL;
Card *head=NULL;
Card *discardArray=NULL;
Card *discardhead;


void discard(Card *discardcard){
    cardarray->next=discardcard->next;
    if(discardArray!=NULL){
        discardhead->next=discardcard;
        discardhead=discardcard;
        discardhead->next=NULL;
    }else{
        discardArray=discardcard;
        discardhead=discardArray;
        discardhead->next=NULL;
    }

}

void moveCard(Card *movedcard){
    if(movedcard->next!=NULL){
        cardarray->next=movedcard->next;
    }
    head->next=movedcard;
    head=movedcard;
}
int main(){
    int n;
    int num;
    cardarray=malloc(sizeof(Card));
    head=cardarray;
    scanf("%d %d",&n,&num);
    for(int i=1;i<=n;i++){
        Card *tmp = malloc(sizeof(Card));
        tmp->data=i;
        head->next=tmp;
        head=tmp;
    }
    head->next=NULL;
    for(int i=0;i<num;i++){
        Card *ptr=cardarray->next;
        Card *discardCard=ptr;
        Card *movedCard=NULL;
        if(ptr->next!=NULL) movedCard = ptr->next;
        discard(discardCard);
        if(movedCard!=NULL){
            moveCard(movedCard);
            movedCard->next=NULL;
        }
    }
    Card *ptr_output;
    ptr_output=discardArray;
    while(ptr_output!=NULL){
        printf("%d ",ptr_output->data);
        ptr_output=ptr_output->next;
    }
    return 0;
}