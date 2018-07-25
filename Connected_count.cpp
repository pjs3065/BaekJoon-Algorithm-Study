#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> graph[1001];
vector<bool> check(1001);

int n, m;

int ans = 0;

void dfs(int start)
{
	check[start] = true;

	for(int i = 0; i < graph[start].size(); i++)
	{
		if(check[graph[start][i]] == false)
		{
			dfs(graph[start][i]);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	int u, v;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 0; i < n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	for(int i = 1; i <= n; i++)
	{
		if(check[i] == false)
		{
			dfs(i);
			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}