#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a, &b);

	int temp_a, temp_b;
	temp_a = a;
	temp_b = b;

	int point_front;
    vector<int>point_back;

	int count = 1;

	point_front = a / b;

	while(temp_a % temp_b != 0 && count < 33)
	{
		temp_a = (temp_a % temp_b) * 10; 
		temp_b;
		point_back.push_back(temp_a / temp_b); 
		count++;
	}

	printf("%d",point_front);
	printf(".");

	for(int i = 0; i < point_back.size(); i++)
	{
		printf("%d",point_back[i]);
	}
}