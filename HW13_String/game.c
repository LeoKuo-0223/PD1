#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int dis;
int blood;
int moveCount;
bool dead=false;
bool monsterAlive = true;
bool still_have_command=true;
int readcommand(char command[]){
    char ch;
    int i=0;
    ch=getchar();   //initial ch char value
    while(ch!='\n'&&ch!='.'&&ch!=','){
        command[i] = ch;
        i++;
        ch=getchar();
    }
    command[i] = '\0';
    return i;
}
int main () {
    int legal_command_count=0;
    char attack[] = "PON PON PATA PON";
    char moveforward[] = "PATA PATA PATA PON";
    char defense[] = "CHAKA CHAKA PATA PON";
    char *ptr_command[3];
    char *preCommand;
    char command[22];
    ptr_command[0] = attack;
    ptr_command[1] = moveforward;
    ptr_command[2] = defense;
    scanf("%d %d",&dis,&blood);
    while(getchar()!='\n');
    while(dis>0 && dead==false &&monsterAlive==true){
        for(moveCount=1;moveCount<=30;moveCount++){
            int word_count=readcommand(command);
            if(word_count==0) {
                still_have_command=false;
                break;
            }
            if(moveCount%10==1 && moveCount!=1){    //monster attack
                if(strcmp(preCommand,defense)==0){
                    dead=false;
                }else{
                    dead=true;
                    break;
                }

            }
            if(strcmp(command,attack)==0){
                legal_command_count++;
                preCommand = ptr_command[0];
                if(dis<=3){
                    blood--;
                    if(blood<=0) {
                        monsterAlive=false;
                        break;
                    }
                }
            }else if(strcmp(command,moveforward)==0){
                legal_command_count++;
                preCommand = ptr_command[1];
                dis--;
                if(dis<=0) {
                    dead=true;
                    break;
                }
            }else if(strcmp(command,defense)==0){
                legal_command_count++;
                preCommand = ptr_command[2];
                dis++;
            }
        }
        if(still_have_command=false) break;
        if(moveCount>30) break;
    }
    if(dead==false && monsterAlive==false){ //not dead and monster die
        printf("YES %d",legal_command_count);
    }else if(dead==false && monsterAlive==true){ //command run out and monster is alive
        printf("NO %d",blood);
    }else if(dead==true){   //player died
        printf("NO %d",blood);
    }

    return 0;
}