#include<stdio.h>
unsigned int a,b;

int main(){
	scanf("%x %x",&a,&b);
	if(a+b<=0xFFFF){
		printf("%u",a+b);
	}else{
		printf("OVERFLOW!");
	}
}

