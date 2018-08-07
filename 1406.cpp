#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
	//문자열 입력
	char str[600000];
	scanf("%s",str);

	//스택에 입력
	stack<char> left;
	stack<char> right;

	int len = strlen(str);

	for(int i = 0; i < len; i++)
	{
		left.push(str[i]);
	}

	int n;
	scanf("%d",&n);

	//operation
	while(n--)
	{
		char f;
		scanf(" %c", &f);

		if(f == 'L')
		{
			if(!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}

		else if(f == 'D')
		{
			if(!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}

		else if(f == 'B')
		{
			if(!left.empty())
			{
				left.pop();
			}
		}

		else if(f == 'P')
		{
			char word;
			scanf(" %c", &word);

			left.push(word);
		}
	}

	//출력

	while(!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while(!right.empty())
	{

		printf("%c",right.top());
		right.pop();
	}

	printf("\n");

	return 0;
}