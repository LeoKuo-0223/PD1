#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
int addition(char str[]) {
    int total=0;
    char tok[2]="+";
    char *ptr;
   	ptr=strtok(str,tok);
    while(ptr!=NULL){
		total+=atoi(ptr);
        ptr=strtok(NULL,tok);
    }
    return total;
}