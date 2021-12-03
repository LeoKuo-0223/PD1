#include <stdio.h>
int length;
char message;
int key(char word){
	return word-97;
}


int main(void){
    scanf("%d",&length);
    char code[length];
    while(getchar()!='\n');
    for(int i=0;i<length;i++){
        scanf("%1c",&code[i]);
    }
    // printf("%c",code[1]);
    while(getchar()!='\n');
    int s=0;

        while((message = getchar())!='\n'){
            // printf("|%d*",key(code[k]));
            int k=key(code[s]);
            if(k>=0){
                if(message>64 && message<91){
                    if(message>90-k) printf("%c", 65+((k-(91-message))%26));
                    else printf("%c",message+k);
                    s++;
                    if(s>length-1) s=s%(length);
                }else if(message>96 && message<123){
                    if(message>122-k) printf("%c", 97+((k-(123-message))%26));
                    else printf("%c",message+k);
                    s++;
                    if(s>length-1) s=s%(length);
                }else printf("%c",message);
            }


        }
    
    return 0;
}