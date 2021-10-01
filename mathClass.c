#include<stdio.h>
int a,b,c,d;
int main(void){ 
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%.4d %.4d %.4d",a,a-b+c,a-b+c-d);  }
