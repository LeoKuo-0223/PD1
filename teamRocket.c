#include<stdio.h>
#include<stdlib.h>
int numPlan;
int found = 0;
const char planChar[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main(){
	scanf("%d", &numPlan);
	int Index[numPlan];
	char plan[numPlan];
	for(int i=0;i<numPlan;i++){
		scanf("%d %c",&Index[i],&plan[i]);
	}
	for(int i=0;i<26;i++){
		found=0;
			for(int j=0;j<numPlan;j++){
				if(planChar[i]==plan[j]) {
					printf("Plan %c is in box %d.\n",planChar[i],Index[j]);
					found=1;
				}
			}
			if(!found){
				printf("Not found plan %c.\n",planChar[i]);
			}
	}
}
