#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rising_hope(char *R);

int main(int argc, char *argv[])
{
    char in[1005];

    scanf("%s", in);
    int hope = rising_hope(in);
    printf("%d\n", hope);

    return 0;
}
int rising_hope(char *R) {
    int tmp=0;
    char *ptr=R;
    for(ptr;*ptr!='\0';ptr++){
        if(*ptr=='P'){
            tmp++;
        }else if(*ptr=='N'){
            tmp--;
        }else{
            continue;
        }
    }
    return tmp;
}