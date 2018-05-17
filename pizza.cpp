#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long t;
	scanf("%lld", &t);

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

	vector<long long> a_sum;
	vector<long long> b_sum;

	long long sum;
	long long ans = 0;

	//a�� �� �� �ִ� ��ü ��
	for(int i = 0; i < a_n; i++)
	{
		sum = 0;

		for(int j = i; j < a_n + i; j++)
		{
			sum += a[j % a_n];

			if(sum > t) break;

			else if(sum == t && j % a_n != i - 1)
			{
				ans += 1;
			}

			else if(sum < t )
			{
				a_sum.push_back(sum);
			}
		}
	}

	//b�� �� �� �ִ� ��ü ��
	for(int i = 0; i < b_n; i++)
	{
		sum = 0;

		for(int j = i; j < b_n + i; j++)
		{
			sum += b[j % b_n];

			if(sum > t) break;

			else if(sum == t && j % a_n != i - 1)
			{
				ans += 1;
			}

			else if(sum < t && j % a_n != i - 1)
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

	sum = 0;

	//a�� b ȥ��
	for(int i = 0; i < a_length; i++)
	{
		for(int j = 0; j < b_length; j++)
		{
			if(a_sum[i] + b_sum[j] > t)
			{
				break;
			}

			else if(a_sum[i] + b_sum[j] == t)
			{
				ans+= 1;
			}
		}
	}

	printf("%lld\n",ans);
	return 0;
}