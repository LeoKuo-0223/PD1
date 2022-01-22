#include<stdio.h>
#include<stdlib.h>

int pull_radish(int *l, int *r, int *pos, int x);

int main() {
    int N, y, x;
    scanf("%d %d %d", &N, &y, &x);
    int *farm = malloc(N*sizeof(int));

    // initialize farm[N]
    for(int i=0; i<N; i++) {
        farm[i]=1;
    }

    int total = pull_radish(&farm[0], &farm[N-1], &farm[y], x);
    printf("%d\n", total);
    for(int i=0; i<N; i++) {
        printf("%d ", farm[i]);
    }

    return 0;
}

// l represents the first radish to the left 左邊第一個
// r represents the first radish to the right 右邊第一個
// pos represents Ariel's position
// x represents the interval
#include<stdbool.h>
int pull_radish(int *l, int *r, int *pos, int x) {
    int *ptr_l;
    int *ptr_r;
    bool over_l=false;
    bool over_r=false;
    int count=0;
    if(pos-x>=l){
        ptr_l=pos-x;
    }else{
        over_l=true;
    }
    if(pos+x<=r){
        ptr_r=pos+x;
    }else{
        over_r=true;
    }

    for(ptr_l;over_l==false;ptr_l-=x){
        *ptr_l=0;
        count++;
        if(ptr_l-x<l) over_l=true;
    }
    for(ptr_r;over_r==false;ptr_r+=x){
        *ptr_r=0;
        count++;
        if(ptr_r+x>r) over_r=true;
    }
    return count;
}