#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int a_n, b_n;
	scanf("%d %d", &a_n, &b_n);

	vector<int> a(a_n);

	for(int i = 0; i < a_n; i++)
	{
		scanf("%d", &a[i]);
	}

	vector<int> b(b_n);

	for(int i = 0; i < b_n; i++)
	{
		scanf("%d", &b[i]);
	}

	//모두 a일경우

	int l = 0;
	int r = 0;

	int sum = a[l];
	int ans = 0;

	while(l < a_n)
	{
		if(sum <= t)
		{
			if(sum == t)
			{
				ans ++;
			}

			r++;
			r = r % a_n;
			sum += a[r];
		}

		else
		{
			if(l == r)
			{
				r++;
				r = r % a_n;
				sum += a[r];
			}

			else
			{
				sum -= a[l];
				l++;
			}
		}
	}


	//모두 b일경우

	l = 0;
	r = 0;

	sum = b[l];

	while(l < b_n)
	{
		if(sum <= t)
		{
			if(sum == t)
			{
				ans ++;
			}

			r++;
			r = r % b_n;
			sum += b[r];
		}

		else
		{
			if(l == r)
			{
				r++;
				r = r % b_n;
				sum += b[r];
			}

			else
			{
				sum -= b[l];
				l++;
			}
		}

	}


	// a 와 b 혼합

	vector<int> a_sum;
	vector<int> b_sum;

	//a가 될 수 있는 전체 수
	for(int i = 0; i < a_n; i++)
	{
		sum = 0;

		for(int j = i; j < a_n + i; j++)
		{
			sum += a[j % a_n];

			if(sum < t)
			{
				a_sum.push_back(sum);
			}

			else
			{
				break;
			}
		}
	}

	//b가 될 수 있는 전체 수
	for(int i = 0; i < b_n; i++)
	{
		sum = 0;

		for(int j = i; j < b_n + i; j++)
		{
			sum += b[j % b_n];

			if(sum < t)
			{
				b_sum.push_back(sum);
			}

			else
			{
				break;
			}
		}
	}

	sort(a_sum.begin(), a_sum.end());
	sort(b_sum.begin(), b_sum.end());

	int a_length = a_sum.size();
	int b_length = b_sum.size();

	l = 0;
	r = 0;

	sum = 0;

	for(int i = 0; i < a_length; i++)
	{
		for(int j = 0; j < b_length; j++)
		{
			if(a_sum[i] + b_sum[j] == t)
			{
				ans+= 1;
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}