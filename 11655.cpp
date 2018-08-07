#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	getline(cin,str);

	int len = str.length();

	for(int i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'm' || str[i] >= 'A' && str[i] <= 'M')
		{
			printf("%c",str[i] + 13);
		}

		else if(str[i] >= 'n' && str[i] <= 'z' || str[i] >= 'N' && str[i] <= 'Z')
		{
			printf("%c",str[i] - 13);
		}

		else
			printf("%c",str[i]);
	}
	return 0;
}