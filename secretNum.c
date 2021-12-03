#include <stdio.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", getSecret(n));
	return 0;
}
int getSecret(int n)
{
	int temp=n;
	int count=0;
	int a,b,expTen=1;
	while(temp>=1){
		count++;
		temp/=10;
	}
	if(count==1){
		return n;
	}else if(count%2==0){
		for(int i=0;i<count/2;i++) {
			expTen*=10;
		}
		a=n/expTen;
		b=n%expTen;
		return (n+getSecret(gcd(a,b)))%MODULUS;
	}else{
		//printf("%d",(count/2+1));
		for(int i=0;i<count/2+1;i++){
			expTen*=10;
		}
		a=n/expTen;
		b=n%expTen;
		return (n+getSecret(gcd(a,b)))%MODULUS;
	}
}

int gcd(int a, int b)
{
	if(a>=b){
		int r;
		while(b!=0){
			r=a%b;
			a=b;
			b=r;
		}
		return a;
	}else{
		int r;
		while(a!=0){
			r=b%a;
			b=a;
			a=r;
		}
		return b;
		
	}
}


