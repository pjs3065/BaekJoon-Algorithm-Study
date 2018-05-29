#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	swap(a[0],a[2]);
	swap(b[0],b[2]);

	int c_a;
	int c_b;

	c_a = stoi(a);
	c_b = stoi(b);

	printf("%d\n", c_a < c_b ? c_b : c_a);
	return 0;
}