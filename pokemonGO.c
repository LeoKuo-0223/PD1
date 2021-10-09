#include<stdio.h>
int num,cp,hp,s;
int main(){
	scanf("%d",&num);
	scanf("%d %d",&cp,&hp);
	scanf("%d",&s);

	if(cp<100){
		if(num>=1) {
			printf("YES\n%d",num-1);
		}else printf("NO\n");
	}else if(cp>=100&&cp<=600){
		if(num>=5){
			if(hp>100){
				if(s>4||num<8) {printf("NO\n");
				}else printf("YES\n%d",num-8);
			}else printf("YES\n%d",num-5);
		}else printf("NO\n");
	}else{
		if(num>=15&&s<=4){
			if(hp>200){
				printf("YES\n%d",num-25);
			}else printf("YES\n%d",num-15);
		}else printf("NO\n");
	}
}
