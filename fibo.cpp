#include<stdio.h>

int d[100][100];
int fi[100];
bool check[100];


int fibonacci(int n) {
	
	if (n == 0) {

		check[n] = true;
		d[n][0] = 1;
		return 0;
	} 
	
	else if (n == 1) {

		check[n] = true;
		d[n][1] = 1;
		return 1;
	} 
	
	else if (check[n] == false)
	{
		check[n] = true;
		fi[n] = fibonacci(n-2) + fibonacci(n-1);
	}
	
	else
	{
		for(int i = 0; i < n; i++)
		{
			d[n][0] += d[i][0];
			d[n][1] += d[i][1];
		}
		return fi[n];
	}
}

int main()
{
	int t, count = 1;
	scanf("%d",&t);

	while(count <= t)
	{
		int n;
		scanf("%d", &n);

		for(int i = 0; i <100; i++)
		{
			check[i] = false;
		}

		fibonacci(n);

		int count_zero = 0;
		int count_one = 0;

		for(int i = 0; i < n; i++)
		{
			count_zero += d[i][0];
			count_one += d[i][1];
		}

		printf("%d %d\n", count_zero, count_one);

		count ++;
	}
}