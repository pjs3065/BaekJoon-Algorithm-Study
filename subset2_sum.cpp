#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;

	//���̽� �Է�
	scanf("%d %d",&n, &m);  // 5 0

	vector<int> a(n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}

	//f ������ s ����
	int s = n/2;   //2
	n = n - s;

	//�κ� ������ ����
	vector<int> first_sum(1<<n);

	for(int i = 0; i < (1<<n); i++)
	{	
		for(int k = 0; k < n; k++)
		{
			if(i&(1<<k))
			{
				first_sum[i] += a[k];
			}
		}
	}

	vector<int> second_sum(1<<s);

	for(int i = 0; i < (1<<s); i++)
	{
		for(int k = 0; k < s; k++)
		{
			if(i&(1<<k))
			{
				second_sum[i] += a[k + n];
			}
		}
	}

	//���� (��������)
	sort(first_sum.begin(), first_sum.end());
	sort(second_sum.begin(), second_sum.end());

	reverse(second_sum.begin(), second_sum.end());

	n = (1 << n);
	s = (1 << s);

	int p1 = 0;
	int p2 = 0;

	long long ans = 0;

	//�� ���ϱ�

	while(p1 < n && p2 < s)
	{


		if(first_sum[p1] + second_sum[p2] == m)
		{
			long long f_n = 1;
			long long s_n = 1;

			p1++;
			p2++;

			while(p1 < n && first_sum[p1] == first_sum[p1-1])
			{
				f_n++;
				p1++;
			}

			while(p2 < s && second_sum[p2] == second_sum[p2-1])
			{
				s_n++;
				p2++;
			}

			ans += f_n * s_n;
		}

		else if(first_sum[p1] + second_sum[p2] > m)
		{
			p2++;
		}

		else
		{
			p1++;
		}
	}

	//�� ���

	if(m == 0)
	{
		ans -= 1;
	}

	printf("%ld\n",ans);

	return 0;
}