#include<stdio.h>

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	long long n;

	while(count <= t)
	{
		scanf("%lld", &n); //588432

		int m;
		int sum;

		do
		{
			if(n < 10)
			{
				sum = n;
				break;
			}

			else sum = 0;

			while(n > 0)
			{
				m = n % 10;
				n = n / 10;
				sum = sum + m;
			}

			n = sum;
		}while(sum >= 10);

		printf("#%d %d\n",count++, sum);
	}
	return 0;
}