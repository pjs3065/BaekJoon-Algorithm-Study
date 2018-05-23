#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};  //(우, 하, 좌, 상)

int main()
{
	//테스트 케이스 입력
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//맵크기 결정
		int n;
		scanf("%d", &n);

		//맵과 거리, 체크 vector 만들기
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

		//공사 걸리는 시간 입력받기
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}

		//0,0부터 완전탐색 시작
		queue< pair<int, int> > q;
		q.push(make_pair(0,0));

		dis[0][0] = 0;
		check[0][0] = 0;

		//큐에 아무것도 없을 경우 모든 탐색이 종료
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//상하좌우 전부 탐색하기
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