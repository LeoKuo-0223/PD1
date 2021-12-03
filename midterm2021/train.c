#include<stdio.h>

int main () {
    int hh;
    int mm,numTrain;
    int minH=24;
    int minM=59;
    int targetIndex;
    scanf("%d:%d",&hh,&mm);
    scanf("%d",&numTrain);
    int trainIndex;
    int departH,departM;
    int runtime;
    for(int i=0;i<numTrain;i++){
        scanf("%d %d:%d %d",&trainIndex,&departH,&departM,&runtime);
        //printf("%d %d:%d %d\n",trainIndex,departH,departM,runtime);
        if(hh==departH){
            if(mm<=departM){
                int addH,addM;
                addM=runtime%60;
                addH=runtime/60;
                //printf("\n%d+%d= %d\n",addH,departH,(departH+addH));
                if((departH+addH)<minH) {
                    minH=(departH+addH);
                    minM = (departM+addM);
                    //minM = (departM+addM);
                        targetIndex = trainIndex;
                        //  printf("\nposi trainIndex %d\n",targetIndex);
                        //  printf("\nminH %d\n",minH);
                        // printf("arrived time %d:%d",minH,minM);
                    
                }else if((departH+addH)==minH){
                    minH=(departH+addH);
                    if((departM+addM)<=minM) {
                        minM = (departM+addM);
                        targetIndex = trainIndex;
                        //  printf("\nposi trainIndex %d\n",targetIndex);
                        //  printf("\nminH %d\n",minH);
                        // printf("arrived time %d:%d",minH,minM);
                    }
                }
                
            }
        }else if(hh<departH){
            int addH,addM;
                addM=runtime%60;
                addH=runtime/60;
            if((departH+addH)<minH) {
                    minH=(departH+addH);
                    minM = (departM+addM);
                   
                        targetIndex = trainIndex;
                        
                    
                }else if((departH+addH)==minH){
                    minH=(departH+addH);
                    if((departM+addM)<=minM) {
                        minM = (departM+addM);
                        targetIndex = trainIndex;
               
                    }
                }
        }
    }
    printf("%d",targetIndex);
    return 0;
}