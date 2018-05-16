#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;

	//케이스 입력
	scanf("%d %d",&n, &m);  // 5 0

	vector<int> a(n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}

	//f 범위와 s 범위
	int s = n/2;   //2
	n = n - s;

	//부분 집합을 생성
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

	//정렬 (오름차순)
	sort(first_sum.begin(), first_sum.end());
	sort(second_sum.begin(), second_sum.end());

	reverse(second_sum.begin(), second_sum.end());

	n = (1 << n);
	s = (1 << s);

	int p1 = 0;
	int p2 = 0;

	long long ans = 0;

	//값 구하기

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

	//답 출력

	if(m == 0)
	{
		ans -= 1;
	}

	printf("%ld\n",ans);

	return 0;
}