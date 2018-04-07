#include<iostream>
using namespace std;

int ans = -9999999;

void swap(int *set, int i, int j)
{
	int temp;
	temp = set[i];
	set[i] = set[j];
	set[j] = temp;
}

void sort(int *set, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(set[i] > set[j])
			{
				swap(set,i,j);
			}
		}
	}
}

void print(int *set, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << set[i] << " ";
	}
	cout << "\n";
}

void max(int *set, int n)
{
	int cal = 0;
	int sum = 0;

	for(int i = 0; i < n-1; i++)
	{
		cal = set[i] - set[i+1];
		cal = cal < 0 ? -cal : cal;

		sum = sum + cal;
	}

	ans = ans < sum ? sum : ans;
}

int main()
{
	int n;
	int i,j;

	int *set;

	cin >> n;
	set = (int*)malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++)
	{
		cin >> set[i];
	}

	sort(set, n);


	while(1)
	{
		i = n - 1;
		while(i > 0 && set[i-1] >= set[i]) i--;
		if(i == 0) break;

		j = n - 1;
		while(j >= i && set[i-1] >= set[j]) j--;
		swap(set,i-1,j);

		j = n - 1;
		while(i < j)
		{
			swap(set,i,j);
			i++;
			j--;
		}
		max(set,n);
	}

	cout << ans << '\n';
	return 0;
}
