#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}

void find_fruit(char input[],char fruit[][15]){
// input is the fruit sequence eg: watermelon+_+watermelon+_+coconut+_+grape+_+coconut
// fruit is 20 kinds of fruit name eg: fruit[0] is "guava", fruit[1] is litchi and so on. 
// you need to check the Loader code to understand above meaning 
    int record[20]={0};
    char *eachfruit=strtok(input,"+_+");
    while (eachfruit!=NULL){
        for(int i=0;i<20;i++){
            if(strcmp(eachfruit,fruit[i])==0){
                record[i]++;
            }
        }
        eachfruit = strtok(NULL,"+_+");
    }
    int maxNum_Index=0;
    int max=0;
    for(int i=0;i<20;i++){
        if(record[i]>max){
            max=record[i];
            maxNum_Index=i;
        }
    }
    printf("%s\n",fruit[maxNum_Index]);
    for(int i=maxNum_Index+1;i<20;i++){
        if(record[i]==max) printf("%s\n",fruit[i]);
    }

}