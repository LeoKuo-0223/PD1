#include<stdio.h>
#include<math.h>

int main(void){
    int mode;
    double PI=3.14;
    double length,width,height;
    double radius;
    scanf("%d",&mode);
    switch(mode){
        case 1:
            scanf("%lf",&length);
            printf("%.2f",length*length*length);
            break;
        case 2:
            scanf("%lf %lf %lf",&length,&width,&height);
            printf("%.2lf",length*width*height);
            break;
        case 3:
            scanf("%lf %lf",&radius,&height);
            printf("%.2lf",PI*radius*radius*height);
            break;
        case 4:
            scanf("%lf",&length);
            printf("%.2lf",sqrt(2)/12*length*length*length);
            break;
    }
    return 0;
}