#include<stdio.h>
int m,n;
long long mproduct=1;

int main(){
	scanf("%d %d",&m,&n);
	for(int i=m;i>n;i--){
		if(i<=m-n){
			;
		}else{
			mproduct=mproduct*i;
		}
	}	
	if(n<m-n){
		for(int k=n;k>1;k--){
			mproduct /= k;
		}
	}else{
		for(int k=m-n;k>1;k--){
			mproduct/=k;
		}
	}

	printf("%lld",mproduct);
}
