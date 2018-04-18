#include<stdio.h>

int d[100][100];
int fi[100];
bool check[100];

int fibonacci(int n) {

	if (n == 0) {

		d[0][0] = 1;
		d[0][1] = 0;

		return 0;
	} 

	else if (n == 1) {

		d[1][0] = 0;
		d[1][1] = 1;

		return 1;
	}

	else if (check[n] == false)
	{
		check[n] = true;
		fi[n] = fibonacci(n-1) + fibonacci(n-2);
	}

	if(d[n][0] == 0 && d[n][1] == 0)
	{
		for(int i  = n - 2; i < n; i++)
		{
			d[n][0] += d[i][0];
			d[n][1] += d[i][1];
		}
	}

	return fi[n];
}

int main()
{
	int t, count = 1;
	scanf("%d",&t);

	while(count <= t)
	{
		int n;
		scanf("%d", &n);

		fibonacci(n);
		printf("%d %d\n", d[n][0],d[n][1]);
		count ++;
	}
}