#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int num;
void sort_pointers(char **ptr_arr , char name[][101], int );
bool check(char name1[], char name2[]);
int main () {
    char name[100][101];
    scanf("%d",&num);
    char *parray[num];
    for(int i=0;i<num;i++){
        scanf("%s",name[i]);
    }
    sort_pointers(parray,name,num);
    for(int i=0;i<num;i++){
        printf("%s\n",parray[i]);
    }
    return 0;
}


void sort_pointers(char **ptr_arr, char name[][101], int size){
    char min[101];
    char *min_address;
    int min_index;
	for(int i=0;i<size;i++){
     ptr_arr[i] = name[i];
    }
    for(int i=0;i<size;i++){
        strcpy(min,ptr_arr[i]);
        min_address = ptr_arr[i];
        min_index=i;
        for(int j=i+1;j<size;j++){
            if(check(ptr_arr[j],min)){
                strcpy(min,ptr_arr[j]);
                min_address = ptr_arr[j];
                min_index=j;
            }
        }
        char *tmp;//記得將兩個值交換位置，避免再次找到重複的值
        tmp = ptr_arr[i];
        ptr_arr[i] = min_address;
        ptr_arr[min_index] = tmp;
    }
    
    
}

bool check(char name1[], char name2[]){
    int length1 = strlen(name1);
    int length2 = strlen(name2);
    char tmp_name1[length1+1];
    char tmp_name2[length2+1];
    strcpy(tmp_name1,name1); 
    strcpy(tmp_name2,name2);
    
    for(int i=0;i<length1;i++){
        if ('a' <= tmp_name1[i] && tmp_name1[i] <= 'z') {
            tmp_name1[i] = tmp_name1[i] - 'a' + 'A';	//強制大寫
        }
    }

    for(int i=0;i<length2;i++){
        if ('a' <= tmp_name2[i] && tmp_name2[i] <= 'z') {
            tmp_name2[i] = tmp_name2[i] - 'a' + 'A';	//強制大寫
        }
    }
    int k;  //k=1 =>smaller than the min , k=2 => bigger than the min
    if(length1<length2){
        k=1;
        for (int i = 0; i < length1; i++) {
            if (tmp_name1[i] < tmp_name2[i]) {
                k = 1;
                break;
            }
            else if (tmp_name1[i] > tmp_name2[i]) {
                k = 2;
                break;
            }
        }
    }else{
        k=2;
        for (int i = 0; i < length2; i++) {
            if (tmp_name1[i] < tmp_name2[i]) {
                k = 1;
                break;
            }
            else if (tmp_name1[i] > tmp_name2[i]) {
                k = 2;
                break;
            }
        }

    }
    if(k==1){
        return true;
    }else{
        return false;
    }
}

