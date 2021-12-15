#include<stdio.h>
#include<string.h>
int main(){
    char target[3] = {'1','2','3'};
    char test[]="123";
    printf("%d\n",strlen(target));
    printf("%d",strlen(test));
    printf("%c",test[0]);
    return 0;
}