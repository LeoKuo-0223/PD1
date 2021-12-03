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
    int b=1;
    int c=2;
    int next=0;
    record_B[b]=1;
    record_C[b]=1;
    record_B[lonelyNumIndex]=1;
    record_C[lonelyNumIndex]=1;
    for(;;){
        if(next==1){
            c=0;
            for(int j=0;j<n;j++){
                record_C[j] = 0;
                if(record[j]==1) record_C[j] = 1;
            }
            for(;;){
                if(record[b]==1||record_B[b]==1){
                    b++;
                    if(b==n){
                        printf("%d",array[lonelyNumIndex]);
                        return 0;
                    }
                    
                }else {
                    record_B[b]=1;
                    record_C[b]=1;
                    break;
                }
            }

            next=0;
        }
    
        for(;;){
            if(record[c]==1||record_C[c]==1){
                c++;
                if(c==n) c=c%n;
            }else break;
            
        }


        int sum = array[lonelyNumIndex] + array[b];
        if(sum==array[c]){
            record[lonelyNumIndex] = 1;
            record[b] = 1;
            record[c] = 1;
            for(int j=0;j<n;j++){
                record_B[j] = 0;
                record_C[j] = 0;
            }
            for(int i=0;i<n;i++){
                if(record[i]==1){
                    record_B[i] = 1;
                    record_C[i] = 1;
                }
            }
            for(;;){
                if(record[lonelyNumIndex]==1){
                    lonelyNumIndex++;
                    if(lonelyNumIndex==n-1) {
                        printf("%d",array[lonelyNumIndex]);
                        return 0;
                    }

                }else {
                    next=1;
                    record_C[lonelyNumIndex] = 1;
                    record_B[lonelyNumIndex] = 1;
                    break;
                }
            
            }
        }else{
            record_C[c] = 1;
            for(int i=0;i<n;i++){
                if(record_C[i]==0){
                    next=0;
                    break;
                }
                next=1;
            }
        }


    }
    return 0;
}


// record_B[b]=1;

//     for(;;){
//             if(b==lonelyNumIndex ||record[b]==1||record_B[b]==1){
//                 b++;
//                 if(b==n){
//                     printf("%d",array[lonelyNumIndex]);
//                     return 0;
//                 }
                
//             }else break;
//         }
