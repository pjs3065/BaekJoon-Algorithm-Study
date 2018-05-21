#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	//입력
	long long int t;
	scanf("%lld", &t);

	int n;
	scanf("%d", &n);

	vector<int> a(n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int m;
	scanf("%d", &m);

	vector<int> b(m);

	for(int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}

	//계산
	long long int sum;
	int ans = 0;

	vector<long long> a_sum;

	for(int i = 0; i < n; i++)
	{
		sum = 0;

		for(int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum > t)
			{
				break;
			}
			else
			{
				a_sum.push_back(sum);
			}
		}
	}

	vector<long long> b_sum;

	for(int i = 0; i < m; i++)
	{
		sum = 0;

		for(int j = i; j < m; j++)
		{
			sum += b[j];
			if (sum > t)
			{
				break;
			}
			else
			{
				b_sum.push_back(sum);
			}
		}
	}

	sort(a_sum.begin(), a_sum.end());
	sort(b_sum.begin(), b_sum.end());

	int a_length = a_sum.size();
	int b_length = b_sum.size();

	for(int i = 0; i < a_length; i++)
	{
		for(int j = 0; j < b_length; j++)
		{
			if(a_sum[i] + b_sum[j] == t)
			{
				ans += 1;
			}

			else if(a_sum[i] + b_sum[j] > t)
			{
				break;
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}