#include<stdio.h>

int main()
{
	int n, kim_n, yim_n;
	scanf("%d %d %d", &n, &kim_n, &yim_n);

	if(n == 1)
	{
		printf("-1\n");
	}

	int round = 1;

	while((kim_n % 2) + (kim_n /2) != (yim_n % 2) + (yim_n /2))
	{
		kim_n = (kim_n % 2) + (kim_n /2);
		yim_n = (yim_n %2) + (yim_n / 2);
		round++;
	}

	printf("%d\n",round);
	return 0;
}