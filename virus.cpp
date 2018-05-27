#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int c;
	scanf("%d", &c);

	int n; 
	scanf("%d", &n);

	vector< vector<int> > network;

	for(int i = 0; i < c + 1; i++)
	{
		vector<int> element(c + 1);
		network.push_back(element);
	}
	
	int cx, cy;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &cx, &cy);
		network[cx][cy] = 1;
		network[cy][cx] = 1;
	}

	queue <int> q;
	q.push(1);
	
	vector<int> check(c+1);
	check[1] = 1;


	while(!q.empty())
	{
		int x = q.front();
		q.pop();

		for(int y = 2; y <= c; y++)
		{
			if(network[x][y] == 1 && check[y] != 1)
			{
				check[y] = 1;
				q.push(y);
			}
		}
	}

	int ans = 0;

	for(int i = 2; i <= c; i++)
	{
		if(check[i] == 1)
		{
			ans += 1;
		}
	}

	printf("%d\n",ans);

	return 0;
}