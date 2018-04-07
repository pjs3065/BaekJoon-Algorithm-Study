#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	int w[20][20] = {0,};

	//입력
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> w[i][j]; 
		}
	}

	//경로
	vector<int> d(n);
	for(int i = 0; i < n; i++)
	{
		d[i] = i;
	}

	int ans = 9999999;

	//모든 경로 탐색
	do{
		bool ok = true;
		int sum = 0;

		for(int i = 0; i < n - 1; i++)
		{
			if(w[d[i]][d[i+1]] == 0) ok = false;
			sum = sum + w[d[i]][d[i+1]];
		}

		if(ok == true && w[d[n-1]][d[0]] != 0)
		{
			sum = sum + w[d[n-1]][d[0]];
			if(ans > sum)
			{
				ans = sum;
			}
		}
	}while(next_permutation(d.begin(), d.end()));

	cout << ans << '\n';
	return 0;
}