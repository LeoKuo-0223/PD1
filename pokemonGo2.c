#include<stdio.h>
int numBattle,a,b,a_numWin,b_numWin;
int numWinBattle=0;
int main(){
	scanf("%d",&numBattle);
	for(int j=0;j<numBattle;j++){
		a_numWin=0;
		b_numWin=0;
		for(int i=0;i<3;i++){
			scanf("%d %d",&a,&b);
			if(a>b) a_numWin++;
			else if(a<b) b_numWin++;
		}
		if(a_numWin>b_numWin) {numWinBattle++;printf("Win\n");}
		else if(a_numWin==b_numWin) printf("Tie\n");
		else printf("Lose\n");
		
	}
	printf("%.2f%%",(numWinBattle*1.00/numBattle)*100);
}
