#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	vector<int> prime(10000);

	for(int i = 0; i <= n; i++)
	{
		if(i < 2)
		{
			prime[i] = 1;
			continue;
		}

		if(prime[i] == 1)
		{
			continue;
		}

		else
		{
			for(int j = i + i; j <= n; j += i)
			{
				prime[j] = 1;
			}
		}
	}

	int sum = 0;
	int count = 0;

	for(int i = m; i <= n; i++)
	{
		if(prime[i] == 0)
		{
			sum += i;

			if(count == 0)
			{
				count = i;
			}
		}
	}

	if(sum == 0 && count == 0)
	{
		printf("-1\n");
	}
	else 
	{
		printf("%d\n%d\n",sum,count);
	}

	return 0;
}