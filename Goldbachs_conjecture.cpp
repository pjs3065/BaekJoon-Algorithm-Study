#include<stdio.h>
#include<vector>

using namespace std;
vector<int> prime(10001);

int main()
{
	int t;
	scanf("%d",&t);

	//소수 먼저 구하기
	for(int i = 0; i <= 10000; i++)
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
			for(int j = i + i; j <= 10000; j += i)
			{
				if(prime[j] == 1) continue;
				prime[j] = 1;
			}
		}
	}

	int n;

	while(t--)
	{
		scanf("%d", &n);

		int min = 10000;

		int a = 0;
		int b = 0;

		for(int i = 2; i <= n; i++)
		{
			if(prime[i] == 1) continue;

			for(int j = i; j <= n; j++)
			{
				if(prime[j] == 1) continue;

				int total = i + j;

				if(total == n)
				{
					a = i;
					b = j;

					if(min > j - i)
					{
						min = j - i;
						a = i;
						b = j;
						break;
					}
				}
			}
		}

		printf("%d %d\n",a,b);
	}

	return 0;
}