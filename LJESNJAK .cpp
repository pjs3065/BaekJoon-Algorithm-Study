#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int length = s.length();
	int count = 0;
	int next = 1;
	
	for(int i = 0; i < length; i = i + next)
	{
		if(i + 2 < length)
		{
			if(s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=')
			{
				count++;
				next = 3;
				continue;
			}

		}

		if(i + 1 < length)
		{
			if((s[i] == 'c' || s[i] == 's' || s[i] == 'z') && s[i+1] == '=')
			{
				count++;
				next = 2;
				continue;
			}
			else if((s[i] == 'c' || s[i] == 'd') && s[i+1] == '-')
			{
				count++;
				next = 2;
				continue;
			}
			else if((s[i] == 'l' || s[i] == 'n') && s[i+1] == 'j')
			{
				count++;
				next = 2;
				continue;
			}
		}
			count ++;
			next = 1;
	}

	printf("%d\n", count);
	return 0;
}