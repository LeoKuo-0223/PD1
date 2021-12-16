#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void Print(char* str);
void Remove(char* str,char target);
void Reverse(char* str);
void To_Upper(char* str);
void To_Lowwer(char* str);
void Compress(char* str);
int main(){
    char word;
    char str[3000]={'\0'};
    int size=0;
    int num;
    char action[20]={'\0'};
    char print[]="PRINT";char reverse[]="REVERSE";char remove[]="REMOVE";
    char Upper[]="TO_UPPER";char Lower[]="TO_LOWER";char compress[]="COMPRESS";
    while((word=getchar())!='\n'){
        str[size] = word;
        size++;
    }
    str[size] = '\0';
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",action);
        if(!strcmp(action,print)){
            Print(str);
        }else if(!strcmp(action,reverse)){
            Reverse(str);
        }else if(!strcmp(action,remove)){
            char target;
            while(getchar()!=' ');
            target = getchar();
            Remove(str,target);
        }else if(!strcmp(action,Upper)){
            To_Upper(str);
        }else if(!strcmp(action,Lower)){
            To_Lowwer(str);
        }else if(!strcmp(action,compress)){
            Compress(str);
        }
    }
    return 0;
}


void Print(char* str){
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
void Remove(char* str,char target){
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=target){
            count++;
        }
    }
    int temp[count];
    int k=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=target){
            temp[k] = str[i];
            k++;
        }
    }
    for(int i=0;i<k;i++){
        str[i] = temp[i];
    }
    str[k] = '\0';
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
void Reverse(char* str){
    char temp[3000];
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        temp[i] = str[i];
        count++;
    }
    for(int i=0;i<count;i++){
        str[i] = temp[(count-i)-1];
    }
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
void To_Upper(char* str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i]-32;
        }
    }
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");

}
void To_Lowwer(char* str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i]+32;
        }
    }
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}
char IntegerToStr(int integer){
 return integer+48;
}
void Compress(char* str){
    int record[500]={0};//紀錄每種字元重複的數量
    int count=0;
    char record_nonrepeat[200]={'\0'}; //紀錄不重複的字元
    char pre;
    pre=str[0];
    record_nonrepeat[count] = str[0];
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==pre){
            record[count]++;
        }else{
            pre=str[i];
            record_nonrepeat[count+1] = pre;
            count++;
            record[count]++;
        }

    }
    int index=0;
    int count__ = 0; //改2. 141行變數宣告而已
    for(int i=0;i<count+1;i++){
        str[index] = '-';
        str[index+1] = record_nonrepeat[i];
        if(record[count__]<=9){   
            str[index+2]=IntegerToStr(record[i]);
            index = index+3;
        }else{
            index = index+2; //因為前面已經放了'-'跟char字元
            int tmp = record[i];
            int place_value = 0;
            int next_gap = 0;
            int exp=1;
            for(;;){
                if(tmp/exp==0){
                    break;
                }else{
                    exp*=10;
                    place_value++;
                }
            }
            place_value--; //若是四位數字，則只需要多出三個空間
            next_gap = place_value+1;
            while(tmp!=0){
                int oneth = tmp%10;
                str[index+place_value]=IntegerToStr(oneth);  
                place_value--;
                tmp/=10;
            }
            index += next_gap;
        }
        count__++; 
    }
    str[index] = '\0';
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]);
    }
    printf("\n");
}