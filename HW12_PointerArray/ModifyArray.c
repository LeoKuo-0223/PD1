#include <stdio.h>
#define SIZE 201

void modify_array(int *);

int main(void) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    modify_array(&arr[SIZE/2]);
    for (int i = 1; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void modify_array(int *p) {
    int *termination = p+100;
    p=p-100;
    if(*p==1){
        p++;
        for(int i=1;i<SIZE;i+=2){
            *p=*p+10;
            if(p+2<=termination){
                p+=2;
            }
            
        }
    }else if(*p==2){
        p++;
        for(int i=1;i<SIZE;i+=3){
            *p=*p*8;
            if(p+3<=termination){
                p+=3;
            }
        }
    }else if(*p==3){
        p++;
        for(int i=1;i<SIZE;i+=5){
            *p=*p-2;
            if(p+5<=termination){
                p+=5;
            }
        }
    }
    return;
}