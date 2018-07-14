#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//입력 갯수
	int n;

	//빈도수 배열과 중간값을 위한 배열
	vector<int> f(10000);
	vector<int> m;

	//입력하기
	scanf("%d",&n);

	int integer;

	float sum = 0;

	int max = -100000;
	int min = 100000;
	int f_max = 0;

	int f_min = 100000;
	int s_min = 100000;

	for(int i = 0; i < n; i++)
	{
		//integer 입력하기
		scanf("%d", &integer);

		//합계 구하기
		sum += integer;

		// 빈도수 구하기 (음수일 경우)
		if(integer < 0)
		{
			int c_integer = 4000 - integer; // 4000 -(-1) = 4001
			f[c_integer]++;  

			if(f_max < f[c_integer])
			{
				f_max = f[c_integer];
				f_min = integer; // 최빈중 첫번째값이 -1
				s_min = 100000;
			} // 만약에 최빈이 같은 수가 등장 했다면?
			else if (f_max == f[c_integer]) 
			{
				//가장 작은 수가 현재 값이 되고 가장 작은 수였던 것이 두번째 작은 수가 된다.
				if(f_min > integer)
				{
					int temp = f_min;
					f_min = integer;
					s_min = temp;
				}
				//값이 가장 작은 수보다 크고 두번째 작은 수보다 작다면 두번째 작은 수로 넣어준다.
				else if(s_min > integer)
				{
					s_min = integer;
				}
			}
		}
		else
		{
			f[integer]++;

			if(f_max < f[integer])
			{
				f_max = f[integer];
				f_min = integer;
				s_min = 100000;
			}
			else if (f_max == f[integer])
			{
				if(f_min > integer)
				{
					int temp = f_min;
					f_min = integer;
					s_min = temp;
				}
				else if(s_min > integer)
				{
					s_min = integer;
				}
			}
		}

		//printf("(%d %d)\n",f_min,s_min);

		//middle
		m.push_back(integer);

		// min, max
		if(max < integer)
		{
			max = integer;
		}

		if(min > integer)
		{
			min = integer;
		}
	}

	//average
	float avg = sum/n;

	//middle
	sort(m.begin(),m.end());
	int mid = m[n/2];

	//frequency
	int max_f;

	if(s_min != 100000)
	{
		if(f_min < 0)
		{
			f_min = 4000 - f_min;
		}

		if(s_min < 0)
		{
			s_min = 4000 - s_min;
		}

		if(f[f_min] == f[s_min])
		{ 
			max_f = s_min > 4000 ? -(s_min - 4000) : s_min;
		}
		else
		{
			max_f = f_min > 4000 ? -(f_min - 4000) : f_min;
		}
	}
	else
	{
		max_f = f_min;
	}

	//range
	int range = max - min;
	printf("%.0f\n%d\n%d\n%d\n",avg, mid, max_f, range);
	return 0;
}