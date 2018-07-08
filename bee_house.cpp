#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int limit = 1, k = 0;

	while(1)
	{
		limit = limit + (6 * k);
	
		if(n <= limit)
		{
			break;
		}

		k++;
	}

	printf("%d\n",k);
	return 0;
}