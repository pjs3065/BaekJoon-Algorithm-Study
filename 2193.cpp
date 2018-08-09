#include<stdio.h>

long long d[91][2];

void cal(int n)
{
	d[1][1] = 1;

	for(int i = 2; i <= n; i++)
	{
			d[i][0] += d[i-1][1] + d[i-1][0];
			d[i][1] += d[i-1][0];
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	cal(n);

	printf("%lld\n",d[n][0] + d[n][1]);

}