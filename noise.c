#include<stdio.h>
#include<stdlib.h>
#define NUM 10

int num[NUM];
int Max=0;


int noise(int m,int n,int a,int b){
	return (m+n)*abs(a-b);
}
int main(){
	int temp;
	for(int i=0;i<NUM;i++){
		scanf("%d",&num[i]);
	}
	for(int j=0;j<NUM;j++){
		for(int k=j+1;k<NUM;k++){
			temp=noise(num[j],num[k],j,k);
			if(temp>Max) Max=temp;
		}
	}
	printf("%d",Max);
}
