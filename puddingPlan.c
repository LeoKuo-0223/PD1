#include<stdio.h>
int box1,box2, box3;
int main(void){
	scanf("%d %d %d",&box1,&box2,&box3);
	if((box1+box2+box3)%7==0) printf("%d 0",(box1+box2+box3)/7);
	else printf("%d %d",(box1+box2+box3)/7,(box1+box2+box3)%7);
	return 0;
}
