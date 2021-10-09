#include<stdio.h>
int arabic;
int main(){
	scanf("%d",&arabic);
	for(int i=0;i<arabic/1000;i++){
		printf("M");
	}
	switch((arabic%1000)/100){
		case 1: case 2: case 3: 
			for(int i=0;i<(arabic%1000)/100;i++) {printf("C");}
			break;
		case 4:
			printf("CD");
			break;
		case 5: case 6: case 7: case 8:
			printf("D");
			for(int i=0;i<(arabic%1000)/100-5;i++) {printf("C");}
			break;
		case 9:
			printf("CM");
			break;
	}
	if((arabic%100)/10==4){
		printf("XL");
	}else if((arabic%100)/10==9){
		printf("XC");
	}else{
		if((arabic%100)/10<4) {
			for(int i=0;i<(arabic%100)/10;i++){printf("X");}
		}else{
			printf("L");
			for(int i=0;i<(arabic%100)/10-5;i++){printf("X");}
		}
	}
	if((arabic%10)==4){
		printf("IV");
	}else if((arabic%10)==9){
		printf("IX");
	}else{
		if((arabic%10)<4) {
			for(int i=0;i<(arabic%10);i++){printf("I");}
		}else{
			printf("V");
			for(int i=0;i<(arabic%10)-5;i++){printf("I");}
		}
	}
}
