#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int>alphabet(26);

	int length = s.length();

	for(int i = 0; i< length; i++)
	{
		int number;
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			 number = s[i]-'a';
		}
		else if(s[i] >= 'A' && s[i] <= 'Z')
		{
			number = s[i] -'A'; 
		}
		alphabet[number]++;
	}

	int max = 0;
	int offset = 0;

	for(int i = 0; i < 26; i++)
	{
		if(alphabet[i] > max)
		{
			max = alphabet[i];
			offset = i;
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(offset == i)
			continue;
		
		if(alphabet[i] == max)
		{
			printf("?\n");
			return 0;
		}
	}

	printf("%c\n", offset + 'A');

	return 0;
}