#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	string c;
	cin >> c;

	int alphabet[26];

	for(int i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}

	int length = c.length();

	for(int i = 0; i< length; i++)
	{
		int index = c[i] -'a';
		if(alphabet[index] == -1)
		{
			alphabet[index] = i;
		}
	}

	for(int i = 0; i< 26; i++)
	{
		cout << alphabet[i] << ' ';
	}

	cout << '\n';
	return 0;
}