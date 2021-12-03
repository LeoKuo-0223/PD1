#include <stdio.h>
int angle,m,n;
int main(void){
    scanf("%d",&angle);
    scanf("%d %d",&m,&n);
    int array[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i][j]);
        }
    }
    
    if(angle==90){
            int result[n][m];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[j][(m-1)-i] = array[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
    }else if(angle==180){
            int result[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    result[(m-1)-i][(n-1)-j] = array[i][j];
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            

    }else{
            int result[n][m];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    result[(n-1)-j][i] = array[i][j];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%d ",result[i][j]);
                }
                printf("\n");
            }
            
    }

    return 0;
}
