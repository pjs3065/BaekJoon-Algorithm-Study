#include<cstdio>

int t, m, n, x, y, k;

int main()
{
	scanf("%d",&t);
	
	while(t--)
	{
		int x_p = 0, y_p = 0, k = 0, ischeck = 0;
		scanf("%d %d %d %d", &m, &n, &x, &y);

		while(!(x_p == m && y_p == n))
		{
			x_p++;
			y_p++;
			k++;

			x_p = x_p % (m + 1) == 0 ? 1 : x_p;
			y_p = y_p % (n + 1) == 0 ? 1 : y_p;

			if(x_p == x && y_p == y)
			{
				ischeck = 1;
				break;
			}
		}

		if(ischeck == 1)
		{
			printf("%d\n",k);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}