#include<stdio.h>
int CN,SO,SC,point,grade;
int A=0,B=0,C=0;
float EN,MA;
int main(){
	scanf("%d %f %f %d %d",&CN,&EN,&MA,&SO,&SC);
	if(CN>=41){//國文
		point+=6;
		A+=1;
		if(CN>=43&&CN<=44) grade+=6;
		else if(CN>44) grade+=7;
		else grade+=5;
	}else if(CN>=19&&CN<=40){
		point+=4;
		B+=1;
		if(CN>=31&&CN<=35) grade+=3;
		else if(CN>35) grade+=4;
		else grade+=2;
	}else {point+=2; grade+=1;C+=1;}
	
	if(EN>=90.24){//英文
		point+=6;
		A+=1;
		if(EN>=95.15&&EN<=97.14) grade+=6;
		else if(EN>97.14) grade+=7;
		else grade+=5;
	}else if(EN>=38.75&&EN<=89.52){
		point+=4;
		B+=1;
		if(EN>=68.93&&EN<=81.53) grade+=3;
		else if(EN>81.53) grade+=4;
		else grade+=2;
	}else {point+=2; grade+=1;C+=1;}

	if(MA>=81.73){//數學
		point+=6;
		A+=1;
		if(MA>=90.19&&MA<=93.46) grade+=6;
		else if(MA>93.46) grade+=7;
		else grade+=5;
	}else if(MA>=40.96&&MA<=81.15){
		point+=4;
		B+=1;
		if(MA>=63.08&&MA<=71.92) grade+=3;
		else if(MA>71.92) grade+=4;
		else grade+=2;
	}else {point+=2; grade+=1;C+=1;}

	if(SO>=56){//社會
		point+=6;
		A+=1;
		if(SO>=59&&SO<=60) grade+=6;
		else if(SO>60) grade+=7;
		else grade+=5;
	}else if(SO>=23&&SO<=55){
		point+=4;
		B+=1;
		if(SO>=39&&SO<=47) grade+=3;
		else if(SO>47) grade+=4;
		else grade+=2;
	}else {point+=2; grade+=1;C+=1;}

	if(SC>=46){//自然
		point+=6;
		A+=1;
		if(SC>=50&&SC<=51) grade+=6;
		else if(SC>51) grade+=7;
		else grade+=5;
	}else if(SC>=20&&SC<=45){
		point+=4;
		B+=1;
		if(SC>=31&&SC<=37) grade+=3;
		else if(SC>37) grade+=4;
		else grade+=2;
	}else {point+=2; grade+=1;C+=1;}
	printf("%d/%d",point,grade);
	if(A==0){
		if(B==0) printf("(%dC)",C);
		else if(C==0) printf("(%dB)",B);
		else printf("(%dB%dC)",B,C);
	}else if(B==0){
		if(C==0) printf("(%dA)",A);
		else printf("(%dA%dC)",A,C);
	}else if(C==0){	
		printf("(%dA%dB)",A,B);
	}else printf("(%dA%dB%dC)",A,B,C);
}
