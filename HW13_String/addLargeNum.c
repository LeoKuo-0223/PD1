#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

#include<stdbool.h>
void add(char a[], char b[], char res[]) {
    char *ptr_a;
    char *ptr_b;
    int zeroCount;
    int res_place=0;
    bool excess=false;
    char tmp[100]={'\0'};
    char tmp_res[105]={'\0'};

    if(strlen(a)>=strlen(b)) {
        zeroCount=strlen(a)-strlen(b);
        for(int i=0;i<zeroCount;i++){
            tmp[i]='0';
        }
        strcat(tmp,b);
        ptr_a=a;
        ptr_b=tmp;
        while(*ptr_a!='\0') ptr_a++;
        while(*ptr_b!='\0') ptr_b++;
        ptr_a--;ptr_b--;
        res_place=strlen(a)-1;
        for(int i=0;i<strlen(a);i++){
            int sum = (*ptr_a+*ptr_b)-'0';
            if(excess) {
                sum=sum+1;
            }
            if(sum>'9') {
                excess=true;
                sum = sum-10;
                tmp_res[res_place]=sum;
            }else{
                excess=false;
                tmp_res[res_place]=sum;
            }
            res_place--;
            ptr_a--;
            ptr_b--;
        }
        if(excess){
            char addonespace[105]={'1','\0'};
            strcat(addonespace,tmp_res);
            strcpy(res, addonespace);
        }else{
            strcpy(res, tmp_res);
        }



    }else if(strlen(a)<strlen(b)) {
        zeroCount=strlen(b)-strlen(a);
        for(int i=0;i<zeroCount;i++){
            tmp[i]='0';
        }
        strcat(tmp,a);
        ptr_a=tmp;
        ptr_b=b;
        while(*ptr_a!='\0') ptr_a++;
        while(*ptr_b!='\0') ptr_b++;
        ptr_a--;ptr_b--;
        res_place=strlen(b)-1;
        for(int i=0;i<strlen(b);i++){
            int sum = (*ptr_a+*ptr_b)-'0';
            if(excess) {
                sum=sum+1;
            }
            if(sum>'9') {
                excess=true;
                sum = sum-10;
                tmp_res[res_place]=sum;
            }else{
                excess=false;
                tmp_res[res_place]=sum;
            }
            res_place--;
            ptr_a--;
            ptr_b--;
        }
        if(excess){
            char addonespace[105]={'1','\0'};
            strcat(addonespace,tmp_res);
            strcpy(res, addonespace);
        }else{
            strcpy(res, tmp_res);
        }
    }


    
}