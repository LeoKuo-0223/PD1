#include <stdio.h>
#include<string.h>

char key[1000];
char getkey(int count,int Length);
int main () {
    char new_char,orig_char;
    int count=0;
    int len=0;
    char word;
    while((word=getchar())!='\n'){
        key[len] = word;
        len++;
    }
    //scanf("%s",key);
    //len=strlen(key);
    //while(getchar()!='\n');
    while((orig_char=getchar())!='\n'){
        char k=getkey(count,len);
        new_char = orig_char ^ k;
        count++;
        if(new_char>=0 &&new_char<=255){
            putchar(new_char);
        }
    }
    return 0;
}

char getkey(int count,int Length){
    return key[count%Length];
}