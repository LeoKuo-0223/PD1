#include<stdio.h>
void VigeCipher();
int key(char word);
void Trith();
void Caesar();
void swap();
void rotate();
void railFence();

int main () {
    return 0;
}

void rotate(){

}

void swap(){

}

void railFence(){

}

int key(char word){
	return word-97;
}

void Trith(){
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
}

void Caesar(){
	while((message = getchar())!='\n'){
		if(k>=0){
			if(message>64 && message<91){
				if(message>90-k) printf("%c", 65+((k-(91-message))%26));
				else printf("%c",message+k);
			}else if(message>96 && message<123){
				if(message>122-k) printf("%c", 97+((k-(123-message))%26));
				else printf("%c",message+k);
			}else printf("%c",message);
		}else{
			if(message>64 && message<91){
				if(message<65-k) printf("%c", 90-((0-k)-(message-64))%26);
				else printf("%c",message+k);
			}else if(message>96 && message<123){
				if(message<97-k) printf("%c", 122-((0-k)-(message-96))%26);
				else printf("%c",message+k);
			}else printf("%c",message);
				
		}
	}
}

void VigeCipher(){
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
}