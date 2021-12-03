#include<stdio.h>
int passcode(int n){
	if(n>1){
		if(n%2==0){
			return passcode(n/2);
		}else{
			return passcode(n+1)+passcode(n-1);
		}
	}else if(n==1){
		return 1;
	}
}
int main(void){
	int n;
	scanf("%d",&n);
	printf("%d",passcode(n));
	return 0;
}
