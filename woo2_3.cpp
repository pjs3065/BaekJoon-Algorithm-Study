#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	//�Է�
	int x[6];
	int y[6];

	//x�� y�� �Է�
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

	//x�� y�� ���� �� �ִ� ��
	vector<int> x_check (10001);
	vector<int> y_check (10001);

	//1�� �簢���� ����
	int rect1_w = x[1] - x[0];
	int rect1_h = y[1] - y[0];

	int rect1 = rect1_w * rect1_h;

	//1�� �簢�� x���� check �ϱ�

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

	//�簢��2 x�� ���۰� x�� �����ϱ�
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

	//�簢��2 y�� ���۰� y�� �����ϱ�
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

	//�簢�� 3 x������ ���ϱ�

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

	//�簢�� 3 y������ ���ϱ�

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


