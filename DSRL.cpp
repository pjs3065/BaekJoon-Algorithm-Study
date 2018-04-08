#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
bool check[10000];
char how[10000];
int from[10000];


int main()
{
	//test case
	int t;
	cin >> t;

	//number range

	while(t--)
	{
		int n,m;
		cin >> n;
		cin >> m;

		//initialization
		memset(check,false,sizeof(check));
		memset(how,'\n',sizeof(how));
		memset(from,0,sizeof(from));

		//push first value into q
		queue<int> q;
		q.push(n);

		check[n] = true;
		from[n] = -1;

		//find DSLR
		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			if(now == m)
			{
				break;
			}

			if(check[now * 2 % 10000] == false)
			{
				int next = (now * 2) % 10000;
				check[next] = true;
				how[next] = 'D';
				from[next] = now;
				q.push(next);
			}

			if(check[now == 0 ? 9999 : now - 1] == false)
			{
				int next = now == 0 ? 9999 : now - 1;
				check[next] = true;
				how[next] = 'S';
				from[next] = now;
				q.push(next);
			}

			if(check[(now % 1000) * 10 + (now /1000)] == false)
			{
				int next = (now % 1000) * 10 + (now /1000);
				check[next] = true;
				how[next] = 'L';
				from[next] = now;
				q.push(next);
			}

			if(check[(now /10) + (now % 10) * 1000] == false)
			{
				int next = (now /10) + (now % 10) * 1000;
				check[next] = true;
				how[next] = 'R';
				from[next] = now;
				q.push(next);
			}

		}

		int temp = m;
		string ans = "";
		while(temp != n){
			ans += how[temp];
			temp = from[temp];
		}

		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}