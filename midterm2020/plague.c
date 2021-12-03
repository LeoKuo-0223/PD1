#include <stdio.h>

int main(void){
    long double R;
    int N;
    long double total=1;
    long result;
    scanf("%Lf %d",&R,&N);
    for(int i=0;i<N;i++){
        total=total*R;
    }
	

    result = total;
    printf("%ld",result);
    // printf("%Lf\n",total);
    // printf("%.0Lf",total);
    return 0;
}