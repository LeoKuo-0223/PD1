#include<stdio.h>
int targetIndex=0;
int num=0;

void print_binary(void* n){
    // for(int i = 63; i >= 0; --i){
    //     printf("%d", (*(int *)n >> i) & 1);
    //     if(i && !(i % 8)) printf(" ");
    // }
	//n=(unsigned int *)n;
    for(int i=63;i>=0;--i){
        if(i<=targetIndex+7 && i>=targetIndex){
            printf("%d", (*(int *)n >> i) & 1);
        }
        else{
            printf("%d", (*(int *)n >> i) & 0);
        }
        if(i && !(i % 8)) printf(" ");
    }
    printf("\n");
}
int main () {
    unsigned long long *word;
    unsigned long long word1;
    word=&word1;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d^[-]",&targetIndex);
        while((getchar())!='-'){
            // printf("%c",word);
        };
        scanf("%llx",&word1);
        print_binary(word);

    }
    return 0;
}
// 00000000 00000000 00000000 00000011 00110000 00000000 00000000 00000000 





