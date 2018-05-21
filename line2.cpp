#include <iostream>
#include <string>
#include <stdlib.h>

// include <cstdio>
// cin,cout 대신 scanf,printf를 사용하려면 iostream 대신 cstdio 를 사용하세요 .

using namespace std;
int main() {

	string canvas[5];
	string color[3];
	string frames[4];
	string option[5];

	for(int i = 0; i < 5; i++)
	{
		cin >> canvas[i];
	}

	for(int i = 0; i < 5; i++)
	{
		cin >> color[i];
	}

	for(int i = 0; i < 5; i++)
	{
		cin >> frames[i];
	}

	for(int i = 0; i < 5; i++)
	{
		cin >> option[i];
	}

	for(int i = 0; i < 5; i++)
	{
		cin >> canvas[i];
	}


}