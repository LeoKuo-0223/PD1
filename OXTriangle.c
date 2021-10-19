#include<stdio.h>
int main(){
	int n,flag;
	scanf("%d",&n);
	for(int i=0;i<n;i++){	
		for(int k=0;k<n-1-i;k++){
			printf(" ");
		}
		for(int j=0;j<1+2*i;j++){
			if(i!=n-1){
				if(flag) {printf("O");flag=0;}
				else {printf("X");flag=1;}
			}else printf("O");
		}
		flag=1;
		printf("\n");
	}
}
