#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int box[1001][1001];
int check[1001][1001];

int mx[4] = {-1,0,0,1};
int my[4] = {0,-1,1,0};

int main()
{
	//n x m
	int n, m;
	scanf("%d %d", &n, &m);

	//익은 토마토의 위치 좌표
	vector<int> t_x;
	vector<int> t_y;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			scanf("%d",&box[i][j]);
			check[i][j] = 0;

			if(box[i][j] == 1)
			{
				t_x.push_back(i);
				t_y.push_back(j);
			}
		}
	}

	queue< pair<int, int> > q;

	//익은 토마토 동시에 시작
	for(int i = 0; i< t_x.size(); i++)
	{
		q.push(make_pair(t_x[i],t_y[i]));
		check[t_x[i]][t_y[i]] = 1;
	}

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int dx = x + mx[i];
			int dy = y + my[i];

			if(dx >= 0 && dx < m && dy >= 0 && dy < n)
			{
				if(box[dx][dy] != -1)
				{
					if(check[dx][dy] == 0)
					{
						//인접한 토마토는 하루정도 더 걸린다.
						check[dx][dy] = check[x][y] + 1;
						q.push(make_pair(dx,dy));
					}
				}
			}
		}
	}

	//다 익는데 걸린 시간 구하기
	int max = -1;

	//모두 다 익었는지 체크
	bool all = true;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//박스에 있는 토마토가 모두 익지 않은 경우
			if(box[i][j] != -1 && check[i][j] == 0)
			{
				all = false;
				break;
			}
			
			else if(check[i][j] > max)
			{
				max = check[i][j];
			}
		}

		if(all == false)
		{
			break;
		}
	}

	//다 익지 않을 경우 -1을 출력
	if(all == false) printf("-1\n");
	
	//모두 익었을 경우 최소로 걸린 시간 출력(여기서 -1해주는 이유는 시작이 1일이었으니깐)
	else printf("%d\n",max - 1);
	
	return 0;
}