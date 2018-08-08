#include<stdio.h>

int d[10];

int cal(int x)
{
	if(x == 0) return 1;
	if(x == 1) return 1;
	if(x == 2) return 2;

	if(d[x] > 0) return d[x];

	else 
	{
		d[x] = cal(x-1) + cal(x-2) + cal(x-3);
		return d[x];
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", cal(n));
	}
	return 0;
}