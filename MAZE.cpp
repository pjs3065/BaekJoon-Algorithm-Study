#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int mx[4] = {1,-1,0,0};
int my[4] = {0,0,-1,1};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector< vector<int> > maze;
	vector< vector<int> > d;

	for(int i = 0; i < n; i++)
	{
		vector<int> element(m);
		maze.push_back(element);
		d.push_back(element);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	queue < pair<int, int> > q;
	q.push(make_pair(0,0));
	d[0][0] = 1;

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int dx = x + mx[i];
			int dy = y + my[i];

			if(dx >= 0 && dx < n && dy >= 0 && dy < m)
			{
				//경로가 0일 경우 못감
				if(maze[dx][dy] == 0)
				{
					continue;
				}

				//경로가 1일 경우 감
				else if(maze[dx][dy] == 1)
				{
					// 거리가 0인 경우 
					if(d[dx][dy] == 0)
					{
						d[dx][dy] = d[x][y] + 1;
						q.push(make_pair(dx,dy));
					}
					else
					{
						if(d[dx][dy] > d[x][y] + 1)
						{
							d[dx][dy] = d[x][y] + 1;
							q.push(make_pair(dx,dy));
						}
					}
				}
			}
		}
	}

	printf("%d\n",d[n-1][m-1]); 


	return 0;
}