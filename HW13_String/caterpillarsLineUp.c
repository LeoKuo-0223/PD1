#include<stdio.h>
#include<stdbool.h>

void lineup_again(char line[]);
void swap(char *a, char *b);
void reverse_caterpillar(char *l, char *r);

int main() {
    char line[1000000];
    scanf("%s", line);
    lineup_again(line);
    printf("%s", line);
}

void swap(char *a, char *b) {
    char temp=*a;
    *a = *b;
    *b=temp;
}

void reverse_caterpillar(char *l, char *r) {
    int dis = (r-l);
    if(dis%2!=0){
        while(l<r){
            swap(l,r);
            l++;
            r--;
        }
    }else{
        while(l!=r){
            swap(l,r);
            l++;
            r--;
        }
    }
}

void lineup_again(char line[]) {
    char *p;

    for(p=line;p<line+1000000;p++){
        if(*p=='Z'){
            char *tmp;
            for(tmp=p;tmp<line+1000000;tmp++){
                if(*tmp=='A'){
                    reverse_caterpillar(p,tmp);
                    break;
                }
            }
            p=tmp;
        }else if(*p=='A'){

            char *tmp;
            for(tmp=p;tmp<line+1000000;tmp++){
                if(*tmp=='Z'){
                    break;
                }
            }
            p=tmp;
        }
    }
}