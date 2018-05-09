#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;

	//입력
	scanf("%d",&n);

	vector<bool> check_prime (n+1);
	vector<int> prime (n+1);

	int count = 0;

	//소수 구하기
	for(int i = 2; i <= n; i++)
	{
		if(check_prime[i] == false) prime[count++] = i;

		for(int j = i * 2; j <= n; j = j + i)
		{
			if(check_prime[j] == true) continue;
			else check_prime[j] = true;
		}
	}

	int l = 0, r = 0;
	int sum = 0;
	int ans = 0;

	sum = prime[0];

	while(r < count)
	{
		if(sum == n)
		{
			ans++;
			r++;
			sum += prime[r];
		}

		else if(sum < n)
		{
			r++;
			sum += prime[r];
		}

		else if(sum > n)
		{
			if(l == r)
			{
				r++;
				sum += prime[r];
			}
			else
			{
				sum -= prime[l];
				l++;
			}
		}
	}

	printf("%d\n", ans);

}