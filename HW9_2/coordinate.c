#include<stdio.h>
#define N 10000

long transfer(char word);
void decode(char a[],long num);
void decimalToHex(long decimal,long num);

int main () {
    char message;
    char array[N];
    long index=0;
    while((message = getchar())!='\n'){
        array[index]=message;
        index++;
    }
    decode(array,index);
    return 0;
}

void decode(char a[],long num){
    if(num>1){
        long oddSum=0;
        long evenSum=0;
        if(num%2==0){
            for(long i=0;i<num;i+=2){
                oddSum+=transfer(a[i+1]);
                evenSum+=transfer(a[i]);
            }
            decimalToHex(oddSum,num);
            decimalToHex(evenSum,num);
        }else if(num%2==1){
            
            for(long i=0;i<num;i+=2){
                evenSum+=transfer(a[i]);
                
            }
            for(long i=1;i<num;i+=2){
                oddSum+=transfer(a[i]);
            }
            decimalToHex(oddSum,num);
            decimalToHex(evenSum,num);

        }
        



    }else{
        if(a[0]>=65 && a[0]<=90){
            printf("%c",a[0]+32);
        }else printf("%c",a[0]);
    }
}

void decimalToHex(long decimal,long num){
    long i=0;
    char array[num];
    if(decimal==0) {// for 0 just output 0
        i=1;
        array[0]='0';
    }
    while(decimal!=0){
        long temp=0;
        temp = decimal%16;
        decimal/=16;
        if (temp < 10) {
            array[i] = temp + 48;
            i++;
        }
        else {
            array[i] = temp + 55;
            i++;
        }
    }
    
    char next_array[i];
    long count=i-1;
    for(long j=0;j<i;j++){//reverse array
        next_array[j] = array[count];
        count--;
    }
    decode(next_array,i);
}

long transfer(char word){
    if(word>=48 && word<=57){
        return word-48;
    }else{
        switch(word){
            case 'a':case 'A':
                return 10;
                break;
            case 'b':case 'B':
                return 11;
                break;
            case 'c':case 'C':
                return 12;
                break;
            case 'd':case 'D':
                return 13;
                break;
            case 'e':case 'E':
                return 14;
                break;
            case 'f':case 'F':
                return 15;
                break;
            default:
                printf("error");
                break;

        }
    }
}

