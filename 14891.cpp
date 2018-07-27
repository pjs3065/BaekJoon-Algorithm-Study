#include<stdio.h>
#include<deque>

using namespace std;

int main()
{
	deque<int> de[5];
	for(int i = 1; i < 5; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			int pole;
			scanf("%1d", &pole);
			de[i].push_back(pole);
		}
	}

	int turn;
	scanf("%d", &turn);

	int topni_num;
	int way;
	scanf("%d %d", &topni_num, &way);











	return 0;
}