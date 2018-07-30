#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int v, e;

	while(t--)
	{
		scanf("%d %d", &v, &e);

		vector<int> graph[20001];
		vector<int> check(20001);

		for(int i = 0; i < e; i++)
		{
			int start, end;
			scanf("%d %d",&start, &end);

			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		queue<int> q;

		int sw = 1;
		int stop = 0;

		for(int i = 1; i <= v; i++)
		{
			if(stop == 1) break;

			q.push(i);
			if(check[i] == 0) check[i] = sw;

			while(!q.empty())
			{
				int n = q.front();
				q.pop();

				for(int i = 0; i < graph[n].size(); i++)
				{
					if(check[graph[n][i]] == 0)
					{
						check[graph[n][i]] = 3-check[n];
						q.push(graph[n][i]);
					}
					else
					{
						if(check[graph[n][i]] == check[n])
						{
							stop = 1;
							break;
						}
					}
				}

				if(stop == 1)
				{
					printf("NO\n");
					break;
				}
			}
		}

		if(stop == 0)
		{
			printf("YES\n");
		}
	}

	return 0;
}