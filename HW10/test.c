#include <stdio.h>
#include<string.h>
#include <ctype.h>
int comparison(char a[],char b[]);
int main(){
    int N;
    char t[100];
    char ch[100][100];
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",ch[i]);
    }
    for(int i=0;i<N-1;i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if(comparison(ch[i],ch[j])==1)
            {
                strcpy(t,ch[i]);
                strcpy(ch[i],ch[j]);
                strcpy(ch[j],t);
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        printf("%s\n",ch[i]);
    }
    return 0;
}
int comparison(char a[100],char b[100])
{
    char c[100],d[100];
    for(int i=0;i<100;i++)
    {
        c[i]=(char)tolower(a[i]);
        d[i]=(char)tolower(b[i]);
    }
    return strcmp(c,d);
}


