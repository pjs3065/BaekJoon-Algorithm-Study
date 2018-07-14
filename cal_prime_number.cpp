#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	vector<int> prime(1000001);

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

	for(int i = m; i <= n; i++)
	{
		if(prime[i] == 0)
		{
			printf("%d\n",i);
		}
	}

	return 0;
}