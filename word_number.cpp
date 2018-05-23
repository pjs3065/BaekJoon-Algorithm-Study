#include<string>
#include<iostream>

using namespace std;

int main()
{
	string input;
	getline(cin,input,'\n');

	int length =  input.size();
	int ans = 0;

	for(int i = 0; i < length; i++)
	{
		if(input[i] == ' ')
		{
			ans += 1;
		}
	}

	if(input[0] == ' ' && input[length -1] == ' ')
	{
		ans -= 1;
	}
	else if(input[0] != ' ' && input[length -1] != ' ')
	{
		ans += 1;
	}


	printf("%d\n", ans);

	return 0;
}