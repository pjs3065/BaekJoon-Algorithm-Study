#include<stdio.h>

using namespace std;

long long d[1001][10];
long long mod = 10007;

void cal(int n)
{
	for(int i = 0; i <= 9; i++)
	{
		d[1][i] += 1;
	}

	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				d[i][j] += d[i-1][k];
			}
			d[i][j] = d[i][j] % mod;
		}
	}

}


int main()
{
	int n;
	scanf("%d",&n);

	cal(n);

	long long ans = 0;

	for(int i = 0; i<= 9; i++)
	{
		ans += d[n][i];
	}

	printf("%d\n",ans % mod);
	
	return 0;
}