#include <stdio.h>
void swap(int *a,int i, int smallerIndex){
	if(i==smallerIndex) return;
	int temp;
	temp = a[i];
	a[i]=a[smallerIndex];
	a[smallerIndex]=temp;
	return;
}
int main(void){
    int m,n;
    scanf("%d %d",&m,&n);

    int result[m+n];
    for(int i=0;i<m;i++){
        scanf("%d",&result[i]);
    }
    for(int i=m;i<m+n;i++){
        scanf("%d",&result[i]);
    }
    for(int i=0;i<m+n;i++){
		int smallerIndex=i;
		for(int j=i+1;j<m+n;j++){
			if(result[j]<result[i] && result[j]<result[smallerIndex]){
				smallerIndex=j;
			}
		}
		swap(result,i,smallerIndex);

	}
    for(int i=0;i<m+n;i++){
		printf("%d ",result[i]);
	}
    return 0;
}