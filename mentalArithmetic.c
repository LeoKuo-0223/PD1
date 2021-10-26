#include<stdio.h>
int N;
unsigned long int k;
unsigned long int base=1;
unsigned long int result=0;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lu",&base);
		switch(base){
			case 6:
				scanf("%ld",&k);
                base=1;
				while(k>0){
					result=(result+((k%10)*base))%1000000007;
					base*=6;
					k/=10;
				}
				break;
			case 8:
				scanf("%lo",&k);
				result = (result+k)%1000000007;
				break;
			case 10:
				scanf("%ld",&k);
				result = (result+k)%1000000007;
				break;
			case 16:
				scanf("%lx",&k);
				result = (result+k)%1000000007;
				break;
		}
	}
	printf("%ld",result);
}
