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

	//���� �丶���� ��ġ ��ǥ
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

	//���� �丶�� ���ÿ� ����
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
						//������ �丶��� �Ϸ����� �� �ɸ���.
						check[dx][dy] = check[x][y] + 1;
						q.push(make_pair(dx,dy));
					}
				}
			}
		}
	}

	//�� �ʹµ� �ɸ� �ð� ���ϱ�
	int max = -1;

	//��� �� �;����� üũ
	bool all = true;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//�ڽ��� �ִ� �丶�䰡 ��� ���� ���� ���
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

	//�� ���� ���� ��� -1�� ���
	if(all == false) printf("-1\n");
	
	//��� �;��� ��� �ּҷ� �ɸ� �ð� ���(���⼭ -1���ִ� ������ ������ 1���̾����ϱ�)
	else printf("%d\n",max - 1);
	
	return 0;
}