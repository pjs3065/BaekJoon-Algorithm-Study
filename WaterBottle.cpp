#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int cap[3];
bool ans[201] = {false,};
bool check[201][201] = {false,};

const int from[6] = {0,0,1,1,2,2};
const int to[6] = {1,2,0,2,0,1};

int main()
{
	//Input
	for(int i = 0; i < 3; i++)
	{
		cin >> cap[i];
	}

	int sum = cap[2];
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	check[0][0] = true;
	ans[cap[2]] = true;

	while(!q.empty())
	{
		//Current each bottle's water value;
		int cur[3]; //x, y, z
		cur[0] = q.front().first;
		cur[1] = q.front().second;
		cur[2] = sum - cur[0] - cur[1];
		q.pop();

		//move water from -> to (x -> y, x -> z, y -> x, y -> z, z -> x, z -> y)
		for(int i = 0; i < 6; i++)
		{
			int next[3] = { cur[0], cur[1], cur[2] };
			next[to[i]] += next[from[i]];
			next[from[i]] = 0;
			if(next[to[i]] >= cap[to[i]])
			{
				next[from[i]] = next[to[i]] - cap[to[i]];
				next[to[i]] = cap[to[i]];
			}

			if(check[next[0]][next[1]] == false)
			{
				check[next[0]][next[1]] = true;
				q.push(make_pair(next[0],next[1]));
				if(next[0] == 0)
				{
					ans[next[2]] = true;
				}
			}
		}
	}

	for(int i = 1; i <= cap[2]; i++)
	{
		if(ans[i] == true)
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}