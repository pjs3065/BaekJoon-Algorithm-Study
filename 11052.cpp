#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int d[1001];
int p[1001];

void cal()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], d[i-j] + p[j]);
		}
	}
}


int main()
{
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}

	cal();

	printf("%d\n",d[n]);
	return 0;
}