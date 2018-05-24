#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, count =1;
	cin >> n;

	while(count <= n)
	{
		string quiz;
		cin >> quiz;

		int length = quiz.length();

		int o = 0;
		int sum = 0;


		for(int i = 0; i < length; i++)
		{
			if(quiz[i] == 'O')
			{
				
				o++;
				sum += o;
			}
			else
			{
				o = 0;
			}
		}

		printf("%d\n", sum);
		count++;
	}

	return 0;
}