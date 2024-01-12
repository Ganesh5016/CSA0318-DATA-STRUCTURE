#include<stdio.h>
 int insertion_sort(int num[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(num[i]>num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
}
int main()
{
	int i,n,num[100];
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("\nEnter Array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	insertion_sort(num,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++)
		printf("%d  ",num[i]);
	return 0;
}
