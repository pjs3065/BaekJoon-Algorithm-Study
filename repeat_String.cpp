#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	int t, count =1; 
	cin >> t;

	while(count <= t)
	{
		int n;
		cin >> n;

		string s;
		cin >> s;

		int length = s.length();

		for(int i = 0; i < length; i++)
		{

			for(int j = 0; j < n; j++)
			{
				printf("%c",s[i]);
			}
		}
		printf("\n");
		count++;
	}
	return 0;
}