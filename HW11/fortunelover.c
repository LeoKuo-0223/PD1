#include<stdio.h>

void addition();

void print_binary(void* n){
    for(int i = 31; i >= 0; --i){
        printf("%d", (*(int *)n >> i) & 1);
        if(i && !(i % 8)) printf(" ");
    }
}

int main(){
    addition();
    return 0;
}

void addition(){
    int a,b;
    float *pa,*pb;
    pa=(float*)&a;
    pb=(float*)&b;
    scanf("%f %f",(float*)&a,(float*)&b); 
    printf("   ");
    print_binary(&a);
    printf("\n");
    printf("+) ");
    print_binary(&b);
    printf("\n");
    printf("---------------------------------------\n");
    printf("   ");
    // int result_a=0;
    // int result_b=0;
    //int exp=1;
    int result = a+b;
    print_binary(&result);
    printf("\n");

    printf("%.f + %.f = ",*pa,*pb);
    printf("%d",a+b);

}