#include<stdio.h>
#define f(x) x*9/5+32
float celsius;
int main(void){
	scanf("%f",&celsius);
	printf("%.2f",f(celsius));
}
