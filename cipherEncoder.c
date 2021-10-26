#include<stdio.h>
int k;
char message;
int main(){
	scanf("%d",&k);
	while(getchar()!='\n');
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

