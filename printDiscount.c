#include<stdio.h>
int a,b;
int main(void){
	scanf("%d %d",&a,&b);
	printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
	printf("\\%7d%%off!    \\\n",a);
	printf("\\ Before  $%5d \\\n",b);
	printf("\\ After   $%5.2f \\\n",b*((100-a)/100.0));
	printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
}
