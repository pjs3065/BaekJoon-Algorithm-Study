#include<stdio.h>
#include<vector>

using namespace std;

vector<int> team_check(100001);
vector<int> visit_check(100001);
vector<int> graph[100001];

int dfs(int start, int p)
{
	if(start == p)
	{
		team_check[start] = 2;
		return 2;
	}

	if(visit_check[p] == 0 && team_check[p] == 0)
	{
		visit_check[p] = 1;

		team_check[p] = dfs(start, graph[p][0]);

		visit_check[p] = 0;

		return team_check[p];
	}

	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);

	int n; // 총 학생 수

	while(t--)
	{
		scanf("%d",&n);

		for(int i = 1; i <= n; i++)
		{
			int st_n; // 학생 번호
			scanf("%d",&st_n);

			graph[i].push_back(st_n);
		}

		int ans = 0;

		for(int i = 1; i <= n; i++)
		{
			if(team_check[i] == 0)
			{                                    
				visit_check[i] = 1;

				if(!dfs(i, graph[i][0]))
				{
					team_check[i] = 1;
					ans++;
				}

				visit_check[i] = 0;
			}
		}

		fill(team_check.begin(),team_check.end(),0);

		for(int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

		printf("%d\n",ans);
	}
	return 0;
}