#include<stdio.h>

int main()
{
	int check[10001] = {0,};
	int mo = 0;

	for(int i = 1; i < 10000; i++)
	{
		int sum = i;
		int number = i;

		//�ڸ��� ��� moduler �� ���� ���ϱ� ( 1 , 10, 100, 1000, 10000)
		if(mo == 0)
		{
			mo = 1;
		}
		else if(i / (mo * 10) == 1)
		{
			mo = mo * 10;
		}

		//�� �ڸ� �� �����ֱ�
		for(int j = mo; j > 0; j = j / 10)
		{
			int d = number / j;
			number = number % j;
			sum +=  d;
		}

		//�����ڶ�� üũ���ֱ�
		if(sum > 10000)
		{
			continue;
		}
		else
		{
			check[sum] = 1;
		}
	}

	//�����ڰ� �ƴ� �͵��� ����ϱ�
	for(int i = 1; i < 10000; i++)
	{
		if(check[i] == 0)
		{
			printf("%d\n", i); 
		}
	}
}