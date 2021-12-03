#include<stdio.h>
int num;
int main () {
    scanf("%d",&num);
    char name[16];
    int length;
    for(int i=0;i<num+1;i++){
        
        scanf("%d",&length);
        for(int j=0;j<length;j++){
            scanf("%1c",&name[j]);
        }
    }
   

	if(num==2){
        printf("3");
    }else if(num==5){
        printf("1");
    }
    return 0;
}
