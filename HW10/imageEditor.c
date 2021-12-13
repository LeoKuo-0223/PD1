#include<stdio.h>
#include<stdbool.h>
int row=0,col=0;
char mode;
int num;
char dir;
int times;
int up,down,left,right;
bool reverse;
bool cutted = false;
int left_edge=0,right_edge=0,up_edge=0,down_edge=0;
void rotate(int img[][col],int result[][row],char dir,int row,int col);
void horizontal(int img[][col],int r,int c);
void vertical(int img[][col],int r,int c);
void show(int img[][col], int, int);

int main () {
    scanf("%d %d",&row,&col);
    int img[row][col];
    int img_r[col][row];
    reverse = false;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&img[i][j]);
        }
    }
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        while(getchar()!='\n');
        scanf("%c",&mode);
        switch(mode){
            case 'r':
                scanf(" %c %d",&dir,&times);
                times = times%4;
                for(int s=0;s<times;s++){
                    int result[col][row];
                    if(reverse==false){
                        rotate(img,result,dir,row,col);
                        reverse=true;                           
                        for(int j=0;j<col;j++){
                            for(int k=0;k<row;k++){
                                img_r[j][k] = result[j][k];
                            }
                        }
                            int tmp = col;
                            col = row;
                            row = tmp;
                    }else{
                        rotate(img_r,result,dir,row,col);
                        reverse=false;
                        for(int j=0;j<col;j++){
                            for(int k=0;k<row;k++){
                                img[j][k] = result[j][k];
                            }
                        }
                            int tmp = col;
                            col = row;
                            row = tmp;
                    }

                }

                break;
            case 'v':
                if(reverse==true){
                    vertical(img_r,row,col);
                }else{
                    vertical(img,row,col);
                }

                break;
            case 'h':
                if(reverse==true){
                    horizontal(img_r,row,col);
                }else{
                    horizontal(img,row,col);
                }

                break;
            case 'c':
                scanf(" %d %d %d %d",&left,&right,&up,&down);
                down_edge = up_edge+(down-1);
                up_edge = up_edge+(up-1);
                right_edge = left_edge+(right-1);
                left_edge = left_edge+(left-1);
                cutted = true;
                if(reverse==true){

                    
                    for(int j=0;j<row;j++){
                        for(int k=0;k<col;k++){
                            if(j>=up_edge && j<=down_edge && k>=left_edge && k<=right_edge){
                                img_r[j][k] = img_r[j][k];
                            }else{
                                img_r[j][k] = -1;
                            }
                        }
                    }
                    
                }else{
                    for(int j=0;j<row;j++){
                        for(int k=0;k<col;k++){
                            if(j>=up_edge && j<=down_edge && k>=left_edge && k<=right_edge){
                                img[j][k] = img[j][k];
                            }else{
                                img[j][k] = -1;
                            }
                        }
                    }
                }

                break;
            case 'p':
                if(reverse==true){
                    show(img_r,row,col);
                }else{
                    show(img,row,col);
                }
                break;
            default:
                break;

        }
    }
    return 0;
}


void rotate(int img[][col],int result[][row],char dir,int r,int c){
    
    if(dir=='r'){
        if(cutted){//border rotate
            int up_tmp = up_edge;
            int down_temp = down_edge;
            up_edge = col-(col-left_edge);
            down_edge = up_edge+(right_edge-left_edge);
            left_edge = (row-1)-down_temp;
            right_edge = left_edge+(down_temp-up_tmp);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                result[j][(r-1)-i] = img[i][j];
            }
        }
        
    }else{
        if(cutted){
            int up_tmp = up_edge;
            int down_temp = down_edge;
            up_edge= (col-1)-right_edge;
            down_edge = up_edge+(right_edge-left_edge);
            left_edge = row-(row-up_tmp);
            right_edge = left_edge+(down_temp-up_tmp);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                result[(c-1)-j][i] = img[i][j];
            }
        }
    }

    

}
void horizontal(int img[][col],int r,int c){
    int result[r][c];
    for(int i=0;i<r;i++){
        for(int j=c-1;j>=0;j--){
            result[i][j] = img[i][c-j-1];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            img[i][j] = result[i][j];
        }
    }
    if(cutted){
        int left_tmp = left_edge;
        left_edge = (col-1)-right_edge;
        right_edge = left_edge+(right_edge-left_tmp);
    }

}
void vertical(int img[][col],int r,int c){
    int result[r][c];
    for(int i=r-1;i>=0;i--){
        for(int j=0;j<c;j++){
            result[r-i-1][j] = img[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            img[i][j] = result[i][j];
        }
    }
    if(cutted){
        int up_tmp = up_edge;
        up_edge = (row-1)-down_edge;
        down_edge = up_edge+(down_edge-up_tmp);
    }
}
void show(int img[][col],int row,int col){
    if(cutted==true){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(img[i][j]!=-1){
                    if(j==right_edge){
                        printf("%d",img[i][j]);
                    }else printf("%d ",img[i][j]);
                }

            }
            if(i>=up_edge && i<=down_edge){
                printf("\n");
            }
        }
        printf("\n");
    }else{
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(j==col-1){
                printf("%d",img[i][j]);
                }else  printf("%d ",img[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    //printf(" ");
}