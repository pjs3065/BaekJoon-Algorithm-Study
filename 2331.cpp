#include<stdio.h>

using namespace std;
int check[1000000];

int pow(int a, int p)
{
	int ans = 1;
	
	for(int i = 0; i < p; i++)
	{
		ans = ans * a;
	}
	return ans;
}

int next(int a, int p)
{
	int ans = 0;

	while(a > 0)
	{
		if(a > 0)
		{
			ans += pow(a % 10, p);
			a = a / 10;
		}
	}

	return ans;
}

int cal(int a, int p, int cnt)
{
	if(check[a] != 0)
	{
		return check[a] - 1;
	}

	check[a] = cnt;
	return cal(next(a,p), p, cnt + 1);
}

int main()
{
	int a, p;
	scanf("%d %d", &a, &p);

	printf("%d\n",cal(a,p,1));
	return 0;
}