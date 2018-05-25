#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{

	int n, count = 1;
	int ans = 0;

	cin >> n;

	while(count <= n)
	{
		string s;
		cin >> s;

		int length = s.length();

		int check[26];
		int clear = 0;

		for(int i = 0; i < 26; i++)
		{
			check[i] = -1;
		}

		for(int i = 0; i < length; i++)
		{
			int prenumber;

			if(i - 1 >= 0)
			{
				prenumber = s[i-1] - 'a';
			}

			int number = s[i] - 'a';

			if(check[number] == -1)
			{
				check[number] = 1;
			}

			else if(prenumber != number)
			{
				check[number] = 2;
				clear = 2;
				break;
			}
		}

		if(clear != 2)
		{
			ans += 1;
		}

		count += 1;
	}

	printf("%d\n",ans);
	return 0;
}