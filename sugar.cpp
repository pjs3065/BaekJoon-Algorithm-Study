#include<stdio.h>

int main()
{
	int n;
	int ans = 9999;

	scanf("%d", &n);

	for(int x = 0; x <= n/5; x++)
	{
		for(int y = 0; y <= n/3; y++)
		{
			if((5*x) + (3*y) == n)
			{
				if(x + y < ans)
				{
					ans = x + y;
				}
			}

		}
	}

	if(ans == 9999)
	{
		printf("-1\n");
	}
	else
		printf("%d\n", ans);
}