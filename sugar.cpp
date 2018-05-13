#include<stdio.h>

int main()
{
	int n, temp;
	int f, t, ans;
	scanf("%d", &n);

	f =  n / 5;
	temp = n % 5;
	t = temp / 3;
	temp = temp % 3;

	if(temp != 0)
	{
		t =  n / 3;
		temp = t % 3;
		f = temp / 5;
		temp = temp % 5;
	}

	if(temp != 0)
	{
		printf("-1\n");
	}

	else
	{
		ans = f + t;
		printf("%d\n",ans);
	}

	return 0;
}