/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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