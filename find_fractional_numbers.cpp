#include<stdio.h>

int main()
{
	int x;
	scanf("%d",&x);

	int i = 1, j = 1;
	int s = 0, count = 1, limit = 0;

	while(count < x)
	{
		if(limit == 0)
		{
			if(s == 0)
			{
				j = j + 1;
				limit = j - 1;
				s = 1;
			}

			else
			{
				i =  i + 1;
				limit = i - 1; 
				s  = 0;
			}
		}

		else
		{
			if(s == 0)
			{
				i = i - 1;
				j = j + 1;
			}

			else
			{
				i = i + 1;
				j = j - 1;
			}

			limit--;
		}

		count++;
	}

	printf("%d/%d\n",i,j);

	return 0;
}