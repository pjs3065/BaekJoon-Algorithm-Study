#include<iostream>
#include<string>
#include<queue>
#include<map>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int main()
{
	int n = 3;
	int start = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			temp = (temp == 0) ? 9 : temp;
			start = start * 10 + temp;
		}
	}

	queue<int> q;
	q.push(start);

	map<int,int> dist;
	dist[start] = 0;

	while(!q.empty())
	{
		int now_number = q.front();
		string now = to_string(now_number);
		q.pop();

		int z = now.find('9');
		int x = z/3;
		int y = z%3;

		for(int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if(nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				string next = now;
				swap(next[3*x + y],next[3*nx + ny]);
				int number = stoi(next);

				if(dist.count(number) == 0)
				{
					dist[number] = dist[now_number] + 1;
					q.push(number);
				}
			}
		}
	}

	if(dist.count(123456789) == 0)
	{
		cout << -1 << '\n';
	}else{
		cout << dist[123456789] << '\n';
	}
	return 0;
}