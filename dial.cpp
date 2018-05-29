#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string dial;
	cin >> dial;

	int length = dial.length();
	int timer = 0;

	for(int i = 0; i < length; i++)
	{
		switch (dial[i])
		{
		case 'A':
		case 'B':
		case 'C': timer+= 3; break;
		case 'D':
		case 'E':
		case 'F': timer+= 4; break;
		case 'G':
		case 'H':
		case 'I': timer+= 5; break;
		case 'J':
		case 'K':
		case 'L': timer+= 6; break;
		case 'M':
		case 'N':
		case 'O': timer+= 7; break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S': timer+= 8; break;
		case 'T':
		case 'U':
		case 'V': timer+= 9; break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z': timer+= 10; break;
		}
	}

	printf("%d\n", timer);
	return 0;
}