#include<stdio.h>

int d[100001];
int check[100001];
int s[100001];

int dfs(int p ,int cnt, int step)
{
	if(check[p] != 0)
	{
		if(step != s[p])
		{
			return 0;
		}

		return cnt - check[p];
	}

	check[p] = cnt;
	s[p] = step;

	return dfs(d[p], cnt + 1, step);
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &d[i]);
			check[i] = 0;
			s[i] = 0;
		}

		int ans = 0;

		for(int i = 1; i <= n; i++)
		{
			if(check[i] == 0)
			{
				ans += dfs(i,1,i);
			}
		}

		printf("%d\n", n - ans);
	}
	return 0;
}