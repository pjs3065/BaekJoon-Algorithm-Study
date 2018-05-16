#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);

	vector<long long> a(n), b(n), c(n), d(n);

	for(int i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
	}

	// a + b + c + d = 0 -> a + b = -(c+b)

	vector<long long> first (n*n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			first[i*n + j] = a[i] + b[j]; 
		}
	}
	vector<long long> second (n*n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			second[i*n + j] = c[i] + d[j]; 
		}
	}

	sort(second.begin(), second.end());

	long long ans = 0;

	for(long long num : first)
	{
		auto range = equal_range(second.begin(), second.end(),-num);
		ans += range.second - range.first;
	}

	printf("%lld\n", ans);

	return 0;
}