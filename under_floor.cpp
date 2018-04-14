#include<iostream>

using namespace std;

int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};

int d[500][500];
int map[500][500];

int n, m;
int ans = 0;

int go(int x, int y)
{
	if(x == n-1 && y == m-1)
	{
		return 1;
	}

	if(d[x][y] != -1)
	{
		return d[x][y];
	}

	int &ans = d[x][y];
	ans = 0;

	for(int i = 0; i < 4; i++)
	{
		int px = x + mx[i];
		int py = y + my[i];

		if(px >= 0 && px < n && py >= 0 && py < m)
		{
			if(map[px][py] < map[x][y])
			{
				ans += go(px,py);
			}
		}
	}

	return ans;
}

int main()
{
	
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}

	for(int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 500; j++)
		{
			d[i][j] = -1;
		}
	}

	cout << go(0,0) << '\n';
	return 0;
}