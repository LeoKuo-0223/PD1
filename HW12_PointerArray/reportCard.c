#include <stdio.h>
int *report_card (int *s) ;

int main () {
    int score[1001];
    int *show;
    int count = 0;

    do {
        scanf("%d", &score[count++]);
    } while (score[count - 1] != -1);

    show = report_card(score);

    count = 0;
    while (*(show + count) != -1) {
        printf("%d ", *(show + count));
        count++;
    }
}

int *report_card (int *s) {
    int *p;
    int static show[1001];
    int count=0;
    int max_length=0;
    int max_value=0;
    int value;
    int record_index;
    int i=0;
    for(p=s;*p!=-1;p++){
        if(*p>=60){
            value+=*p;
            count++;
        }else{
            if(count>max_length){
                record_index=i;
                max_value = value;
                max_length = count;
            }else if(count==max_length){
                if(value>max_value){
                    record_index=i;
                    max_value = value;
                    max_length = count;
                }
            }
            count=0;
            value=0;
        }
        i++;
    }
    if(count>max_length){
            record_index=i;
            max_value = value;
            max_length = count;
        }else if(count==max_length){
            if(value>max_value){
                record_index=i;
                max_value = value;
                max_length = count;
            }
        }
    int start = record_index-max_length;
    int j=0;
    for(int k=start;k<record_index;k++){
        show[j] = s[k];
        j++;
    }
    show[j] = -1;
    return show;

}