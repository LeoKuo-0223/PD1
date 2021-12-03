#include <stdio.h>
int length;
char message;



int main(void){
    long k;
    scanf("%ld",&k);
    char movetype;
    while(getchar()!='\n');
    scanf("%c",&movetype);
    while(getchar()!='\n');
    //printf("%c",movetype);
    if(movetype=='a'){
        
        while((message = getchar())!='\n'){
            // printf("|%d*",key(code[k]));
            
            if(k>=0){
                if(message>64 && message<91){
                    if(message>90-k) printf("%c", 65+((k-(91-message))%26));
                    else printf("%c",message+k);
                    k++;
                    
                }else if(message>96 && message<123){
                    if(message>122-k) printf("%c", 97+((k-(123-message))%26));
                    else printf("%c",message+k);
                    k++;
                    
                }else printf("%c",message);
            }else{
			if(message>64 && message<91){
				if(message<65-k) printf("%c", 90-((0-k)-(message-64))%26);
				else printf("%c",message+k);
                 k++;
			}else if(message>96 && message<123){
				if(message<97-k) printf("%c", 122-((0-k)-(message-96))%26);
				else printf("%c",message+k);
                 k++;
			}else printf("%c",message);
				
		}
            


        }
    }else if(movetype=='d'){
        
         while((message = getchar())!='\n'){
            // printf("|%d*",key(code[k]));
            
            if(k>=0){
                if(message>64 && message<91){
                    if(message>90-k) printf("%c", 65+((k-(91-message))%26));
                    else printf("%c",message+k);
                    k--;
                    
                }else if(message>96 && message<123){
                    if(message>122-k) printf("%c", 97+((k-(123-message))%26));
                    else printf("%c",message+k);
                    k--;
                    
                }else printf("%c",message);
            }else{
			if(message>64 && message<91){
				if(message<65-k) printf("%c", 90-((0-k)-(message-64))%26);
				else printf("%c",message+k);
                k--;
			}else if(message>96 && message<123){
				if(message<97-k) printf("%c", 122-((0-k)-(message-96))%26);
				else printf("%c",message+k);
                k--;
			}else printf("%c",message);
				
		}
            


        }
    }

    
    return 0;
}