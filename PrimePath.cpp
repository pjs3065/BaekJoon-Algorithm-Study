#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

bool prime[10001];
bool c[10001];
int d[10001];

int change(int now, int index, int number)
{
	if(index == 0 && number == 0)
	{
		return -1;
	}

	string s = to_string(now);
	s[index] = number + '0';

	return stoi(s);
}

int main()
{
	int t;
	cin >> t;

	//make set about prime number
	for(int i = 2; i <= 10000; i++)
	{
		if(prime[i] == false)
		{
			for(int j = i * i; j <= 10000; j += i)
			{
				prime[j] = true;
			}
		}
	}

	//convert true -> false 
	for(int i = 0; i<= 10000; i++)
	{
		prime[i] = !prime[i];
	}


	while(t--)
	{
		//input first, end number
		int n, m;
		cin >> n >> m;

		//initialization
		memset(c,false,sizeof(c));
		memset(d,0,sizeof(d));

		//push first value
		queue<int> q;
		q.push(n);

		c[n] = true;

		//check and change and distance
		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j <= 9; j++)
				{
					int next = change(now,i,j);
					if( next != -1)
					{
						if(prime[next] == true && c[next] == false)
						{
							c[next] = true;
							d[next] = d[now] + 1;
							q.push(next);
						}
					}
				}
			}
		}
		cout << d[m] << '\n';
	}
	return 0;
}
