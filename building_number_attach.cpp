#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

int mx[4] = {-1,1,0,0};
int my[4] = {0,0,-1,1};

using namespace std;

int main()
{
	//지도 크기 입력 (5 ~ 25)
	int n;
	scanf("%d", &n);

	//집 여부 입력
	vector< vector<int> > house;
	vector< vector<int> > check;

	for(int i = 0; i < n; i++)
	{
		vector<int> element(n);
		house.push_back(element);
		check.push_back(element);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d",&house[i][j]);
		}
	}

	//집 단지 몇개로 구성되어 있는지 세기
	queue< pair<int, int> > q;
	vector<int> total;

	int town_count = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int house_count = 0;

			if(check[i][j] < 1 && house[i][j] == 1)
			{
				q.push(make_pair(i,j));
				check[i][j] = ++town_count;
				house_count = 1;
			}

			while(!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for(int k = 0; k < 4; k++)
				{
					int dx = x + mx[k];
					int dy = y + my[k];

					if(dx >= 0 && dx < n && dy >= 0 && dy < n)
					{
						if(house[dx][dy] != 0 && check[dx][dy] < 1)
						{
							house_count += 1;
							check[dx][dy] = town_count;
							q.push(make_pair(dx,dy));
						}
					}
				}
			}

			if(house_count > 0)
			{
				total.push_back(house_count);
			}
		}
	}

	printf("%d\n",town_count);

	sort(total.begin(),total.end());

	for(int i = 0; i < town_count; i++)
	{
		printf("%d\n",total[i]);
	}

	return 0;
}