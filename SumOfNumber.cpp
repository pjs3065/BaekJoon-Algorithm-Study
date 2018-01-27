#include<stdio.h>
int main(void)
{
	int n,c;
	int sum = 0;

	scanf("%d",&c);

	for(int i = 0; i < c; i++)
	{
		scanf("%1d",&n);
		sum = sum + n;
	}

	printf("%d",sum);
	return 0;
}