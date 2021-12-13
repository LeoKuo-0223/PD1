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
    float a,b;
    float *pa,*pb;
    pa=&a;
    pb=&b;
    scanf("%f %f",&a,&b); 
    printf("   ");
    print_binary(&a);
    printf("\n");
    printf("+) ");
    print_binary(&b);
    printf("\n");
    printf("---------------------------------------\n");
    printf("   ");
    int result_a=0;
    int result_b=0;
    int exp=1;
    for(int i = 0; i <= 31; i++){

        result_b += ((*(int *)pb >> i) & 1)*exp;
        result_a += ((*(int *)pa >> i) & 1)*exp;
        exp*=2;
    }
    int result = result_a+result_b;
    print_binary(&result);
    printf("\n");

    printf("%d + %d = ",(int)a,(int)b);
    printf("%d",result);

}