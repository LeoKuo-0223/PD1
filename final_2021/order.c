#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};

int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}
int cmp(const void* a, const void* b) {
    char *ptr_a=(char*)a;
    char *ptr_b = (char*)b;
    int la=strlen(ptr_a);
    int lb=strlen(ptr_b);
    // return strlen(ptr_a)-strlen(ptr_b);
    int compare=strlen(ptr_a)-strlen(ptr_b);
    if(compare==0){
        for(;;){
            if(*ptr_a<*ptr_b) return -1;
            else if(*ptr_a>*ptr_b) return 1;
            else{
                ptr_a++;
                ptr_b++;
            }
        }
    }else if(compare<0) return -1;
    else{
        return 1;
    }
}
void recovering_order(char *order, char **result) {
    *result=malloc(sizeof(char*)*100);
    **result='\0';
    // int total_count=0;
    char possible[30][15]={"\0"};
    int possible_count=0;
    char *token;
    token=strtok(order,":");
    int txt_len=strlen(token);
    // printf("%s",names[0]);
    while(token!=NULL){
        int txt_len=strlen(token);
        for(int i=0;i<GOODS_SIZE;i++){
            char *txt_ptr;
            char *name_ptr;
            txt_ptr=token;
            name_ptr=names[i];
            int length_g=strlen(name_ptr);
            int length_t=strlen(txt_ptr);
            while(strlen(name_ptr)>=strlen(txt_ptr)){
                if(strncmp(name_ptr,txt_ptr,strlen(txt_ptr))==0){
                    strcpy(possible[possible_count],names[i]);
                    possible_count++;
                    break;
                }else{
                    name_ptr++;
                }

            }
            
        }
        char *ptr_sort[possible_count];
        for(int j=0;j<possible_count;j++){
            ptr_sort[j]=possible[j];
        }
        qsort(ptr_sort,possible_count,sizeof(char*),cmp);
        strcat(*result,ptr_sort[0]);
        

        // total_count++;
        // printf("%s+",ptr_sort[0]);
        possible_count=0;
        token=strtok(NULL,":");
        if(token!=NULL) strcat(*result,"+");
    }
    return;
}