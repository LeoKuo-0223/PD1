#include<stdio.h>
#include<stdlib.h>

long combination(int n,int m){
	if(m==0 || m==n){
		return 1;
	}else{
		long result;
		result = combination(n-1,m-1)+combination(n-1,m);
		return result;
	}
}
int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%ld",combination(n,m));
}
