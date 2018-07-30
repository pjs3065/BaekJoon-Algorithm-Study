#include<stdio.h>
#include<vector>

using namespace std;

vector<int> graph(1001);
vector<int> check(1001);

int cycle_c = 0;

int dfs(int start, int p)
{
	check[p] = 1;

	int next = graph[p];

	if(check[next] == 0)
	{
		check[p] = dfs(start, next);
		return check[p];
	}

	else
	{
		if(start == next)
		{
			cycle_c = cycle_c + 1;
			return 1;
		}
		return 0;
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

		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&graph[i]);
			check[i] = 0;
		}

		cycle_c = 0;

		for(int i = 1; i <= n; i++)
		{
			if(check[i] == 0)
			{
				check[i] = 1;
				check[i] = dfs(i, graph[i]);
			}
		}

		printf("%d\n",cycle_c);
	}

	return 0;
}