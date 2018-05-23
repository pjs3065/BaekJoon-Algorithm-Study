#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int a, b, c;
	int total;

	scanf("%d %d %d", &a, &b, &c);
	total = a * b * c;

	string total2;
	total2 = to_string(total);

	int length = total2.size();

	vector<int> fre(10);

	for(int i = 0; i < length; i++)
	{
		int number = total2[i] - '0';
		fre[number]++;
	}


	for(int i = 0; i < 10; i++)
	{
		printf("%d\n", fre[i]);
	}

	return 0;
}