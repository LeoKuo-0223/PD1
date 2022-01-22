#include<stdio.h>
int main () {
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int *ptr_number;
        float number;
        ptr_number = (int*)&number;
        int p1,p2,p3,p4;
        scanf("%f",&number);
        p1 = *ptr_number & 0xff;
        p2 = (*ptr_number>>8) & 0x000000ff;
        p3 = (*ptr_number>>16) & 0x000000ff;
        p4 = (*ptr_number>>24) & 0x000000ff;
        int total=p1+p2+p3+p4;
        if(total%2==1){
            printf("Back\n");
        }else{
            printf("Front\n");
        }
    }
    return 0;
}