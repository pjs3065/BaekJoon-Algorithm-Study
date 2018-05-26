#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	//입력 갯수
	int n; 
	scanf("%d", &n);

	//범위 a, b
	vector<int> a(n);
	vector<int> b(n);

	int max = -1;

	//범위 입력 받기
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);

		if(max < b[i])
		{
			max = b[i];
		}
	}

	vector<int> check_n(max + 2);


	for(int i = 0; i < n; i++)
	{
		for(int j = a[i]; j <= b[i]; j++)
		{
			check_n[j] += 1;
		}
	}

	int find = 0;

	for(int i = 0; i < max + 2; i++)
	{
		//짝수일 경우
		if(i == 0 && check_n[i] % 2 == 0)
		{
			printf("(-, ");
			find = 1;
		}

		else if(find == 1 && check_n[i] % 2 != 0)
		{
			printf(" %d)\n",i);
			find = 0;
		}

		else if(find == 0 && check_n[i] % 2 == 0)
		{
			printf("[%d , ",i);
			find = 2;
		}

		else if(find == 2 && check_n[i] % 2 != 0)
		{
			printf("%d)\n",i-1);
			find = 4;
		}

		else if(find == 3 && check_n[i] % 2 == 0)
		{
			printf("%d)\n", i);
			find = 4;
		}

		else if(find == 4 && check_n[i] % 2 == 0)
		{
			printf("(%d, ",i);
			find = 3;
		}
		else
		{
			printf("+)\n");
		}
	}
	return 0;
}