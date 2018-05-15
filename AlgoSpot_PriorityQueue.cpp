#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

//움직이는 방향 (우, 좌, 하, 상)
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };

int main()
{
	int n, m;

	//입력
	scanf("%d %d",&m, &n);

	//배열선언 (벽 지도와 거리)
	vector< vector<int> > map;
	vector< vector<int> > d;

	for(int i = 0; i < n; i++)
	{
		vector<int> element(m);
		vector<int> element2(m);

		map.push_back(element);
		d.push_back(element2);
	}


	//벽 구성하기 및 거리 초기화
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d",&map[i][j]);
			d[i][j] = -1;
		}
	}

	priority_queue<pair<int,pair<int,int> >> q;

	q.push(make_pair(0,make_pair(0,0)));
	d[0][0] = 0;

	while(!q.empty())
	{
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x + d_x[i];
			int ny = y + d_y[i];

			if(nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if(d[nx][ny] == -1)
				{
					if(map[nx][ny] == 0)
					{
						d[nx][ny] = d[x][y];
					}
					else
					{
						d[nx][ny] = d[x][y] + 1;
					}
					q.push(make_pair(-d[nx][ny],make_pair(nx,ny)));
				}
			}
		}
	}

	int ans = d[n-1][m-1];
	printf("%d\n", ans);
	
	return 0;
}