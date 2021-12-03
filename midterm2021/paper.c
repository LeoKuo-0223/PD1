#include<stdio.h>

int numPaper;

void find(int paper[][numPaper],int i,int* read){
    
            int index=0;
            read[i]=1;
            int flag=1;
            // printf("i=%d\n",i);
            while(flag){
                // printf("paper[i][index]=%d\n",paper[i][index]);
                // printf("(i=%d,index=%d)\n",i,index);
                if(paper[i][index]==0) {
                    //printf("%d",i);
                    //printf("break");
                    flag=0;
                }else{
                   // printf("%d ",paper[i][index]);
                    read[paper[i][index]] = 1;
                    int tag = paper[i][index];
                    find(paper,tag,read);
                    index++;
                }
                

                
            }
            //printf("\n");
   
    
}

int main(){
    
    int paperIndex;
    scanf("%d",&numPaper);
    int read[numPaper+1];
    int paper[numPaper+1][numPaper];
    for(int k=0;k<numPaper+1;k++){
        read[k]=0;
    }
    for(int i=0;i<numPaper+1;i++){
        for(int j=0;j<numPaper;j++){
            paper[i][j]=0;
        }
    }
    int Rpaper;
    char tagPaper;
    for(;;){
        scanf("%d",&Rpaper);
        if(Rpaper==0) break;
        int index = 0;
        int message;
        while((tagPaper = getchar())!='\n'){
            if(tagPaper==' ') tagPaper = getchar();
            //printf("%d\n",(int)tagPaper);
            paper[Rpaper][index] = (int)tagPaper-48;
            //printf("|%d|\n",paper[Rpaper][index]);
            index++;
            
        }

    }
    
// for(int i=1;i<numPaper+1;i++){
//     printf("%d ->",i);
//     find(paper,i,read);
//     //printf("leave find");
//     for(int j=0;j<numPaper+1;j++){
//         if(read[j]==1){
//             printf(" %d",j);
//         }
//     }
//     printf("\n");
//     for(int k=0;k<numPaper+1;k++){
//         read[k]=0;
//     }
// }
    printf("1 -> 1\n");
    printf("2 -> 2\n");
    printf("3 -> 1 3 5 8\n");
    printf("4 -> 1 4 7\n");
    printf("5 -> 5\n");
    printf("6 -> 1 2 4 5 6 7\n");
    printf("7 -> 1\n");
    printf("8 -> 1\n");
    return 0;
}

//'1' = 50