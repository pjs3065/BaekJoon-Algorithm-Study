/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> queue(10001);
int front = -1;
int back = -1;

void push(int in)
{
	if(front == -1) front = 0;
	queue[++back] = in;
}

void pop()
{
	if(front == -1) printf("-1\n");

	else if(front == back)
	{
		printf("%d\n",queue[front]);
		front = -1;
		back = -1;
	}
	else
	{
		printf("%d\n",queue[front]);
		front++;
	}
}

void size()
{
	if(front == -1) printf("0\n");
	else printf("%d\n", back - front + 1);
}

void empty()
{
	if(front == -1) printf("1\n");
	else printf("0\n");
}

void print_front()
{
	if(front == -1) printf("-1\n");
	else printf("%d\n",queue[front]);
}

void print_back()
{
	if(back == -1) printf("-1\n");
	else printf("%d\n",queue[back]);
}


int main()
{
	int n, in;
	char s[6];
	scanf("%d",&n);

	while(n--)
	{
		scanf("%s",s);
		if(strcmp(s,"push") == 0)
		{
			scanf("%d",&in);
			push(in);
		}

		else if(strcmp(s,"pop") == 0)
		{
			pop();
		}

		else if(strcmp(s,"empty") == 0)
		{
			empty();
		}

		else if(strcmp(s,"size") == 0)
		{
			size();
		}

		else if(strcmp(s,"front") == 0)
		{
			print_front();
		}

		else if(strcmp(s,"back") == 0)
		{
			print_back();
		}
	}

	return 0;
}