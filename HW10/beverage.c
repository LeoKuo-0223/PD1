#include<stdio.h>

int earnMoney=0;
int ingredient[7];
int sugar;
int ice;
void check(char type[],int sugar,int ice,int len);

int main(){
    int num;
    for(int i=0;i<7;i++){
        scanf("%d",&ingredient[i]);
        ingredient[i] = 1000*ingredient[i];
    }
    scanf("%d",&num);
    while(getchar()!='\n');
    for(int i=0;i<num;i++){
        char word1[1];
        word1[0] = getchar();
        char word2;
        char message[2];
        if((word2 = getchar())!=' '){
            message[0] = word1[0];
            message[1] = word2;
            scanf("%d/%d",&sugar,&ice);
            check(message,sugar,ice,2);
        }else{
            scanf("%d/%d",&sugar,&ice);
            check(word1,sugar,ice,1);
        }
        while(getchar()!='\n');

    }
    for(int i=0;i<7;i++){
        printf("%d ",ingredient[i]);
    }
    printf("\n");
    printf("%d",earnMoney);
    return 0;
}

void check(char type[],int sugar,int ice,int len){
    switch(sugar){
        case 1: sugar = 0;break;
        case 2: sugar = 3;break;
        case 3: sugar = 5;break;
        case 4: sugar = 7;break;
        case 5: sugar = 10;break;
        default: break;
    }
    switch(ice){
        case 1: ice = 0;break;
        case 2: ice = 30;break;
        case 3: ice = 50;break;
        case 4: ice = 70;break;
        case 5: ice = 100;break;
        default: break;
    }
    if(len==1){
        switch(type[0]){
            case 'G':
                earnMoney = earnMoney+20;
                ingredient[3] = ingredient[3]-500;
                break;
            case 'B':
                earnMoney = earnMoney+20;
                ingredient[0] = ingredient[0]-500;
                break;
            case 'T':
                earnMoney = earnMoney+30;
                ingredient[2] = ingredient[2]-500;
                break;
            case 'W':
                earnMoney = earnMoney+15;
                ingredient[1] = ingredient[1]-500;
                break;
            default:
                break;
        }
        ingredient[5] -= sugar;
        ingredient[6] -= ice;
    }else{
        switch(type[0]){
            case 'G':
                earnMoney = earnMoney+45;
                ingredient[2] = ingredient[2]-250;
                ingredient[3] = ingredient[3]-250;
                break;
            case 'W':
                if(type[1]=='T'){
                    earnMoney = earnMoney+40;
                    ingredient[2] = ingredient[2]-350;
                    ingredient[1] = ingredient[1]-150;
                }else{
                    earnMoney = earnMoney+30;
                    ingredient[1] = ingredient[1]-200;
                    ingredient[4] = ingredient[4]-300;
                }
                break;
            case 'T':
                    earnMoney = earnMoney+45;
                    ingredient[2] = ingredient[2]-200;
                    ingredient[4] = ingredient[4]-300;
                break;
            case 'B':
                    earnMoney = earnMoney+35;
                    ingredient[0] = ingredient[0]-200;
                    ingredient[4] = ingredient[4]-300;
                break;
            default:
                break;
        }
        ingredient[5] -= sugar;
        ingredient[6] -= ice;
    }
}