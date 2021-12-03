#include<stdio.h>
int wallLength;
unsigned long long combination=0;
unsigned long long fac(int n,int m){
	printf("%d %d	",n,m);
	unsigned long long result=1;
	if(n>m){
		int marray[m];
		for(int i=0;i<m;i++){
			marray[i]=0;
		}
		for(int j=m+n;j>n;j--){
			result=result*j;
			for(int k=1;k<=m;k++){
				if(result%k==0 && marray[k-1]==0){
					marray[k-1]=1;
					result/=k;
				}
			}
		}
	}else if(n<=m){
		int narray[n];
		for(int i=0;i<n;i++){
			narray[i]=0;
		}
		for(int j=m+n;j>m;j--){
			result=result*j;
			for(int k=1;k<=n;k++){
				if(result%k==0 && narray[k-1]==0){
					narray[k-1]=1;
					result/=k;
				}
			}
		}
	}
	printf("%llu\n",result);
	return result;
}
void main(){
	int vertical=0,horizontal=0;
	scanf("%d",&wallLength);
	if(wallLength>0){
		for(int i=0;20*i<=wallLength;i++){
				vertical = (wallLength-20*i)/10;
				horizontal = i;
				combination = combination+ fac(vertical,horizontal);
		}
		printf("%llu",combination);
	}else printf("%llu",combination);
}
