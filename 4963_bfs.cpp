#include<stdio.h>
#include<queue>

using namespace std;

int map[51][51];
int check[51][51];

int my[8] = {-1,-1,-1,0,0,1,1,1};
int mx[8] = {-1,0,1,-1,1,-1,0,1};

void bfs(int start_y, int start_x, int limit_y, int limit_x)
{
	queue< pair<int, int> > q;
	q.push(make_pair(start_y,start_x));
	check[start_y][start_x] = 1;

	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for(int k = 0; k < 8; k++)
		{
			int dy = y + my[k];
			int dx = x + mx[k];

			if(dy >= 0 && dy < limit_y && dx >= 0 && dx < limit_x)
			{
				if(check[dy][dx] == 0 && map[dy][dx] == 1)
				{
					check[dy][dx] = 1;
					q.push(make_pair(dy,dx));
				}
			}
		}
	}
}

int main()
{
	int x, y;

	while(scanf("%d %d",&x, &y))
	{
		if(x == 0 && y == 0) break;

		for(int i = 0; i < y; i++)
		{
			for(int j = 0; j < x; j++)
			{
				scanf("%d", &map[i][j]);
				check[i][j] = 0;
			}
		}

		int cnt = 0;

		for(int i = 0; i < y; i++)
		{
			for(int j = 0; j < x; j++)
			{
				if(check[i][j] == 0 && map[i][j] == 1)
				{
					bfs(i,j,y,x);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}

	return 0;
}