/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

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