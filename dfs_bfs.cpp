#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> graph[1001];
vector<int> check1(1001);
vector<int> check2(1001);
int n, m, v;

void dfs(int p)
{
	if(check1[p] == 0)
	{
		check1[p] = 1;
		printf("%d ", p);
	}

	for(int i = 0; i < graph[p].size(); i++)
	{
		if(check1[graph[p][i]] == 0)
		{
			dfs(graph[p][i]);
		}
	}
}

void bfs()
{
	//큐 선언 
	queue<int> q;
	q.push(v);

	check2[v] = 1;
	printf("%d ",v);

	while(!q.empty())
	{
		int p = q.front();
		q.pop();

		for(int i = 0; i < graph[p].size(); i++)
		{
			int c_v = graph[p][i];

			if(check2[graph[p][i]] == 0)
			{
				q.push(graph[p][i]);
				check2[graph[p][i]] = 1;
				printf("%d ",c_v);
			}
		}
	}
}


int main()
{
	// n: 정점 m: 간선, v: 시작할 정점의 번호
	scanf("%d %d %d", &n, &m, &v);

	//간선들 입력
	int s,e;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &s, &e);
		graph[s].push_back(e); graph[e].push_back(s);
	}

	//작은 값 먼저 나오게 정렬하기
	for(int i = 0; i < n; i++)
	{
		sort(graph[i].begin(),graph[i].end());
	}

	dfs(v);
	printf("\n");
	bfs();
	return 0; 
}