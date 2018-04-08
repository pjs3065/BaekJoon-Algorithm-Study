#include<iostream>
#include<vector>
#include<queue>
#define MAX 200000

using namespace std;

int main()
{
	int n, k, count = 0;
	vector<int> dist(MAX + 1);
	vector<bool> check(MAX + 1);
	queue<int> q;

	//input
	cin >> n >> k;

	//n push into queue
	q.push(n);
	dist[n] = 0;
	check[n] = true;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		if(now == k)
		{
			cout << dist[k] << '\n';
			break;
		}

		if(now - 1 >= 0)
		{
			if(check[now - 1] == false)
			{
				dist[now - 1] = dist[now] + 1;
				check[now - 1] = true;
				q.push(now - 1);
			}
		}

		if(now + 1 < MAX)
		{
			if(check[now + 1] == false)
			{
				dist[now + 1] = dist[now] + 1;
				check[now + 1] = true;
				q.push(now + 1);
			}
		}

		if(now * 2 < MAX)
		{
			if(check[now * 2] == false)
			{
				dist[now * 2] = dist[now] + 1;
				check[now * 2] = true;
				q.push(now * 2);
			}
		}
	}
	return 0;
}