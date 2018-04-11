#include<iostream>

using namespace std;

int main()
{
	int n, s;
	int ans = 0;
	int subset[20];

	cin >> n >> s;
	
	for(int i = 0; i < n; i++)
	{
		cin >> subset[i];
	}

	for(int i = 1; i <(1<<n); i++)
	{
		int sum = 0;
		
		for(int j = 0; j < n; j++)
		{
			if(i&(1<<j))
			{
				sum += subset[j];
			}
		}

		if(sum == s)
		{
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;

}