#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

//�����̴� ���� (��, ��, ��, ��)
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };

int main()
{
	int n, m;

	//�Է�
	scanf("%d %d",&m, &n);

	//�迭���� (�� ������ �Ÿ�)
	vector< vector<int> > map;
	vector< vector<int> > d;

	for(int i = 0; i < n; i++)
	{
		vector<int> element(m);
		vector<int> element2(m);

		map.push_back(element);
		d.push_back(element2);
	}


	//�� �����ϱ� �� �Ÿ� �ʱ�ȭ
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d",&map[i][j]);
			d[i][j] = -1;
		}
	}

	queue< pair<int,int> > q;
	queue< pair<int,int> > next_q;

	q.push(make_pair(0,0));
	d[0][0] = 0;

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
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
						q.push(make_pair(nx,ny));
					}
					else
					{
						d[nx][ny] = d[x][y] + 1;
						next_q.push(make_pair(nx,ny));
					}
				}
			}
		}

		if(q.empty())
		{
			q = next_q;
			next_q = queue< pair<int,int> >();
		}
	}

	int ans = d[n-1][m-1];
	printf("%d\n", ans);
	
	return 0;
}