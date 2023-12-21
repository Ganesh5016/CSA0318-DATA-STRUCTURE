#include<stdio.h>
int main()
{
	int i,n1,n2,j;
	scanf("%d%d",&n1,&n2);
	printf("Even numbers:");
	for(i=n1;i<=n2;i++)
	{
		if(i%2==0)
		printf("%d ",i);
	}
	printf("\nodd numbers:");
	for(i=n1;i<=n2;i++)
	{
		if(i%2!=0)
		printf("%d ",i);
	}
}
