#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void VigeCipher(char*,char*,int,int);
int keyToInteger(char word);
void Trith(char*,int,char,int);
void Caesar(char*,int,int);
void swap(char*,int);
void rotate(char*,int,char,int);
void railFence(char*, int*,int,int);
int encodetype;
char target[64];
char output[64];
int size = (int)(sizeof(target)/sizeof(target[0]));
int main () {
    char message;
    char pretarget[32];
    char posttarget[32];
    int wordcount=0;
    scanf("%d",&encodetype);
    while(getchar()!='\n');
    while( (message = getchar())!='\n'){
        target[wordcount] = message;
        wordcount++;
    }
    if(encodetype==1){
        char key[4]={'m','e','o','w'};
        int key_size = (int)(sizeof(key)/sizeof(key[0]));
        swap(target,size);
        for(int i=0;i<32;i++){
            pretarget[i] = target[i];
            posttarget[i] = target[32+i];
        }
        Caesar(pretarget,13,size/2);
        VigeCipher(posttarget,key,size/2,key_size);
        for(int i=0;i<64;i++){
            if(i<32){
                target[i] =pretarget[i];
            }else{
                target[i] = posttarget[i-32];
            }
        }
        rotate(target,3,'l',size);
    }else if(encodetype==2){
        int key[8]={4,3,1,2,7,6,5,8};
        int key_size = (int)(sizeof(key)/sizeof(key[0]));
        rotate(target,11,'r',size);
        Trith(target,74,'a',size);
        for(int i=0;i<32;i++){
            pretarget[i] = target[i];
            posttarget[i] = target[32+i];
        }
        rotate(pretarget,1,'r',size/2);
        rotate(posttarget,3,'r',size/2);
        for(int i=0;i<64;i++){
            if(i<32){
                target[i] =pretarget[i];
            }else{
                target[i] = posttarget[i-32];
            }
        }
        railFence(target,key,size,key_size);
    }else if(encodetype==3){
        int key1[4] = {3,2,4,1};
        int key2[8] = {1,8,4,3,6,5,7,2};
        int key1_size = (int)(sizeof(key1)/sizeof(key1[0]));
        int key2_size = (int)(sizeof(key2)/sizeof(key2[0]));
        railFence(target,key1,size,key1_size);
        for(int i=0;i<32;i++){
            pretarget[i] = target[i];
            posttarget[i] = target[32+i];
        }
        Caesar(pretarget,8,size/2);
        railFence(posttarget,key2,size/2,key2_size);
        for(int i=0;i<64;i++){
            if(i<32){
                target[i] =pretarget[i];
            }else{
                target[i] = posttarget[i-32];
            }
        }
        swap(target,size);
        Trith(target,602,'d',size);
        rotate(target,7,'r',size);
    }else if(encodetype==4){
        char key[8]={'v','i','g','e','n','e','r','e'};
        int key_size = (int)(sizeof(key)/sizeof(key[0]));
        for(int i=0;i<32;i++){
            pretarget[i] = target[i];
            posttarget[i] = target[32+i];
        }
        VigeCipher(pretarget,key,size/2,key_size);
        swap(pretarget,size/2);
        Trith(pretarget,3,'a',size/2);
        rotate(posttarget,24,'l',size/2);
        for(int i=0;i<64;i++){
            if(i<32){
                target[i] =pretarget[i];
            }else{
                target[i] = posttarget[i-32];
            }
        }
        rotate(target,19,'r',size);
    }else if(encodetype==5){
        int key1[8]={3,1,7,6,4,5,2,8};
        int key2[4] = {2,4,1,3};
        int key1_size = (int)(sizeof(key1)/sizeof(key1[0]));
        int key2_size = (int)(sizeof(key2)/sizeof(key2[0]));
        railFence(target,key1,size,key1_size);
        for(int i=0;i<32;i++){
            pretarget[i] = target[i];
            posttarget[i] = target[32+i];
        }
        Caesar(pretarget,10,size/2);
        railFence(posttarget,key2,size/2,key2_size);
        for(int i=0;i<64;i++){
            if(i<32){
                target[i] =pretarget[i];
            }else{
                target[i] = posttarget[i-32];
            }
        }
        swap(target,size);
        Trith(target,52,'a',size);
        rotate(target,7,'r',size);

    }
    for(int i=0;i<size;i++){
        printf("%c",target[i]);
    }
    return 0;
}

void rotate(char* target,int step,char dir,int size){
    char temp[size];
    for(int i=0;i<size;i++){
        temp[i]=target[i];
    }
    if(dir=='r'){
        for(int i=0;i<size;i++){            
            target[(i+step)%size] = temp[i];
        }
    }else{
        for(int i=0;i<size;i++){
            target[i] = temp[(i+step)%size];
        }
    }
}

void swap(char* target,int size){
    
    char pre[size/2],post[size/2];
    for(int i=0;i<size/2;i++){
        pre[i] = target[i];
        post[i] = target[size/2+i];
    }
    for(int i=0;i<size;i++){
        if(i<(size/2)){
            target[i] =post[i];
        }else{
            target[i] = pre[i-(size/2)];
        }
    }
}

void railFence(char* target,int* key,int target_size,int key_size){
    int count=0;
    char temp[target_size];
    for(int i=0;i<target_size;i++){
        temp[i]=target[i];
    }
    int termimal = (target_size/key_size);
    for(int i=0;i<termimal*key_size;i++){
        if(i%key_size==0&&i!=0) count++;
        target[(key_size*count)+(key[i%key_size]-1)] = temp[i];
    }
}



void Trith(char* target,int k,char movetype,int target_size){
    
    if(movetype=='a'){
        for(int i=0;i<target_size;i++){
            char message = target[i]; 
            // printf("|%d*",key(code[k]));
            if(k>=0){
                if(message>64 && message<91){
                    if(message>90-k) target[i] = 65+((k-(91-message))%26);   //printf("%c", 65+((k-(91-message))%26));
                    else target[i] = message+k;//printf("%c",message+k);
                    k++;
                    
                }else if(message>96 && message<123){
                    if(message>122-k) target[i] = 97+((k-(123-message))%26);//printf("%c", 97+((k-(123-message))%26));
                    else target[i] = message+k;//printf("%c",message+k);
                    k++;
                    
                }else target[i] = message;//printf("%c",message);
            }else{
			if(message>64 && message<91){
				if(message<65-k) target[i] =90-((0-k)-(message-64))%26; //printf("%c", 90-((0-k)-(message-64))%26);
				else target[i] = message+k;//printf("%c",message+k);
                 k++;
			}else if(message>96 && message<123){
				if(message<97-k) target[i] = 122-((0-k)-(message-96))%26;//printf("%c", 122-((0-k)-(message-96))%26);
				else target[i] = message+k;//printf("%c",message+k);
                 k++;
			}else target[i] = message;//printf("%c",message);
				
		}
            


        }
    }else if(movetype=='d'){
        
        for(int i=0;i<target_size;i++){
            // printf("|%d*",key(code[k]));
            char message = target[i];
            if(k>=0){
                if(message>64 && message<91){
                    if(message>90-k) target[i] = 65+((k-(91-message))%26);//printf("%c", 65+((k-(91-message))%26));
                    else target[i] = message+k;//printf("%c",message+k);
                    k--;
                    
                }else if(message>96 && message<123){
                    if(message>122-k) target[i] = 97+((k-(123-message))%26);//printf("%c", 97+((k-(123-message))%26));
                    else target[i] = message+k;//printf("%c",message+k);
                    k--;
                    
                }else target[i] = message;//printf("%c",message);
            }else{
			if(message>64 && message<91){
				if(message<65-k) target[i] = 90-((0-k)-(message-64))%26;//printf("%c", 90-((0-k)-(message-64))%26);
				else target[i] = message+k;//printf("%c",message+k);
                k--;
			}else if(message>96 && message<123){
				if(message<97-k) target[i] = 122-((0-k)-(message-96))%26;//printf("%c", 122-((0-k)-(message-96))%26);
				else printf("%c",message+k);
                k--;
			}else target[i] = message;//printf("%c",message);
				
		}
            


        }
    }
}

void Caesar(char* target,int k,int target_size){
    
	for(int i=0;i<target_size;i++){
        char message = target[i];
		if(k>=0){
			if(message>64 && message<91){
				if(message>90-k) target[i] =65+((k-(91-message))%26); //printf("%c", 65+((k-(91-message))%26));
				else target[i] = message+k;//printf("%c",message+k);
			}else if(message>96 && message<123){
				if(message>122-k) target[i] =97+((k-(123-message))%26); //printf("%c", 97+((k-(123-message))%26));
				else target[i] = message+k;//printf("%c",message+k);
			}else target[i] = message;//printf("%c",message);
		}else{
			if(message>64 && message<91){
				if(message<65-k) target[i] = 90-((0-k)-(message-64))%26;//printf("%c", 90-((0-k)-(message-64))%26);
				else target[i] = message+k;//printf("%c",message+k);
			}else if(message>96 && message<123){
				if(message<97-k) target[i] = 122-((0-k)-(message-96))%26;//printf("%c", 122-((0-k)-(message-96))%26);
				else target[i] = message+k;//printf("%c",message+k);
			}else target[i] = message;//printf("%c",message);
				
		}
	}
}

int keyToInteger(char word){
	return word-97;
}

void VigeCipher(char* target,char* key,int target_size,int key_size){
    
    int s=0;
    for(int i=0;i<target_size;i++){
        char message = target[i];
        // printf("|%d*",key(code[k]));
        int k=keyToInteger(key[s]);
        if(k>=0){
            if(message>64 && message<91){
                if(message>90-k) target[i] = 65+((k-(91-message))%26);//printf("%c", 65+((k-(91-message))%26));
                else target[i] = message+k;//printf("%c",message+k);
                s++;
                if(s>key_size-1) s=s%(key_size);
            }else if(message>96 && message<123){
                if(message>122-k) target[i] = 97+((k-(123-message))%26);//printf("%c", 97+((k-(123-message))%26));
                else target[i] = message+k;//printf("%c",message+k);
                s++;
                if(s>key_size-1) s=s%(key_size);
            }else target[i] = message;//printf("%c",message);
        }


    }
}