#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> arr1(n);
	vector<int> arr2(n);
	vector<int> ans(n);

	for(int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for(int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}

	for (int i = 0; i < n; i++)
	{
		ans[i] = arr1[i] | arr2[i];
	}

	double p = pow(2.0, n);

	//output
	for(int i = 0; i < n; i++)
	{
		for(int j = p; j >= 1; j = j / 2)
		{
			if(ans[i] >= j )
			{
				printf("#");
				ans[i] = ans[i] % j;
			}
			else printf(" ");
		}
		printf("\n");
	}
}