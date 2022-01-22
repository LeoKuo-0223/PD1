#include <stdio.h>
#include <stdint.h>

int bingo (unsigned char[]);

int main () {
    unsigned char num[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%hhu", &num[i]);
    }
    int ans = bingo(num);
    printf("%d\n", ans);
}
int bingo (unsigned char num[]) {
    int array[8][8]={0};
    int ans=0;
    for(int i=0;i<8;i++){
        for(int j=7;j>=0;j--){
            array[i][7-j]=((num[i]>>j)& 1);
            continue;
        }
    }

    for(int i=0;i<8;i++){
        int tmp=0;
        for(int j=0;j<8;j++){
            tmp+=array[i][j];
            if(tmp==8) ans++;
        }
    }
    for(int i=0;i<8;i++){
        int tmp=0;
        for(int j=0;j<8;j++){
            tmp+=array[j][i];
            if(tmp==8) ans++;
        }
    }
    int tmp=0;
    for(int i=0;i<8;i++){
        tmp+=array[i][i];
    }
    if(tmp==8) ans++;
    tmp=0;
    for(int i=0;i<8;i++){
        tmp+=array[i][7-i];
    }
    if(tmp==8) ans++;
    return ans;
}