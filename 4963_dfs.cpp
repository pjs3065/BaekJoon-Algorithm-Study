#include<stdio.h>
using namespace std;

int map[51][51];
int check[51][51];

int my[8] = {-1,-1,-1,0,0,1,1,1};
int mx[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int i, int j, int y, int x)
{
	check[i][j] = 1;

	for(int k = 0; k < 8; k++)
	{
		int dy = i + my[k];
		int dx = j + mx[k];

		if(dy >= 0 && dy < y && dx >= 0 && dx < x)
		{
			if(check[dy][dx] == 0 && map[dy][dx] == 1)
			{
				dfs(dy,dx,y,x);
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
					dfs(i,j,y,x);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}

	return 0;
}