#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> bottle(201);

int main()
{
	int f, s, t;
	int n = 0;
	cin >> f >> s >> t;

	for(int i = 0; i < 201; i++)
	{
		bottle[i] = 999;
	}

	bottle[0] = t;

	if( f + s < t )
	{
		for(int i = 1; i <= f + s; i++)
		{
			bottle[++n] = t - i;
		}

	}

	else if(f + s >= t)
	{
		if(f > s)
		{
			int temp;
			temp = f;
			f = s;
			s = temp;
		}

		for(int i = f; i <= s; i++)
		{
			if( t - f == s)
			{
				bottle[++n] = f;
			}
			else
			{
				bottle[++n] = i;
				bottle[++n] = t - i;
			}
		}
	}

	sort(bottle.begin(),bottle.end());

	for(int i = 0; i <= n; i++)
	{
		if(i == 0 && bottle[i] != 0)
		{
			cout << bottle[i];
		}

		else if(bottle[i] !=0)
		{
			cout << ' '<< bottle[i];
		}
	}

	cout << '\n';
	return 0;
}