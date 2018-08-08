#include<stdio.h>

int n;
int tile[1001];

int tiling(int x)
{
	if(x <= 1) return 1;

	if(tile[x] > 0) return tile[x];
	else
	{
		tile[x] = (tiling(x-1) + tiling(x-2))  % 10007;
		return tile[x];
	}
}

int main()
{
	scanf("%d", &n);
	printf("%d\n",tiling(n));
	return 0;
}
