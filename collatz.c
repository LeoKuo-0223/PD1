#include<stdio.h>
int s,len=1,max=1;
int main(){
	scanf("%d",&s);
	while(s!=1){
		len++;
		if(s>max) max=s;
		if(s%2==0){
			s/=2;
		}else s=3*s+1;
	}
	printf("%d %d",len,max);
}
