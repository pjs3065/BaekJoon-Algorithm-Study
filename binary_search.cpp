#include<stdio.h>

int number[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};


void find(int first, int last, int f_n)
{
	if(first > last)
	{	
		printf("존재하지 않음\n");
		return;
	}

	int p = (first + last) / 2;
	if(number[p] == f_n) printf("존재함\n");
	else if(number[p] < f_n) find(p + 1, last, f_n);
	else find(first, p - 1, f_n);
}

int main()
{
	int f_n;
	scanf("%d", &f_n);

	find(0,9,f_n);
	return 0;
}