#include<stdio.h>
int a,b;
int main(void){
	scanf("%d %d",&a,&b);
	printf("%6.4d\n",a);
	printf("+)%.4d\n",b);
	printf("------\n");
	printf("%.6d",a+b);
}
