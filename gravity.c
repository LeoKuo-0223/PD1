#include<stdio.h>
int main(){
	float g=9.8;
	int height,t=0;
	scanf("%d",&height);
		while(height-0.5*g*t*t>0){
		printf("%.1f\n",height-0.5*g*t*t);
		t++;
	}
}
