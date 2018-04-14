#include<iostream>

using namespace std;

int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};

int map[500][500];

int n, m;
int ans = 0;

void go(int x, int y)
{
	if(x == n-1 && y == m-1)
	{
		ans += 1;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		int px = x + mx[i];
		int py = y + my[i];

		if(px >= 0 && px < n && py >= 0 && py < m)
		{
			if(map[px][py] < map[x][y])
			{
				go(px,py);
			}
		}
	}
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

	go(0,0);

	cout << ans << '\n';
	return 0;
}