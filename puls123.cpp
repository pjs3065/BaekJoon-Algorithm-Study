#include<iostream>
using namespace std;

int ans = 0;
void cal(int t, int n, int sum);

int main()
{
	int t;
	int n;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		ans = 0;
		cin >> n;
		cal(1,n,0);
		cout << ans << '\n';
	}

	return 0;
}

void cal(int t, int n, int sum)
{
	for(int c = 1; c <= 3; c++)
	{
		int temp = sum;
		temp = temp + c;

		if(temp == n) ans++;
		if(temp < n) cal(t + 1, n, temp);
	}
}