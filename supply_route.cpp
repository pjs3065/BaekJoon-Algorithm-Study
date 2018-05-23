#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};  //(��, ��, ��, ��)

int main()
{
	//�׽�Ʈ ���̽� �Է�
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//��ũ�� ����
		int n;
		scanf("%d", &n);

		//�ʰ� �Ÿ�, üũ vector �����
		vector< vector<int> > map;
		vector< vector<int> > dis;
		vector< vector<int> > check;

		for(int i = 0; i < n; i++)
		{
			vector<int> element1(n);

			map.push_back(element1);
			dis.push_back(element1);
			check.push_back(element1);
		}

		//���� �ɸ��� �ð� �Է¹ޱ�
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		//0,0���� ����Ž�� ����
		queue< pair<int, int> > q;
		q.push(make_pair(0,0));

		dis[0][0] = 0;
		check[0][0] = 0;

		//ť�� �ƹ��͵� ���� ��� ��� Ž���� ����
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//�����¿� ���� Ž���ϱ�
			for(int i = 0; i < 4; i++)
			{
				int dx = x + mx[i];
				int dy = y + my[i];

				if(dx >= 0 && dx < n && dy >=0 && dy < n)
				{
					if(check[dx][dy] == 1)
					{
						if(dis[dx][dy] > dis[x][y] + map[dx][dy])
						{
							dis[dx][dy] = dis[x][y] + map[dx][dy];
							q.push(make_pair(dx,dy));
						}
					}
					
				else
					{
						dis[dx][dy] = dis[x][y] + map[dx][dy];
						q.push(make_pair(dx,dy));
						check[dx][dy] = 1;
					}
				}
			}
		}

		printf("#%d %d\n",count, dis[n-1][n-1]);
		count++;
	}
}