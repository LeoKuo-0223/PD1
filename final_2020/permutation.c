#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char alphabets[7];
int count=0;
void permutation(char *str, int n){
    char ch ;
    int i ;
    if(n==1) {
    printf("%s\n", str) ;
    }
    else {
        for(i=n-1 ; i>=0 ; i--) {
            ch = *(str+i) ;
            *(str+i) = *(str+n-1) ;
            *(str+n-1) = ch ;
            permutation(str, n-1) ;
            ch = *(str+i) ;
            *(str+i) = *(str+n-1) ;
            *(str+n-1) = ch ;
        }
    }

}

 
int main(void){

    char *ptr_alphabets=alphabets;
    char word;
    
    while((word=getchar())!='\n'){
        *ptr_alphabets=word;
        ptr_alphabets++;
        count++;
    }
    int min;
    for(int i=0;i<count;i++){
        min=alphabets[i];
        for(int j=i+1;j<count;j++){
            if(alphabets[j]<min){
                min=alphabets[j];
                int tmp = alphabets[i];
                alphabets[i] = alphabets[j];
                alphabets[j] = tmp;
            }
        }
    }
    // char *ptr_arr[count];
    // ptr_alphabets=alphabets;
    // int i=0;
    // for(ptr_alphabets;*ptr_alphabets!='\0';ptr_alphabets++){
    //     ptr_arr[i]=ptr_alphabets;
    //     i++;
    // }
    permutation(alphabets,count);
    return 0;
}