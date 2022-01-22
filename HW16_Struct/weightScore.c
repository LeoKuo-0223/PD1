#include <stdio.h>

struct weight {
    char chapter[10];
    int percent;
};

struct score {
    char chapter[10];
    int score;
};

struct report_card {
    char name[32];
    struct score record[10];
    int final;
    int max_score;
    int min_score;
};

void calculate (struct report_card[], struct weight[], int student_num, int chapter_num);

int main () {
    int student_num, chapter_num;
    struct weight chapter[10];
    struct report_card card[100];

    scanf("%d %d\n", &chapter_num, &student_num);
    for (int i = 0; i < chapter_num; ++i) {
        scanf("%d %s", &chapter[i].percent, chapter[i].chapter);
    }

    for (int i = 0; i < student_num; ++i) {
        scanf("%s", card[i].name);
        for (int j = 0; j < chapter_num; ++j) {
            scanf("%d %s", &card[i].record[j].score, card[i].record[j].chapter);
        }
    }

    calculate(card, chapter, student_num, chapter_num);

    for (int i = 0; i < student_num; ++i) {
        printf("%s %d %d %d\n", card[i].name, card[i].final, card[i].max_score, card[i].min_score);
    }
}

#include<string.h>
void calculate (struct report_card card[], struct weight chapter[], int student_num, int chapter_num) {
    for(int i=0;i<student_num;i++){
        int total=0;
        int Max=0;
        int min=101;
        for(int j=0;j<chapter_num;j++){
            for(int s=0;s<chapter_num;s++){
                if(strcmp(card[i].record[j].chapter,chapter[s].chapter)==0){
                    total+=(card[i].record[j].score*(chapter[s].percent));
                }
            }

            if(card[i].record[j].score>Max) Max=card[i].record[j].score;
            if(card[i].record[j].score<min) min=card[i].record[j].score;
            
        }
        int final_score = total/100;
        card[i].max_score=Max;
        card[i].min_score=min;
        card[i].final = final_score;
    }
}