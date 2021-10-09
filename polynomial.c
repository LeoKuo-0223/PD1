#include<stdio.h>
#define f(x) 7*x*x*x*x-8*x*x*x-x*x+6*x-22
float x;
int main(void){
	scanf("%f", &x);
	printf("%.1f",f(x));
}
