#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int m, n;

	while(true)
	{
		scanf("%d", &n);
		if(n == 0) break;

		m = 2 * n;

		vector<int> prime(300000);

		for(int i = 0; i <= m; i++)
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
				for(int j = i + i; j <= m; j += i)
				{
					prime[j] = 1;
				}
			}
		}

		int count = 0;

		for(int i = n + 1; i <= m; i++)
		{
			if(prime[i] == 0)
			{
				count++;
			}
		}

		printf("%d\n",count);
	}

	return 0;
}