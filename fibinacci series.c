#include<stdio.h>
main()
{
	int n,f1=0,f2=1,nt,i;
	scanf("%d",&n);
	printf("%d %d ",f1,f2);
	nt=f1+f2;
	for(i=3;i<=n;i++)
	{
		printf("%d ",nt);
		f1=f2;
		f2=nt;
		nt=f1+f2;
	}
}

