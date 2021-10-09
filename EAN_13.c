#include<stdio.h>
int f1,m1,m2,m3,m4,m5,m6,p1,p2,p3,p4,p5,sum;
int main(void){
	scanf("%1d %1d%1d%1d%1d%1d%1d %1d%1d%1d%1d%1d", &f1,&m1,&m2,&m3,&m4,&m5,&m6,&p1,&p2,&p3,&p4,&p5);
	sum=(f1+m2+m4+m6+p2+p4)+(m1+m3+m5+p1+p3+p5)*3;
	printf("%d",((sum-1)/10*10+10)-sum);
}
