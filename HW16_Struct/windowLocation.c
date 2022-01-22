#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
#include<stdbool.h>
Location *parse_url(char *url)
{
    Location *tmp = malloc(sizeof(Location));
    bool portExist=true;
    bool pathnameExist=true;
    bool searchExist=true;
    bool hashExist=true;
    bool over=false;
    char *ptr;
    char text[100];
    int count=0;
    for(ptr=url;*ptr!=':';ptr++){
        text[count]=*ptr;
        count++;
    }
    text[count]='\0';
    tmp->protocol=malloc(sizeof(char)*(count+1));
    strcpy(tmp->protocol,text);
    while(*ptr=='/'||*ptr==':') ptr++;
    count=0;
    for(;*ptr!=':';ptr++){
        if(*ptr=='/'||*ptr=='\n') {
            if(*ptr=='\n'){
                over=true;
            }else if(*ptr='/') portExist=false;
            break;
        }
        text[count]=*ptr;
        count++;
    }
    text[count]='\0';
    tmp->host=malloc(sizeof(char)*(count+1));
    strcpy(tmp->host,text);
    if(over){
        tmp->pathname=malloc(sizeof(char)*1);
        tmp->search=malloc(sizeof(char)*1);
        tmp->hash=malloc(sizeof(char)*1);
        *(tmp->pathname)='\0';
        *(tmp->search)='\0';
        *(tmp->hash)='\0';
        tmp->port=0;
        return tmp;
    }

    if(portExist==true){
        count=0;
        for(ptr++;*ptr!='/'&&*ptr!='#'&&*ptr!='?';ptr++){
            if(*ptr=='\n'){
                over=true;
                break;
            }
            text[count]=*ptr;
            count++;
        }
        text[count]='\0';
        tmp->port=atoi(text);
    }else{
        tmp->port=0;
    }

    if(over){
        tmp->pathname=malloc(sizeof(char)*1);
        tmp->search=malloc(sizeof(char)*1);
        tmp->hash=malloc(sizeof(char)*1);
        *(tmp->pathname)='\0';
        *(tmp->search)='\0';
        *(tmp->hash)='\0';
        return tmp;
    }

    count=0;
    if(*ptr=='/'&&pathnameExist==true){
        for(ptr++;*ptr!='?'&&*ptr!='#';ptr++){
            if(*ptr=='\n'){
                over=true;
                break;
            }
            text[count]=*ptr;
            count++;
        }
        text[count]='\0';
        tmp->pathname=malloc(sizeof(char)*(count+1));
        strcpy(tmp->pathname,text);
    }else{
        tmp->pathname=malloc(sizeof(char)*1);
        *(tmp->pathname)='\0';
    }

    if(over){
        tmp->search=malloc(sizeof(char)*1);
        tmp->hash=malloc(sizeof(char)*1);
        *(tmp->search)='\0';
        *(tmp->hash)='\0';
        return tmp;
    }

    count=0;
    if(*ptr=='?'&&searchExist==true){
        for(ptr++;*ptr!='#';ptr++){
            if(*ptr=='\0'||*ptr=='\n'){
                over=true;
                break;
            }
            text[count]=*ptr;
            count++;
        }
        text[count]='\0';
        tmp->search=malloc(sizeof(char)*(count+1));
        strcpy(tmp->search,text);
    }else{
        tmp->search=malloc(sizeof(char)*1);
        *(tmp->search)='\0';
    }

    if(over){
        tmp->hash=malloc(sizeof(char)*1);
        *(tmp->hash)='\0';
        return tmp;
    }

    count=0;
    if(*ptr=='#'&&hashExist==true){
        for(ptr++;*ptr!='\n';ptr++){
            text[count]=*ptr;
            count++;
        }
        text[count]='\0';
        tmp->hash=malloc(sizeof(char)*(count+1));
        strcpy(tmp->hash,text);
    }else{
        tmp->hash=malloc(sizeof(char)*1);
        *(tmp->hash)='\0';
    }
    return tmp; 
}