#include<stdio.h>

long long d[101][10];
long long mod = 1000000000;

void cal(int n)
{
	for(int i = 1; i < 10; i++)
	{
		d[1][i] += 1;
	}

	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(j == 0)
			{
				d[i][j] += d[i-1][j+1];
			}

			else if(j == 9)
			{
				d[i][j] += d[i-1][j-1];
			}

			else
			{
				d[i][j] += d[i-1][j-1] + d[i-1][j+1];
			}

			d[i][j] %= mod; 
		}
	}
}


int main()
{
	int n;
	scanf("%d", &n);

	cal(n);

	long long ans = 0;

	for(int i = 0; i <= 9; i++)
	{
		ans += d[n][i];
	}

	printf("%lld\n", ans % mod);
	return 0;
}