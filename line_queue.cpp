#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

stack<int> s1;
stack<int> s2;

int dequeue()
{
	int s_size = s1.size();

	//다른 스택으로 이동
	for(int i = 0; i < s_size; i++)
	{
		s2.push(s1.top());
		s1.pop();
	}

	//출력할 숫자
	int d = s2.top();
	s2.pop();

	s_size = s2.size();

	//돌려 놓기
	for(int i = 0; i < s_size; i++)
	{
		s1.push(s2.top());
		s2.pop();
	}

	return d;
}

void enqueue(int v)
{
	s1.push(v);
}

int main()
{
	int t, count = 1;
	cin >> t;

	while(count <= t)
	{
		char order[8] = "";
		scanf("%s", order);

		if(strcmp(order,"ENQUEUE") == 0)
		{
			int v;
			scanf("%d", &v);
			enqueue(v);
		}
		
		else if(strcmp(order,"DEQUEUE") == 0)
		{
			int deq_n = dequeue();
			printf("%d\n",deq_n);
		}

		count++;
	}

	return 0;
}
