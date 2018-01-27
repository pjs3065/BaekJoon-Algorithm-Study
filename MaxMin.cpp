#include<stdio.h>
int main(void)
{
	int c,n;
	int max = -1000000;
	int min =  1000000;

	scanf("%d",&c);
	for(int i = 0; i < c; i++)
	{
		scanf("%d",&n);
		if(n > max)
		{
			max = n;
		}
		
		if(n < min)
		{
			min = n;
		}
	}

	printf("%d %d",min, max);
	return 0;
}