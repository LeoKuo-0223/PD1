#include <stdio.h>
#define NUM 9

void check_sudoku(int grid_p[][NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int grid_p[][NUM]){

    int rowRecord[NUM]={0};
    int colRecord[NUM]={0};
    for(int i=0;i<NUM;i++){
        for(int j=0;j<NUM;j++){
            int indexR = grid_p[i][j];
            int indexC = grid_p[j][i];
            rowRecord[indexR]++;
            colRecord[indexC]++;
        }
        for(int k=0;k<NUM;k++){
            if(rowRecord[k]!=1){

            }
        }
       
    }
}