#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int btn [2];

bool check[1000001];
int ans[1000001];

int main()
{
	int f,s,g,u,d;

	//input
	cin >> f >> s >> g >> u >> d;

	//button
	btn[0] = u;
	btn[1] = -d;

	//initialization
	memset(check,false,sizeof(check));
	memset(ans,-1,sizeof(ans));


	//first floor
	queue<int> q;
	q.push(s);
	check[s] = true;
	ans[s] = 0;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		//arrive in g
		if(now == g) break;
	
		//move
		for(int i = 0; i < 2; i++)
		{
			int next = now + btn[i];
			if(next > 0 && next <= f && check[next] == false)
			{
				check[next] = true;
				ans[next] = ans[now] + 1;
				q.push(next);
			}
		}

	}
	if(ans[g] == -1)
		cout << "use the stairs" << '\n';
	else
		cout << ans[g] << '\n';
	return 0;
}
