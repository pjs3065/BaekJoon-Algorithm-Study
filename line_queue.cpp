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

	//�ٸ� �������� �̵�
	for(int i = 0; i < s_size; i++)
	{
		s2.push(s1.top());
		s1.pop();
	}

	//����� ����
	int d = s2.top();
	s2.pop();

	s_size = s2.size();

	//���� ����
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
