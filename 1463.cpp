#include<cstdio>

int dp[1000001];

void make_one (int n, int op_c)
{
	if(n < 1)
	{
		return;
	}

	if(n == 1)
	{
		dp[n] = op_c;
		return;
	}

	dp[n] = op_c;

	//3으로 나눠질 경우
	if(n % 3 == 0)
	{
		if(dp[n/3] == 0 || dp[n/3] > op_c + 1)
		{
			make_one(n/3, op_c + 1);
		}
	}

	//2로 나눠질 경우
	if(n % 2 == 0)
	{
		if(dp[n/2] == 0 || dp[n/2] > op_c + 1)
		{
			make_one(n/2, op_c + 1);
		}
	}

	if(dp[n-1] == 0 || dp[n-1] > op_c + 1)
	{
		make_one(n-1, op_c + 1);
	}
}


int main()
{
	int n;
	scanf("%d",&n);

	if(n == 1)
	{
		printf("0\n");
	}
	
	else
	{
		make_one(n,0);
		printf("%d\n",dp[1]);
	}
}