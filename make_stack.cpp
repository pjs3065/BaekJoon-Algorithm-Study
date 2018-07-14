/*
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

*/

#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> stack(10001);
int top = -1;

void push(int in)
{
	stack[++top] = in;
}

void pop()
{
	if(top == -1) printf("-1\n");
	else
	{
		int value = stack[top--];
		printf("%d\n",value);
	}
}

void empty()
{
	if(top == -1) printf("1\n");
	else printf("0\n");
}

void size()
{
	printf("%d\n", top + 1);
}

void print_top()
{
	if(top == -1) printf("-1\n");
	else printf("%d\n",stack[top]);
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

		else if(strcmp(s,"top") == 0)
		{
			print_top();
		}
	}

	return 0;
}