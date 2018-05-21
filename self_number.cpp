#include<stdio.h>

int main()
{
	int check[10001] = {0,};
	int mo = 0;

	for(int i = 1; i < 10000; i++)
	{
		int sum = i;
		int number = i;

		//자릿수 대로 moduler 할 범위 구하기 ( 1 , 10, 100, 1000, 10000)
		if(mo == 0)
		{
			mo = 1;
		}
		else if(i / (mo * 10) == 1)
		{
			mo = mo * 10;
		}

		//각 자리 수 더해주기
		for(int j = mo; j > 0; j = j / 10)
		{
			int d = number / j;
			number = number % j;
			sum +=  d;
		}

		//생성자라고 체크해주기
		if(sum > 10000)
		{
			continue;
		}
		else
		{
			check[sum] = 1;
		}
	}

	//생성자가 아닌 것들을 출력하기
	for(int i = 1; i < 10000; i++)
	{
		if(check[i] == 0)
		{
			printf("%d\n", i); 
		}
	}
}