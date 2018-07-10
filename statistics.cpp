#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//�Է� ����
	int n;

	//�󵵼� �迭�� �߰����� ���� �迭
	vector<int> f(10000);
	vector<int> m;

	//�Է��ϱ�
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
		//integer �Է��ϱ�
		scanf("%d", &integer);

		//�հ� ���ϱ�
		sum += integer;

		// �󵵼� ���ϱ� (������ ���)
		if(integer < 0)
		{
			int c_integer = 4000 - integer; // 4000 -(-1) = 4001
			f[c_integer]++;  

			if(f_max < f[c_integer])
			{
				f_max = f[c_integer];
				f_min = integer; // �ֺ��� ù��°���� -1
				s_min = 100000;
			} // ���࿡ �ֺ��� ���� ���� ���� �ߴٸ�?
			else if (f_max == f[c_integer]) 
			{
				//���� ���� ���� ���� ���� �ǰ� ���� ���� ������ ���� �ι�° ���� ���� �ȴ�.
				if(f_min > integer)
				{
					int temp = f_min;
					f_min = integer;
					s_min = temp;
				}
				//���� ���� ���� ������ ũ�� �ι�° ���� ������ �۴ٸ� �ι�° ���� ���� �־��ش�.
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