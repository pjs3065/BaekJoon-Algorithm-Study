#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	//입력
	int x[6];
	int y[6];

	//x축 y축 입력
	for(int i = 0; i < 6; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	/*
	for(int i = 0; i < 6; i++)
	{
	printf("%d ", x[i]);
	printf("%d\n", y[i]);
	}
	*/

	//x와 y가 가질 수 있는 수
	vector<int> x_check (10001);
	vector<int> y_check (10001);

	//1번 사각형의 면적
	int rect1_w = x[1] - x[0];
	int rect1_h = y[1] - y[0];

	int rect1 = rect1_w * rect1_h;

	//1번 사각형 x범위 check 하기

	for(int i = 0; i < 6; i = i + 2)
	{
		for(int j = x[i]; j <= x[i+1]; j++)
		{
			x_check[j] += 1;
		}

		for(int j = y[i]; j <= y[i+1]; j++)
		{
			y_check[j] += 1;
		}
	}

	//사각형2 x의 시작과 x의 끝구하기
	int find_x = -1;

	int rec2_start_x = 0;
	int rec2_end_x = 0;

	for(int i = 0; i < 10001; i++)
	{
		if(find_x == -1 && x_check[i] > 1)
		{
			find_x = 1;
			rec2_start_x = i;
		}

		else if(find_x == 1)
		{
			if(i == x[3] || x_check[i] < 2)
			{
				rec2_end_x = i;
				break;
			}
		}
	}

	//사각형2 y의 시작과 y의 끝구하기
	int find_y = -1;

	int rec2_start_y = 0;
	int rec2_end_y = 0;

	for(int i = 0; i < 10001; i++)
	{
		if(find_y == -1 && y_check[i] > 1)
		{
			find_y = 1;
			rec2_start_y = i;
		}

		else if(find_y == 1)
		{
			if(i == y[3] || y_check[i] < 2)
			{
				rec2_end_y = i;
				break;
			}
		}
	}

	int rect2_w = rec2_end_x - rec2_start_x;
	int rect2_h = rec2_end_y - rec2_start_y;
	int rect2 = rect2_w * rect2_h;

	//사각형 3 x시작점 구하기

	find_x = -1;
	int rec3_start_x = 0;
	int rec3_end_x = 0;

	for(int i = 10000; i >= 0; i--)
	{
		if(find_x == -1 && x_check[i] == 2)
		{
			find_x = 1;
			rec3_end_x = i;
		}

		else if(find_x == 1)
		{
			if(i == x[4] || x_check[i] != 2)
			{
				rec3_start_x = i;
				break;
			}
		}
	}

	//사각형 3 y시작점 구하기

	find_y = -1;

	int rec3_start_y = 0;
	int rec3_end_y = 0;

	for(int i = 0; i < 10001; i++)
	{
		if(find_y == -1 && y_check[i] == 3)
		{
			find_y = 1;
			rec3_start_y = i;
		}

		else if(i == y[5] || find_y == 1)
		{
			if(y_check[i] != 3)
			{
				rec3_end_y = i-1;
				break;
			}
		}
	}

	int rec3_w = rec3_end_x - rec3_start_x;
	int rec3_h = rec3_end_y - rec3_start_y;
	int rect3 = rec3_w * rec3_h;

	int total = rect1 - rect2- rect3;
	printf("%d\n",total);

	return 0;
}


