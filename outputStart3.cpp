#include<stdio.h>
int main(void)
{

	int n;
	scanf("%d",&n);

	for(int i = 0; i <= n-1; i++)
	{
		for(int j = n; j > i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}