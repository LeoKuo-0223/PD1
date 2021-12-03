#include<stdio.h>

int main () {
    int n;
    scanf("%d",&n);
    int array[n];
    int record[n];
    int record_B[n];
    int record_C[n];
    for(int i=0;i<n;i++){
        record[i] = 0;
        record_B[i] = 0;
        record_C[i] = 0;
        scanf("%d",&array[i]);
    }
    int lonelyNumIndex=0;
    int b=0;
    int c=0;
    for(;;){
        for(;;){
            if(b==lonelyNumIndex ||record[b]==1||record_B[b]==1){
                b++;
                if(b==n){
                    printf("%d",array[lonelyNumIndex]);
                    return 0;
                }
                
            }else break;
        }
        for(;;){
            if(c==lonelyNumIndex||c==b||record[c]==1||record_C[c]==1){
                c++;
                if(c==n) c=c%n;
            }else break;
            
        }
        int sum = array[lonelyNumIndex] + array[b];
        if(sum==array[c]){
            record[lonelyNumIndex] = 1;
            record[b] = 1;
            record[c] = 1;
            for(;;){
                if(record[lonelyNumIndex]==1){
                    lonelyNumIndex++;
                    if(lonelyNumIndex==n-1) {
                        printf("%d",array[lonelyNumIndex]);
                        return 0;
                    }
                    for(int i=0;i<n;i++){
                        record_B[i] = 0;
                        record_C[i] = 0;
                    }
                }else break;
            
            }
        }else{
            record_B[b]=1;
            record_C[c] = 1;
            b++;
            c++;
        }


    }
    return 0;
}
