#include<iostream>
#include<vector>

using namespace std;

int subset[20];
int n, s;
int ans = 0;

void check(int i, int sum)
{
	//모두 돌았나 체크
	if(i == n)
	{
		if(sum == s)
		{
			ans += 1;
		}
		return;
	}

	//현재 값을 더할것인가?
	check(i+1, sum + subset[i]);

	//현재 값을 더하지 않을 것인가?
	check(i+1, sum);
}


int main()
{
	cin >> n >> s;
	

	for(int i = 0; i < n ; i++)
	{
		cin >> subset[i];
	}

	check(0,0);
	if(s == 0) ans -=1;
	cout << ans << '\n';
	return 0;
}