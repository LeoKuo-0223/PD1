#include<stdio.h>
int numRoom;
int nextRoomIndex;
void Path();
void printPath();
int main(){
	scanf("%d",&numRoom);
	int room[numRoom];
	int record[numRoom];
	int path[numRoom];
	int nextcircle[numRoom];
	for(int i=0;i<numRoom;i++){
		scanf("%d",&room[i]);
		record[i]=0;
	}
	Path(record,room);
	for(int i=0;i<numRoom;i++) record[i]=0;//reset record
	printPath(record,room);
}
void Path(int* record,int* room){
int ringcount=0;
int minIndex=0;
	while(1){
		int flag=1;
		for(int i=0;i<numRoom;i++){
			if(record[i]==0){
				minIndex = i;
				flag = 0;
				break;
			}
		}
		if(flag) break;
		nextRoomIndex=minIndex;
		while(1){
			record[nextRoomIndex]=1;
			nextRoomIndex = room[nextRoomIndex];
			if(nextRoomIndex==minIndex){
				break;
			}
		}
		ringcount++;
	}
	printf("%d rings\n",ringcount);
}
void printPath(int* record,int* room){
int ringcount=0;
int minIndex=0;
	while(1){
		int flag=1;
		for(int i=0;i<numRoom;i++){
			if(record[i]==0){
				minIndex = i;
				//printf("Index %d \n",minIndex);
				flag = 0;
				break;
			}
		}
		if(flag) break;
		nextRoomIndex=minIndex;
		//printf("index %d record: %d\n",nextRoomIndex,record[nextRoomIndex]);
		printf("%d",minIndex);
		while(1){
			printf(" -> ");
			printf("%d",room[nextRoomIndex]);
			record[nextRoomIndex]=1;
			nextRoomIndex = room[nextRoomIndex];
			if(nextRoomIndex==minIndex){
				printf("\n");
				break;
			}
		}
		ringcount++;
	}
	//printf("%d rings\n",ringcount);
}
