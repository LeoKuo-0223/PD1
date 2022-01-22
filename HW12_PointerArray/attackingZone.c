#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1024

void convert_to_polar(int *coords, int N);

int main()
{
    int N, coords[MAX_N + 1][2];
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d%d", &coords[i][0], &coords[i][1]);
    
    
    convert_to_polar((int *) coords, N);
    
    return 0;
}
void convert_to_polar(int *coords, int N)
{
    for(int i=0;i<N;i++){
        double tan = (double)coords[1+i*2]/(double)coords[0+i*2];
        double angle = atan(tan);
        angle = angle*(180/3.14159265358);
        double dis =sqrt(pow(coords[1+i*2],2)+pow(coords[0+i*2],2));
        if(coords[0+i*2]>0&& coords[1+i*2]>0){

        }else if(coords[0+i*2]<0 && coords[1+i*2]>=0){
            angle +=180;
        }else if(coords[0+i*2]<0 && coords[1+i*2]<0){
            angle+=180;
        }else if(coords[0+i*2]>=0 && coords[1+i*2]<0){
            angle+=360;
        }

        printf("%.2f %.2f\n",angle,dis);
    }
}