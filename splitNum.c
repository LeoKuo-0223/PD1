#include<stdio.h>
int x;
int main(){
	scanf("%d",&x);
	if(x/100==0){
		if(x/10==0){
			printf("0 0 %d",x);
		}else {
				printf("0 %1d %1d",x/10,x%10);
		}
	}else{
		printf("%1d %1d %1d",x/100,(x%100)/10,x%10);
	}
}
