#include <stdio.h>
#include <string.h>
#define MAX_LEN_P 100000
#define MAX_LEN_S 100

void strins(char *P, char *s, char *t);

int main() {
  char P[MAX_LEN_P + 1], s[MAX_LEN_S + 2], t[MAX_LEN_S + 2];
  size_t P_len = 0;
  for (char buf[MAX_LEN_P + 1] = ""; strcmp(buf, "---\n"); fgets(buf, MAX_LEN_P + 1, stdin)) {
    size_t len = strlen(buf);
    if (len + P_len > MAX_LEN_P) {
      fprintf(stderr, "The length of the paragraph exceeds %d\n", MAX_LEN_P);
      return 1;
    }
    strncat(P, buf, len + 1);
    P_len += len;
  }
  fgets(s, MAX_LEN_S + 2, stdin);
  s[strlen(s) - 1] = '\0';  // remove newline
  fgets(t, MAX_LEN_S + 2, stdin);
  t[strlen(t) - 1] = '\0';  // remove newline
  strins(P, s, t);
  printf("%s", P);
  return 0;
}
void strins(char *P, char *s, char *t) {
    char *word=P;
    int stringsize = strlen(s);
    char P_temp[MAX_LEN_P+1];
    // printf("len: %d\n",stringsize);
    while(*word!='\0'){
        if(strncmp(word,s,stringsize)==0){
            strncat(P_temp,word,stringsize);
            strcat(P_temp,t);
            word+=stringsize;
        }else{
            strncat(P_temp,word,1);
            word++;
        }

    }
    strcat(P_temp,"\0");
    strcpy(P,P_temp);
}